/**
 * @ingroup app
 * @brief Main file for the application.
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#define IMGUI_DEFINE_MATH_OPERATORS
#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include <imgui-SFML.h>
#include <imgui.h>
#include <iostream>

#include "CarSimulation.h"
#include "ControlPanel.h"
#include "DebugInfoPanel.h"
#include "GuiControls.h"
#include "SimulationsManager.h"
#include "StaticRoadGenerator.h"
#include "VisualisationUtils.h"

constexpr int WINDOW_WIDTH = 800;
constexpr int WINDOW_HEIGHT = 800;
constexpr float SCALE = 20.0f;

int main() {
  sf::Clock clock;
  sf::ContextSettings settings;
  settings.antialiasingLevel = 8;

  auto window = sf::RenderWindow{
      {WINDOW_WIDTH, WINDOW_HEIGHT}, "Box2D with ImGui and SFML", sf::Style::Default, settings};
  if (!ImGui::SFML::Init(window)) {
    std::cerr << "Failed to initialize ImGui with SFML." << std::endl;
    window.close();
    return EXIT_FAILURE;
  }

  ImGuiIO& io = ImGui::GetIO();
  io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
  io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
  io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

  CarDescription car_description_1 = {{-4, 2}, {0, 1.5}, {4, 2}, {2, 0}, {4, -2}, {0, -1}, {-4, -2},
                                    {-2, 0}, 1.0f,     1.0f,   1.0f,   1.0f,    0.5f};
  CarDescription car_description_2 = {{-3, 2}, {0, 1.5}, {3, 2}, {2, 0}, {4, -2}, {0, -1}, {-4, -2},
                                    {-2, 0}, 1.0f,     1.0f,   1.0f,   1.0f,    0.5f};
  CarDescription car_description_3 = {{-3, 2}, {0, 1.5}, {3, 2}, {2, 0}, {3, -2}, {0, -1}, {-3, -2},
                                    {-2, 0}, 1.0f,     1.0f,   1.0f,   1.0f,    0.5f};
  URoadGenerator road_generator = std::make_unique<StaticRoadGenerator>();
  auto road = road_generator->generateRoad();
  auto sim_1 = CarSimulation::create(car_description_1, road);
  auto sim_2 = CarSimulation::create(car_description_2, road);
  auto sim_3 = CarSimulation::create(car_description_3, road);
  SimulationsManager simulations_manager{std::vector{sim_1, sim_2, sim_3}};

  ControlPanel control_panel{};
  DebugInfoPanel debug_info_panel{};

  while (window.isOpen()) {
    ///// Events
    for (auto event = sf::Event{}; window.pollEvent(event);) {
      ImGui::SFML::ProcessEvent(window, event);
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    ///// Setup
    auto delta_time = clock.restart();
    window.clear();
    ImGui::SFML::Update(window, delta_time);

    ///// Draw UI and simulation
    control_panel.render();
    if (control_panel.getRunning()) {
      simulations_manager.update();
    }

    debug_info_panel.setCarPosition(
        {sim_1.getCarChassis().getPosition().x_, sim_1.getCarChassis().getPosition().y_});
    debug_info_panel.setMutationRate(control_panel.getMutationRate());
    debug_info_panel.setBestCarPosition( simulations_manager.getBestCarPosition().asPair() );
    debug_info_panel.render();

    // update camera
    const auto camera_transform = box2dToSFML(WINDOW_WIDTH, WINDOW_HEIGHT, SCALE, simulations_manager.getBestCarPosition());

    for (const auto& sim : simulations_manager.simulations()) {
      drawCarSimulation( window, sim, camera_transform, control_panel.getCarColor() );
    }

    auto ground = simulations_manager.getRoadModel();
    drawRoad( window, ground, camera_transform, control_panel.getRoadColor() );

    ///// Finish
    ImGui::SFML::Render(window);
    window.display();
    sleep(sf::milliseconds(3));
  }

  ImGui::SFML::Shutdown();
}