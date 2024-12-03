#define IMGUI_DEFINE_MATH_OPERATORS
#include <SFML/Graphics.hpp>
#include <VisualisationUtils.h>
#include <box2d/box2d.h>
#include <imgui-SFML.h>
#include <imgui.h>
#include <iostream>

#include "../road/StaticRoadGenerator.h"
#include "CarSimulation.h"
#include "ControlPanel.h"
#include "DebugInfoPanel.h"
#include "GuiControls.h"

constexpr int WINDOW_WIDTH = 800;
constexpr int WINDOW_HEIGHT = 800;

void drawCarSimulation(sf::RenderWindow& window, const CarSimulation& simulation,
                       sf::Transform transform, sf::Color ground_color = sf::Color::White,
                       sf::Color car_color = sf::Color::White) {
  const auto rear_wheel =
      createCircle(simulation.getRearWheelCircle(), car_color, car_color);
  const auto front_wheel =
      createCircle(simulation.getFrontWheelCircle(), car_color, car_color);

  auto car_chassis = simulation.getCarChassis();
  auto body_pos = car_chassis.getPosition();
  for (int i = 0; i < 8; ++i) {
    const auto triangle = car_chassis.getTriangle(i);
    const auto shape = createTriangle(triangle, body_pos, car_color);

    window.draw(shape, transform);
  }
  RoadModel ground = simulation.getRoadModel();
  auto ground_lines = ground.getSegments();
  Position ground_pos = ground.getPosition();
  for (const auto& line : ground_lines) {
    const auto shape = createLine(line.point1, line.point2, ground_pos, ground_color);
    window.draw(shape, transform);
  }
  window.draw(rear_wheel, transform);
  window.draw(front_wheel, transform);
}

int main() {
  sf::Clock clock;
  sf::ContextSettings settings;
  settings.antialiasingLevel = 8;
  const auto transform = box2dToSFML(WINDOW_WIDTH, WINDOW_HEIGHT);

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

  CarDescription car_description = {{-4, 2}, {0, 1.5}, {4, 2}, {2, 0}, {4, -2}, {0, -1}, {-4, -2},
                                    {-2, 0}, 1.0f,     1.0f,   1.0f,   1.0f,    0.5f};
  URoadGenerator road_generator = std::make_unique<StaticRoadGenerator>();
  auto sim = CarSimulation::create(car_description, road_generator->generateRoad());

  ControlPanel control_panel{};
  DebugInfoPanel debug_info_panel{};

  while (window.isOpen()) {
    // Events
    for (auto event = sf::Event{}; window.pollEvent(event);) {
      ImGui::SFML::ProcessEvent(window, event);
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    // Setup
    auto delta_time = clock.restart();
    window.clear();
    ImGui::SFML::Update(window, delta_time);

    // Draw UI and simulation
    control_panel.render();
    if (control_panel.getRunning()) {
      sim.step();
    }

    debug_info_panel.setCarPosition(
        {sim.getCarChassis().getPosition().x, sim.getCarChassis().getPosition().y});
    debug_info_panel.setMutationRate(control_panel.getMutationRate());
    debug_info_panel.render();

    drawCarSimulation(window, sim, transform, control_panel.getRoadColor(),
                      control_panel.getCarColor());

    // Finish
    ImGui::SFML::Render(window);
    window.display();
    sleep(sf::milliseconds(3));
  }

  ImGui::SFML::Shutdown();
}