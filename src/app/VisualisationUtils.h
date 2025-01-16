/**
 * Utility functions for visualising the simulation
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#ifndef VISUALISATIONUTILS_H
#define VISUALISATIONUTILS_H

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>

#include "CarChassis.h"
#include "CircleRot.h"
#include "Position.h"

/**
 * @ingroup app
 * @brief Create a matrix for transforming box2d simulation coordinates to SFML window coordinates
 * @param window_width Width of the SFML window
 * @param window_height Height of the SFML window
 * @param scale Scale factor for the transformation
 * @param tracked_position Position to track in box2d coordinates (the best car position)
 * @return SFML Transform matrix
 */
sf::Transform box2dToSFML( int window_width, int window_height, float scale,
                           Position tracked_position = { 0, 0 } );

/**
 * @ingroup app
 * @brief Convert position to SFML vector
 * @param position Position
 * @return SFML vector
 */
sf::Vector2f asVector( const Position& position );

/**
 * @ingroup app
 * @brief Create SFML circle shape
 * @param circle circle description
 * @param outline_color outline color
 * @param fill_color fill color
 * @return SFML circle shape
 */
sf::CircleShape createCircle( const CircleRot& circle, sf::Color outline_color,
                              sf::Color fill_color );

/**
 * @ingroup app
 * @brief Create SFML line between 2 points
 * @param start start point in relative coordinates
 * @param end end point in relative coordinates
 * @param position offset for the points
 * @param color color
 * @return SFML vertex array
 */
sf::VertexArray createLine( const b2Vec2& start, const b2Vec2& end, Position position,
                            sf::Color color = sf::Color::White );

/**
 * @ingroup app
 * @brief Create SFML triangle shape
 * @param triangle triangle vertices and rotation
 * @param position position of the chassis
 * @param color fill color
 * @return SFML convex shape
 */
sf::ConvexShape createTriangle( const TriangleRot& triangle, Position position,
                                sf::Color color = sf::Color::White );

#endif  // VISUALISATIONUTILS_H
