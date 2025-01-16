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
  /**
   * @brief Create a matrix for transforming box2d simulation coordinates to SFML window coordinates
   * @param window_width Width of the SFML window
   * @param window_height Height of the SFML window
   * @param scale Scale factor for the transformation
   * @param tracked_position Position to track in box2d coordinates (the best car position)
   * @return SFML Transform matrix
   */
  static sf::Transform box2dToSFML( int window_width, int window_height, float scale,
                                    Position tracked_position = { 0, 0 } );

  Window( unsigned int width, unsigned int height, float scale, const sf::ContextSettings& settings,
          const sf::Transform& camera_transform, sf::Color car_color );

  void drawCar( const CarSimulation& simulation );
  void drawCarChassis( const CarChassis& car_chassis );
  void drawBestCar( const EvolutionManager& evolution_manager, const ControlPanel& control_panel );
  void drawCarFromDescription( const CarDescription& description, Position position,
                               sf::Transform transform );
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
