#define IMGUI_DEFINE_MATH_OPERATORS
#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include <imgui-SFML.h>
#include <imgui.h>
#include <iostream>

#include "../road/StaticRoadGenerator.h"
#include "CarSimulation.h"
#include "GuiControls.h"
#include "RectRot.h"

constexpr int WINDOW_WIDTH = 800;
constexpr int WINDOW_HEIGHT = 800;

sf::Vector2f asVector(const Size& size) {
  return sf::Vector2f(size.width, size.height);
}

sf::Vector2f asVector(const Position& position) {
  return sf::Vector2f(position.x, position.y);
}

sf::RectangleShape createSfRectangle(const RectRot& rect, const sf::Color color) {
  const Position& position = rect.pos();
  const Size& size = rect.size();
  sf::RectangleShape rectangle(asVector(size));
  rectangle.setOrigin(size.width / 2, size.height / 2);
  rectangle.setPosition(asVector(position));
  rectangle.setRotation(rect.rotation());
  rectangle.setFillColor(color);
  return rectangle;
}
sf::CircleShape createSfCircle(const CircleRot& circle, const sf::Color color) {
  const Position& position = circle.pos();
  const float radius = circle.radius();
  sf::CircleShape sf_circle;
  sf_circle.setOrigin(radius, radius);
  sf_circle.setRadius(radius);
  sf_circle.setOutlineColor(color);
  sf_circle.setPosition(asVector(position));

  return sf_circle;
}

sf::VertexArray createLine(const b2Vec2& start, const b2Vec2& end, Position position, sf::Color color = sf::Color::White) {
  sf::VertexArray line(sf::Lines, 2);

  line[0].position = sf::Vector2f(start.x + position.x, start.y + position.y);
  line[0].color = color;
  line[1].position = sf::Vector2f(end.x + position.x, end.y + position.y);
  line[1].color = color;

  return line;
}

sf::RectangleShape createRectangle(const Rect& rect, const sf::Color color) {
  return createSfRectangle({rect.pos(), rect.size(), 0}, color);
}

sf::ConvexShape createTriangle(const b2Polygon& triangle, const Position position) {
  sf::ConvexShape shape(3);
  for (int i = 0; i < 3; ++i) {
    shape.setPoint(
        i, sf::Vector2f(triangle.vertices[i].x + position.x, triangle.vertices[i].y + position.y));
  }
  return shape;
}

sf::Transform box2dToSFML() {
  sf::Transform transform;
  transform.translate(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
  transform.scale(30.0f, -30.0f);
  return transform;
}

void carDebugPanel(const CarSimulation& sim) {
  ImGui::Begin("Car Simulation");
//  GuiControls::rectText("Ground", sim.getGroundRect());
  ImGui::End();
}

void drawCarSimulation(sf::RenderWindow& window, const CarSimulation& simulation,
                       sf::Transform transform) {
//  const auto ground = createRectangle(simulation.getGroundRect(), sf::Color::Green);
  const auto rear_wheel = createSfCircle(simulation.getRearWheelCircle(), sf::Color::Red);
  const auto front_wheel = createSfCircle(simulation.getFrontWheelCircle(), sf::Color::Red);

  auto car_chassis = simulation.getCarChassis();
  auto body_pos = car_chassis.getPosition();
  for (int i = 0; i < 8; ++i) {
    const auto triangle = car_chassis.getTriangle(i);
    const auto shape = createTriangle(triangle, body_pos);
    window.draw(shape, transform);
  }
  RoadModel ground = simulation.getRoadModel();
  auto ground_lines = ground.getSegments();
  Position ground_pos = ground.getPosition();
  for (const auto& line : ground_lines) {
    const auto shape = createLine(line.point1, line.point2, ground_pos);
    window.draw(shape, transform);
  }
//  window.draw(ground, transform);
  window.draw(rear_wheel, transform);
  window.draw(front_wheel, transform);
}

int main() {
  sf::Clock clock;
  sf::ContextSettings settings;
  settings.antialiasingLevel = 8;
  const auto transform = box2dToSFML();

  auto window = sf::RenderWindow{
      {WINDOW_WIDTH, WINDOW_HEIGHT}, "Box2D with ImGui and SFML", sf::Style::Default, settings};
  if (!ImGui::SFML::Init(window)) {
    std::cerr << "Failed to initialize ImGui with SFML." << std::endl;
    window.close();
    return EXIT_FAILURE;
  }

  ImGuiIO& io = ImGui::GetIO();
  io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
  io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
  io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

  CarDescription car_description = {{-4, 2}, {0, 1.5}, {4, 2}, {2, 0}, {4, -2}, {0, -1}, {-4, -2},
                                    {-2, 0}, 1.0f,     1.0f,   1.0f,   1.0f,    0.5f};
  GenericRoadGenerator* road_generator = new StaticRoadGenerator();
  auto sim = CarSimulation::create(car_description, road_generator->generateRoad());
  while (window.isOpen()) {
    for (auto event = sf::Event{}; window.pollEvent(event);) {
      ImGui::SFML::ProcessEvent(window, event);
      if (event.type == sf::Event::Closed)
        window.close();
    }

    auto delta_time = clock.restart();
    sim.step();
    ImGui::SFML::Update(window, delta_time);

    carDebugPanel(sim);

    window.clear();
    drawCarSimulation(window, sim, transform);
    ImGui::SFML::Render(window);
    window.display();

    sleep(sf::milliseconds(3));
  }
  delete road_generator;
  ImGui::SFML::Shutdown();
}