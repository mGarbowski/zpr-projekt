#define IMGUI_DEFINE_MATH_OPERATORS
#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include <imgui-SFML.h>
#include <imgui.h>
#include <iostream>

#include "../road/StaticRoadGenerator.h"
#include "CarSimulation.h"
#include "ControlPanel.h"
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
sf::CircleShape createSfCircle(const CircleRot& circle, const sf::Color outiline_color, const sf::Color fill_color) {
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
                           sf::Color color = sf::Color::White) {
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

sf::ConvexShape createTriangle(const b2Polygon& triangle, const Position position, const sf::Color color = sf::Color::White) {
  sf::ConvexShape shape(3);
  for (int i = 0; i < 3; ++i) {
    shape.setPoint(
        i, sf::Vector2f(triangle.vertices[i].x + position.x, triangle.vertices[i].y + position.y));
  }
  shape.setFillColor(color);
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
  ImGui::End();
}

void drawCarSimulation(sf::RenderWindow& window, const CarSimulation& simulation,
                       sf::Transform transform, sf::Color ground_color = sf::Color::White, sf::Color car_color = sf::Color::White) {
  const auto rear_wheel = createSfCircle(simulation.getRearWheelCircle(), sf::Color::Red, car_color);
  const auto front_wheel = createSfCircle(simulation.getFrontWheelCircle(), sf::Color::Red, car_color);

  auto car_chassis = simulation.getCarChassis();
  auto body_pos = car_chassis.getPosition();
  for (int i = 0; i < 8; ++i) {
    const auto triangle = car_chassis.getTriangle(i);
    const auto shape = createTriangle(triangle, body_pos, car_color);

    window.draw(shape, transform);
  }
  RoadModel ground = simulation.getRoadModel();
  auto ground_lines = ground.getSegments();
  Position ground_pos = ground.getPosition();
  for (const auto& line : ground_lines) {
    const auto shape = createLine(line.point1, line.point2, ground_pos, ground_color);
    window.draw(shape, transform);
  }
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

  bool simulation_running = false;
  CarDescription car_description = {{-4, 2}, {0, 1.5}, {4, 2}, {2, 0}, {4, -2}, {0, -1}, {-4, -2},
                                    {-2, 0}, 1.0f,     1.0f,   1.0f,   1.0f,    0.5f};
  URoadGenerator road_generator = std::make_unique<StaticRoadGenerator>();
  auto sim = CarSimulation::create(car_description, road_generator->generateRoad());

  std::unique_ptr<ControlPanel> control_panel = std::make_unique<ControlPanel>();
  while (window.isOpen()) {
    for (auto event = sf::Event{}; window.pollEvent(event);) {
      ImGui::SFML::ProcessEvent(window, event);
      if (event.type == sf::Event::Closed)
        window.close();
    }

    auto delta_time = clock.restart();
    if (simulation_running)
      sim.step();
    ImGui::SFML::Update(window, delta_time);

    carDebugPanel(sim);
    control_panel->render();
    simulation_running = control_panel->getRunning();
    window.clear();
    drawCarSimulation(window, sim, transform, control_panel->getRoadColor(), control_panel->getCarColor() );
    ImGui::SFML::Render(window);
    window.display();

    sleep(sf::milliseconds(3));
  }

  ImGui::SFML::Shutdown();
}