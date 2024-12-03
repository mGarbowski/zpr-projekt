/**
 * Implementation of VisualisationUtils
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#include "VisualisationUtils.h"

sf::Transform box2dToSFML(const int window_width, const int window_height, const float scale) {
  sf::Transform transform;
  transform.translate(window_width / 2, window_height / 2);
  transform.scale(scale, -scale);
  return transform;
}

sf::Vector2f asVector(const Size& size) {
  return sf::Vector2f(size.width_, size.height_);
}

sf::Vector2f asVector(const Position& position) {
  return sf::Vector2f(position.x_, position.y_);
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

  line[0].position = sf::Vector2f(start.x + position.x_, start.y + position.y_);
  line[0].color = color;
  line[1].position = sf::Vector2f(end.x + position.x_, end.y + position.y_);
  line[1].color = color;

  return line;
}

sf::ConvexShape createTriangle(const TriangleRot& triangle, const Position position,
                               const sf::Color color) {
  sf::ConvexShape shape(3);
  shape.setOrigin(-asVector(position));  // FIXME
  shape.setPoint(0, sf::Vector2f(triangle.a().x_, triangle.a().y_));
  shape.setPoint(1, sf::Vector2f(triangle.b().x_, triangle.b().y_));
  shape.setPoint(2, sf::Vector2f(triangle.c().x_, triangle.c().y_));
  shape.setRotation(triangle.rotation());
  shape.setFillColor(color);

  return shape;
}

void drawCarChassis(sf::RenderWindow& window, const CarChassis& car_chassis,
                    const sf::Transform& transform, const sf::Color color) {
  const auto position = car_chassis.getPosition();
  for (int i = 0; i < 8; ++i) {
    const auto triangle = car_chassis.getTriangleRot(i);
    const auto shape = createTriangle(triangle, position, color);
    window.draw(shape, transform);
  }
}

void drawRoad(sf::RenderWindow& window, const RoadModel& road_model, const sf::Transform& transform,
              const sf::Color color) {
  auto road_segments = road_model.getSegments();
  const auto offset = road_model.getPosition();
  for (const auto& [point1, point2] : road_segments) {
    const auto line = createLine(point1, point2, offset, color);
    window.draw(line, transform);
  }
}

void drawCarSimulation(sf::RenderWindow& window, const CarSimulation& simulation,
                       const sf::Transform& transform, sf::Color ground_color,
                       sf::Color car_color) {
  const auto rear_wheel = createCircle(simulation.getRearWheelCircle(), car_color, car_color);
  const auto front_wheel = createCircle(simulation.getFrontWheelCircle(), car_color, car_color);
  auto car_chassis = simulation.getCarChassis();
  auto ground = simulation.getRoadModel();

  drawCarChassis(window, car_chassis, transform, car_color);
  drawRoad(window, ground, transform, ground_color);
  window.draw(rear_wheel, transform);
  window.draw(front_wheel, transform);
}