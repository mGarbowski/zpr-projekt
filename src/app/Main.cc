/**
 * @ingroup app
 * @brief Main file for the application.
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#define IMGUI_DEFINE_MATH_OPERATORS
#include <SFML/Graphics.hpp>
#include <imgui-SFML.h>
#include <optional>

#include "ConfigurationPanel.h"
#include "ControlPanel.h"
#include "DebugInfoPanel.h"
#include "EvolutionManager.h"
#include "EvolutionManagerFactory.h"
#include "Window.h"

constexpr int WINDOW_WIDTH = 800;
constexpr int WINDOW_HEIGHT = 800;
constexpr float SCALE = 20.0f;

int main() {
  auto window = Window::create( WINDOW_WIDTH, WINDOW_HEIGHT, SCALE );

  ControlPanel control_panel{};
  DebugInfoPanel debug_info_panel{};
  ConfigurationPanel configuration_panel{};

  std::optional<EvolutionManager> evolution_manager;

  while( window.isOpen() ) {
    window.onStartOfFrame();

    if( evolution_manager ) {
      control_panel.render();
      if( control_panel.getRunning() ) {
        evolution_manager->update();
      }

      debug_info_panel.update( *evolution_manager );
      debug_info_panel.render();

      window.drawSimulation( *evolution_manager, control_panel );
    } else {
      configuration_panel.render();
      if( configuration_panel.shouldStartEvolution() ) {
        evolution_manager = EvolutionManagerFactory::create(
            configuration_panel, std::mt19937{ std::random_device{}() } );
      }
    }

    window.onEndOfFrame();
    sleep( sf::microseconds( control_panel.getDelayMicroseconds() ) );
  }
}