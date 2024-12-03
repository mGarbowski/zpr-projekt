//
// Created by mgarbowski on 12/3/24.
//

#include "VisualisationUtils.h"

sf::Transform box2dToSFML(const int window_width, const int window_height, const float scale) {
  sf::Transform transform;
  transform.translate(window_width / 2, window_height / 2);
  transform.scale(scale, -scale);
  return transform;
}

sf::Vector2f asVector(const Size& size) {
  return sf::Vector2f(size.width, size.height);
}

sf::Vector2f asVector(const Position& position) {
  return sf::Vector2f(position.x, position.y);
}

sf::CircleShape createSfCircle(const CircleRot& circle, const sf::Color outiline_color,
                               const sf::Color fill_color) {
  const Position& position = circle.pos();
  const float radius = circle.radius();
  sf::CircleShape sf_circle;
  sf_circle.setOrigin(radius, radius);
  sf_circle.setRadius(radius);
  sf_circle.setOutlineColor(outiline_color);
  sf_circle.setPosition(asVector(position));
  sf_circle.setFillColor(fill_color);

  return sf_circle;
}

sf::VertexArray createLine(const b2Vec2& start, const b2Vec2& end, Position position,
                           sf::Color color) {
  sf::VertexArray line(sf::Lines, 2);

  line[0].position = sf::Vector2f(start.x + position.x, start.y + position.y);
  line[0].color = color;
  line[1].position = sf::Vector2f(end.x + position.x, end.y + position.y);
  line[1].color = color;

  return line;
}

sf::ConvexShape createTriangle(const b2Polygon& triangle, const Position position,
                               const sf::Color color) {
  sf::ConvexShape shape(3);
  for (int i = 0; i < 3; ++i) {
    shape.setPoint(
        i, sf::Vector2f(triangle.vertices[i].x + position.x, triangle.vertices[i].y + position.y));
  }
  shape.setFillColor(color);
  return shape;
}