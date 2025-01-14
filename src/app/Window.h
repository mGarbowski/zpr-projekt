/**
 * @ingroup visualisation
 * @brief Wrapper for SFML window.
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#ifndef WINDOW_H
#define WINDOW_H
#define IMGUI_DEFINE_MATH_OPERATORS
#include <SFML/Graphics.hpp>
#include <imgui-SFML.h>
#include <imgui.h>
#include <iostream>

#include "ControlPanel.h"
#include "EvolutionManager.h"
#include "VisualisationUtils.h"

class Window {
 public:
  static Window create( const unsigned int width, const unsigned int height, const float scale ) {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    return Window( width, height, scale, settings );
  }

  ~Window() {
    ImGui::SFML::Shutdown();
  }

  bool isOpen() const {
    return window_.isOpen();
  }

  void onStartOfFrame() {
    processEvents();

    const auto delta_time = clock_.restart();
    window_.clear();
    ImGui::SFML::Update( window_, delta_time );
  }

  void onEndOfFrame() {
    ImGui::SFML::Render( window_ );
    window_.display();
  }

  void drawSimulation( const EvolutionManager& evolution_manager,
                       const ControlPanel& control_panel ) {
    if( !control_panel.isDisplayEnabled() ) {
      return;
    }

    const auto camera_transform = box2dToSFML(
        width_, height_, scale_, evolution_manager.simulationsManager().getBestCarPosition() );

    for( const auto& sim : evolution_manager.simulationsManager().simulations() ) {
      drawCarSimulation( window_, sim, camera_transform, control_panel.getCarColor() );
    }

    const auto ground = evolution_manager.simulationsManager().getRoadModel();
    drawRoad( window_, ground, camera_transform, control_panel.getRoadColor() );
  }

 private:
  Window( unsigned int width, unsigned int height, float scale, sf::ContextSettings settings )
      : width_( width ),
        height_( height ),
        scale_( scale ),
        window_( sf::RenderWindow{
            { width_, height_ }, "Box2D with ImGui and SFML", sf::Style::Default, settings } ) {
    if( !ImGui::SFML::Init( window_ ) ) {
      std::cerr << "Failed to initialize ImGui with SFML." << std::endl;
      window_.close();
    }

    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
  }

  void processEvents() {
    for( auto event = sf::Event{}; window_.pollEvent( event ); ) {
      ImGui::SFML::ProcessEvent( window_, event );
      if( event.type == sf::Event::Closed ) {
        window_.close();
      }
    }
  }

  unsigned int width_;
  unsigned int height_;
  float scale_;
  sf::RenderWindow window_;
  sf::Clock clock_;
};

#endif  // WINDOW_H
