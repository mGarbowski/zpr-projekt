//
// Created by mgarbowski on 12/3/24.
//

#include "VisualisationUtils.h"

sf::Transform box2dToSFML(const int window_width, const int window_height) {
  sf::Transform transform;
  transform.translate(window_width / 2, window_height / 2);
  transform.scale(30.0f, -30.0f);
  return transform;
}