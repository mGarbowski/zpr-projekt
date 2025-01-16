/**
 * @ingroup app
 * @brief Wrapper for SFML window.
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#ifndef WINDOW_H
#define WINDOW_H
#define IMGUI_DEFINE_MATH_OPERATORS
#include <SFML/Graphics.hpp>

#include "ControlPanel.h"
#include "EvolutionManager.h"

class Window {
 public:
  static Window create( unsigned int width, unsigned int height, float scale );

  ~Window();

  bool isOpen() const;

  void onStartOfFrame();

  void onEndOfFrame();

  void drawSimulation( const EvolutionManager& evolution_manager,
                       const ControlPanel& control_panel );

 private:
  Window( unsigned int width, unsigned int height, float scale, const sf::ContextSettings& settings,
          const sf::Transform& camera_transform, sf::Color car_color );

  void drawCar( const CarSimulation& simulation );
  void drawCarChassis( const CarChassis& car_chassis );
  void drawBestCar( const EvolutionManager& evolution_manager, const ControlPanel& control_panel );
  void drawCarFromDescription( const CarDescription& description, Position position,
                               sf::Transform transform );
  void drawRoad( const RoadModel& road_model, sf::Color color );
  void processEvents();

  unsigned int width_;
  unsigned int height_;
  float scale_;
  sf::RenderWindow window_;
  sf::Clock clock_;
  sf::Transform camera_transform_;
  sf::Color car_color_;
};

#endif  // WINDOW_H
