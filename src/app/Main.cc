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
#include <optional>

#include "CarSimulation.h"
#include "ConfigurationPanel.h"
#include "ControlPanel.h"
#include "DebugInfoPanel.h"
#include "EvolutionManager.h"
#include "PerlinRoadGenerator.h"
#include "SimulationsManager.h"
#include "VisualisationUtils.h"

constexpr int WINDOW_WIDTH = 800;
constexpr int WINDOW_HEIGHT = 800;
constexpr float SCALE = 20.0f;

int main() {
  sf::Clock clock;
  sf::ContextSettings settings;
  settings.antialiasingLevel = 8;

  auto window = sf::RenderWindow{
      { WINDOW_WIDTH, WINDOW_HEIGHT }, "Box2D with ImGui and SFML", sf::Style::Default, settings };
  if( !ImGui::SFML::Init( window ) ) {
    std::cerr << "Failed to initialize ImGui with SFML." << std::endl;
    window.close();
    return EXIT_FAILURE;
  }

  ImGuiIO& io = ImGui::GetIO();
  io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
  io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
  io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

  ControlPanel control_panel{};
  DebugInfoPanel debug_info_panel{};
  ConfigurationPanel configuration_panel{};

  std::optional<EvolutionManager> evolution_manager;

  while( window.isOpen() ) {
    ///// Events
    for( auto event = sf::Event{}; window.pollEvent( event ); ) {
      ImGui::SFML::ProcessEvent( window, event );
      if( event.type == sf::Event::Closed ) {
        window.close();
      }
    }

    ///// Setup
    auto delta_time = clock.restart();
    window.clear();
    ImGui::SFML::Update( window, delta_time );

    ///// Draw UI and simulation

    if( evolution_manager ) {
      control_panel.render();
      if( control_panel.getRunning() ) {
        evolution_manager->update();
      }

      debug_info_panel.update( *evolution_manager );
      debug_info_panel.render();

      // update camera
      const auto camera_transform =
          box2dToSFML( WINDOW_WIDTH, WINDOW_HEIGHT, SCALE,
                       evolution_manager->simulationsManager().getBestCarPosition() );

      if( control_panel.isDisplayEnabled() ) {
        for( const auto& sim : evolution_manager->simulationsManager().simulations() ) {
          drawCarSimulation( window, sim, camera_transform, control_panel.getCarColor() );
        }

        auto ground = evolution_manager->simulationsManager().getRoadModel();
        drawRoad( window, ground, camera_transform, control_panel.getRoadColor() );
      }
    } else {
      configuration_panel.render();
      if( configuration_panel.shouldStartEvolution() ) {
        evolution_manager = EvolutionManager::create(
            configuration_panel.populationSize(), std::mt19937{ std::random_device{}() },
            configuration_panel.mutationVariant(), configuration_panel.mutationParams() );
      }
    }

    ///// Finish
    ImGui::SFML::Render( window );
    window.display();
    // sleep( sf::milliseconds( 3 ) );
  }

  ImGui::SFML::Shutdown();
}