#define IMGUI_DEFINE_MATH_OPERATORS
#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include <imgui-SFML.h>
#include <imgui.h>
#include <iostream>

#include "BoxesSimulation.h"
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
  sf_circle.setRadius(radius);
  sf_circle.setOutlineColor(color);
//  sf_circle.setOutlineThickness(3);
  sf_circle.setPosition(asVector(position));

  return sf_circle;
}

sf::RectangleShape createRectangle(const Rect& rect, const sf::Color color) {
  return createSfRectangle({rect.pos(), rect.size(), 0}, color);
}

sf::Transform box2dToSFML() {
  sf::Transform transform;
  transform.translate(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
  transform.scale(30.0f, -30.0f);
  return transform;
}

void drawSimulation(sf::RenderWindow& window, const BoxesSimulation& simulation,
                    sf::Transform transform, sf::Color body_color) {
  const auto ground = createRectangle(simulation.getGroundRect(), sf::Color::Green);
  auto boxes = simulation.getBoxes();
  window.draw(ground, transform);

  std::for_each(boxes.begin(), boxes.end(), [&](const auto& box) {
    auto rectangle = createRectangle(box, body_color);
    window.draw(rectangle, transform);
  });
}

void debugPanel(const BoxesSimulation& sim) {
  const auto ground = sim.getGroundRect();

  ImGui::Begin("Simulation");
  ImGui::Text("Ground x: %.2f y: %.2f", ground.pos().x, ground.pos().y);
  ImGui::Text("Ground width: %.2f height: %.2f", ground.size().width, ground.size().height);
  for (const auto& box : sim.getBoxes()) {
    ImGui::Text("Box width: %.2f height: %.2f", box.size().width, box.size().height);
    ImGui::Text("Box x: %.2f y: %.2f", box.pos().x, box.pos().y);
  }
  ImGui::End();
}

void carDebugPanel(const CarSimulation& sim) {
  ImGui::Begin("Car Simulation");
  GuiControls::rectText("Ground", sim.getGroundRect());
  GuiControls::rectRotText("Car body", sim.getCarBodyRect());
  //GuiControls::rectRotText("Rear wheel", sim.getRearWheelRect());
  //GuiControls::rectRotText("Front wheel", sim.getFrontWheelRect());
  ImGui::End();
}

void drawCarSimulation(sf::RenderWindow& window, const CarSimulation& simulation,
                       sf::Transform transform) {
  const auto ground = createRectangle(simulation.getGroundRect(), sf::Color::Green);
  const auto car_body = createSfRectangle(simulation.getCarBodyRect(), sf::Color::Blue);
  const auto rear_wheel = createSfCircle(simulation.getRearWheelCircle(), sf::Color::Red);
  const auto front_wheel = createSfCircle(simulation.getFrontWheelCircle(), sf::Color::Red);

  window.draw(ground, transform);
  window.draw(car_body, transform);
  window.draw(rear_wheel, transform);
  window.draw(front_wheel, transform);
}

void controlPanel(sf::Color& body_color, const BoxesSimulation& sim) {
  ImGui::Begin("Control Panel");

  if (float color[3] = {body_color.r / 255.0f, body_color.g / 255.0f, body_color.b / 255.0f};
      ImGui::ColorEdit3("Body Color", color)) {
    body_color.r = static_cast<sf::Uint8>(color[0] * 255);
    body_color.g = static_cast<sf::Uint8>(color[1] * 255);
    body_color.b = static_cast<sf::Uint8>(color[2] * 255);
  }

  if (ImGui::Button("Kick")) {
    sim.kickBox();
    std::cout << "Kicked" << std::endl;
  }

  ImGui::End();
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

  auto sim = CarSimulation::create();
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

    sf::sleep(sf::milliseconds(3));
  }

  ImGui::SFML::Shutdown();
}