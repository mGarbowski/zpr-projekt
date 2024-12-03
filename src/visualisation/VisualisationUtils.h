//
// Created by mgarbowski on 12/3/24.
//

#ifndef VISUALISATIONUTILS_H
#define VISUALISATIONUTILS_H

#include <SFML/Graphics.hpp>

#include "Position.h"
#include "Size.h"

/**
 * @ingroup visualisation
 *
 * Create a matrix for transforming box2d simulation coordinates to SFML window coordinates
 * @param window_width Width of the SFML window
 * @param window_height Height of the SFML window
 * @param scale Scale factor for the transformation
 * @return Transform matrix
 */
sf::Transform box2dToSFML(int window_width, int window_height, float scale = 30.0f);

/**
 * @ingroup visualisation
 *
 * Convert size to SFML vector
 *
 * @param size Size
 * @return SFML vector
 */
sf::Vector2f asVector(const Size& size);

/**
 * @ingroup visualisation
 *
 * Convert position to SFML vector
 *
 * @param position Position
 * @return SFML vector
 */
sf::Vector2f asVector(const Position& position);

#endif //VISUALISATIONUTILS_H
