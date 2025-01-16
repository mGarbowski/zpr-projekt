/**
 * @ingroup app
 * @brief Wrapper for SFML window.
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#include "Window.h"

#include <imgui-SFML.h>
#include <imgui.h>
#include <iostream>

#include "VisualisationUtils.h"

Window Window::create( const unsigned int width, const unsigned int height, const float scale ) {
  sf::ContextSettings settings;
  settings.antialiasingLevel = 8;
  const auto transform = box2dToSFML( width, height, scale );
  return Window( width, height, scale, settings, transform, sf::Color::White );
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
  camera_transform_ = box2dToSFML( width_, height_, scale_,
                                   evolution_manager.simulationsManager().getBestCarPosition() );
  car_color_ = control_panel.getCarColor();

  for( const auto& sim : evolution_manager.simulationsManager().simulations() ) {
    drawCar( sim );
  }

  const auto ground = evolution_manager.simulationsManager().getRoadModel();
  drawRoad( window_, ground, camera_transform_, control_panel.getRoadColor() );
  drawBestCar( evolution_manager, control_panel );
}

sf::Transform Window::box2dToSFML( int window_width, int window_height, float scale,
                                   Position tracked_position ) {
  sf::Transform transform;
  transform.translate( window_width / 2, window_height / 2 );
  transform.scale( scale, -scale );
  transform.translate( -tracked_position.x_, -tracked_position.y_ );
  return transform;
}

Window::Window( const unsigned int width, const unsigned int height, const float scale,
                const sf::ContextSettings& settings, const sf::Transform& camera_transform,
                const sf::Color car_color )
    : width_( width ),
      height_( height ),
      scale_( scale ),
      window_( sf::RenderWindow{
          { width_, height_ }, "Box2D with ImGui and SFML", sf::Style::Default, settings } ),
      camera_transform_( camera_transform ),
      car_color_( car_color ) {
  if( !ImGui::SFML::Init( window_ ) ) {
    std::cerr << "Failed to initialize ImGui with SFML." << std::endl;
    window_.close();
  }

  ImGuiIO& io = ImGui::GetIO();
  io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
  io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
  io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
}

void Window::drawCar( const CarSimulation& simulation ) {
  const auto rear_wheel = createCircle( simulation.getRearWheelCircle(), car_color_, car_color_ );
  const auto front_wheel = createCircle( simulation.getFrontWheelCircle(), car_color_, car_color_ );
  auto car_chassis = simulation.getCarChassis();

  drawCarChassis( car_chassis );
  window_.draw( rear_wheel, camera_transform_ );
  window_.draw( front_wheel, camera_transform_ );
}

void Window::drawCarChassis( const CarChassis& car_chassis ) {
  const auto position = car_chassis.getPosition();
  for( int i = 0; i < 8; ++i ) {
    const auto triangle = car_chassis.getTriangleRot( i );
    auto shape = createTriangle( triangle, position, car_color_ );
    window_.draw( shape, camera_transform_ );
  }
}

void Window::drawBestCar( const EvolutionManager& evolution_manager,
                          const ControlPanel& control_panel ) {
  if( !evolution_manager.bestCar().has_value() ) {
    return;
  }

  // Fixed position on the screen
  const auto transform = box2dToSFML( width_, height_, scale_ );
  const Position top_left_corner = { -15, 15 };
  const auto best_car_description = evolution_manager.bestCar()->description_;
  drawCarFromDescription( best_car_description, top_left_corner, transform );
}

void Window::drawCarFromDescription( const CarDescription& description, const Position position,
                                     sf::Transform transform ) {
  sf::CircleShape rear_wheel = createCircle(
      CircleRot{ position + description.bottomLeft(), description.rearWheelRadius(), 0 },
      car_color_, car_color_ );
  sf::CircleShape front_wheel = createCircle(
      CircleRot{ position + description.bottomRight(), description.frontWheelRadius(), 0 },
      car_color_, car_color_ );
  window_.draw( rear_wheel, transform );
  window_.draw( front_wheel, transform );

  // Chassis triangles
  std::initializer_list<std::pair<Position, Position>> vertices = {
      { description.left(), description.topLeft() },
      { description.topLeft(), description.top() },
      { description.top(), description.topRight() },
      { description.topRight(), description.right() },
      { description.right(), description.bottomRight() },
      { description.bottomRight(), description.bottom() },
      { description.bottom(), description.bottomLeft() },
      { description.bottomLeft(), description.left() } };

  for( auto [b, c] : vertices ) {
    auto triangle =
        createTriangle( TriangleRot{ Position{ 0, 0 }, b, c, 0 }, position, car_color_ );
    window_.draw( triangle, transform );
  }
}

void Window::processEvents() {
  for( auto event = sf::Event{}; window_.pollEvent( event ); ) {
    ImGui::SFML::ProcessEvent( window_, event );
    if( event.type == sf::Event::Closed ) {
      window_.close();
    }
  }
}