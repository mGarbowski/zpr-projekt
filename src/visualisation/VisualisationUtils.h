//
// Created by mgarbowski on 12/3/24.
//

#ifndef VISUALISATIONUTILS_H
#define VISUALISATIONUTILS_H

#include <SFML/Graphics.hpp>

/**
 * @ingroup visualisation
 *
 * Create a matrix for transforming box2d simulation coordinates to SFML window coordinates
 * @param window_width Width of the SFML window
 * @param window_height Height of the SFML window
 * @return Transform matrix
 */
sf::Transform box2dToSFML(int window_width, int window_height);



#endif //VISUALISATIONUTILS_H
