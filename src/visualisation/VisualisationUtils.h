//
// Created by mgarbowski on 12/3/24.
//

#ifndef VISUALISATIONUTILS_H
#define VISUALISATIONUTILS_H

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>

#include "CarChassis.h"
#include "CircleRot.h"
#include "Position.h"
#include "RoadModel.h"
#include "Size.h"

/**
 * @ingroup visualisation
 * @brief Create a matrix for transforming box2d simulation coordinates to SFML window coordinates
 * @param window_width Width of the SFML window
 * @param window_height Height of the SFML window
 * @param scale Scale factor for the transformation
 * @return SFML Transform matrix
 */
sf::Transform box2dToSFML(int window_width, int window_height, float scale = 30.0f);

/**
 * @ingroup visualisation
 * @brief Convert size to SFML vector
 * @param size Size
 * @return SFML vector
 */
sf::Vector2f asVector(const Size& size);

/**
 * @ingroup visualisation
 * @brief Convert position to SFML vector
 * @param position Position
 * @return SFML vector
 */
sf::Vector2f asVector(const Position& position);

/**
 * @ingroup visualisation
 * @brief Create SFML circle shape
 * @param circle circle description
 * @param outline_color outline color
 * @param fill_color fill color
 * @return SFML circle shape
 */
sf::CircleShape createCircle(const CircleRot& circle, sf::Color outline_color,
                             sf::Color fill_color);

/**
 * @ingroup visualisation
 * @brief Create SFML line between 2 points
 * @param start start point in relative coordinates
 * @param end end point in relative coordinates
 * @param position offset for the points
 * @param color color
 * @return SFML vertex array
 */
sf::VertexArray createLine(const b2Vec2& start, const b2Vec2& end, Position position,
                           sf::Color color = sf::Color::White);

/**
 * @ingroup visualisation
 * @brief Create SFML triangle shape
 * @param triangle box2d polygon describing a triagle
 * @param position offset for the vertices
 * @param color fill color
 * @return SFML convex shape
 */
sf::ConvexShape createTriangle(const b2Polygon& triangle, Position position,
                               sf::Color color = sf::Color::White);

/**
 * @ingroup visualisation
 * @brief Draw car chassis on the SFML window
 * @param window SFML window
 * @param car_chassis car chassis
 * @param transform transformation matrix
 * @param color chassis fill color
 */
void drawCarChassis(sf::RenderWindow& window, const CarChassis& car_chassis,
                    const sf::Transform& transform, sf::Color color = sf::Color::White);

/**
 * @ingroup visualisation
 * @brief Draw road on the SFML window
 * @param window SFML window
 * @param road_model model of the road
 * @param transform transformation matrix
 * @param color color
 */
void drawRoad(sf::RenderWindow& window, const RoadModel& road_model, const sf::Transform& transform,
              sf::Color color = sf::Color::White);
#endif  // VISUALISATIONUTILS_H
