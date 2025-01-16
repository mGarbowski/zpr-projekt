/**
 * @ingroup visualisation
 * @brief Wrapper for SFML window.
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#include "Window.h"

#include <imgui-SFML.h>
#include <imgui.h>
#include <iostream>

#include "StaticRoadGenerator.h"
#include "VisualisationUtils.h"

Window Window::create( const unsigned int width, const unsigned int height, const float scale ) {
  sf::ContextSettings settings;
  settings.antialiasingLevel = 8;
  return Window( width, height, scale, settings );
}

Window::~Window() {
  ImGui::SFML::Shutdown();
}

bool Window::isOpen() const {
  return window_.isOpen();
}

void Window::onStartOfFrame() {
  processEvents();

  const auto delta_time = clock_.restart();
  window_.clear();
  ImGui::SFML::Update( window_, delta_time );
}

void Window::onEndOfFrame() {
  ImGui::SFML::Render( window_ );
  window_.display();
}

void Window::drawSimulation( const EvolutionManager& evolution_manager,
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
  drawBestCar( evolution_manager, control_panel );
}

Window::Window( unsigned int width, unsigned int height, float scale, sf::ContextSettings settings )
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
void Window::drawBestCar( const EvolutionManager& evolution_manager,
                          const ControlPanel& control_panel ) {
  if( !evolution_manager.bestCar().has_value() ) {
    return;
  }

  // Fixed position on the screen
  const auto transform = box2dToSFML( width_, height_, scale_, Position( 0, 0 ) );
  const sf::Vector2f top_left_corner = { -15, 15 };

  drawCarDescription( window_, evolution_manager.bestCar()->description_, transform,
                      control_panel.getCarColor(), top_left_corner );
}

void Window::processEvents() {
  for( auto event = sf::Event{}; window_.pollEvent( event ); ) {
    ImGui::SFML::ProcessEvent( window_, event );
    if( event.type == sf::Event::Closed ) {
      window_.close();
    }
  }
}