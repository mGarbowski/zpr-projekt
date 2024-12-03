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

sf::CircleShape createCircle(const CircleRot& circle, const sf::Color outline_color,
                             const sf::Color fill_color) {
  const Position& position = circle.pos();
  const float radius = circle.radius();
  sf::CircleShape sf_circle;
  sf_circle.setOrigin(radius, radius);
  sf_circle.setRadius(radius);
  sf_circle.setOutlineColor(outline_color);
  sf_circle.setOutlineThickness(0.05f);
  sf_circle.setPosition(asVector(position));
  sf_circle.setFillColor(fill_color);

  return sf_circle;
}

sf::VertexArray createLine(const b2Vec2& start, const b2Vec2& end, const Position position,
                           const sf::Color color) {
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

std::vector<sf::VertexArray> createPolygonalChain(const RoadModel& road_model,
                                                  const sf::Color color) {
  auto road_segments = road_model.getSegments();
  const auto offset = road_model.getPosition();
  std::vector<sf::VertexArray> lines(road_segments.size());

  std::transform(road_segments.begin(), road_segments.end(), lines.begin(),
                 [&offset, &color](const auto& segment) {
                   return createLine(segment.point1, segment.point2, offset, color);
                 });
  return lines;
}

void drawCarChassis(sf::RenderWindow& window, const CarChassis& car_chassis,
                    const sf::Transform& transform, const sf::Color color) {
  const auto position = car_chassis.getPosition();
  for (int i = 0; i < 8; ++i) {
    const auto triangle = car_chassis.getTriangle(i);
    const auto shape = createTriangle(triangle, position, color);
    window.draw(shape, transform);
  }
}