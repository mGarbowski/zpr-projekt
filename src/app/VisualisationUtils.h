/**
 * Utility functions for visualising the simulation
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#ifndef VISUALISATIONUTILS_H
#define VISUALISATIONUTILS_H

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>

#include "CarChassis.h"
#include "CarSimulation.h"
#include "CircleRot.h"
#include "Position.h"
#include "RoadModel.h"

// TODO better file structure, do not pass window and transform everywhere

/**
 * @ingroup visualisation
 * @brief Convert position to SFML vector
 * @param position Position
 * @return SFML vector
 */
sf::Vector2f asVector( const Position& position );

/**
 * @ingroup visualisation
 * @brief Create SFML circle shape
 * @param circle circle description
 * @param outline_color outline color
 * @param fill_color fill color
 * @return SFML circle shape
 */
sf::CircleShape createCircle( const CircleRot& circle, sf::Color outline_color,
                              sf::Color fill_color );

/**
 * @ingroup visualisation
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
 * @ingroup visualisation
 * @brief Create SFML triangle shape
 * @param triangle triangle vertices and rotation
 * @param position position of the chassis
 * @param color fill color
 * @return SFML convex shape
 */
sf::ConvexShape createTriangle( const TriangleRot& triangle, Position position,
                                sf::Color color = sf::Color::White );

/**
 * @ingroup visualisation
 * @brief Draw road on the SFML window
 * @param window SFML window
 * @param road_model model of the road
 * @param transform transformation matrix
 * @param color color
 */
void drawRoad( sf::RenderWindow& window, const RoadModel& road_model,
               const sf::Transform& transform, sf::Color color = sf::Color::White );

#endif  // VISUALISATIONUTILS_H
