#define IMGUI_DEFINE_MATH_OPERATORS
#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include <imgui-SFML.h>
#include <imgui.h>
#include <iostream>

#include "Simulation.h"

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;

sf::Vector2f asVector(const Size& size) {
  return sf::Vector2f(size.width, size.height);
}

sf::Vector2f asVector(const Position& position) {
  return sf::Vector2f(position.x, position.y);
}

sf::RectangleShape createRectangle(const Rect& rect, const sf::Color color) {
  const Position& position = rect.pos();
  const Size& size = rect.size();
  sf::RectangleShape rectangle(asVector(size));
  rectangle.setOrigin(size.width / 2, size.height / 2);
  rectangle.setPosition(asVector(position));
  rectangle.setFillColor(color);
  return rectangle;
}

sf::Transform box2dToSFML() {
  sf::Transform transform;
  transform.translate(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
  transform.scale(30.0f, -30.0f);
  return transform;
}

void drawSimulation(sf::RenderWindow& window, const Simulation& simulation, sf::Transform transform,
                    sf::Color bodyColor) {
  const auto ground = createRectangle(simulation.getGroundRect(), sf::Color::Green);
  auto boxes = simulation.getBoxes();
  window.draw(ground, transform);

  std::for_each(boxes.begin(), boxes.end(), [&](const auto& box) {
    auto rectangle = createRectangle(box, bodyColor);
    window.draw(rectangle, transform);
  });
}

void debugPanel(const Simulation& sim) {
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

  Size box_size = {2, 2};
  std::vector<Rect> boxes = {
      {{0, 10}, box_size},
      {{1, 15}, box_size},
  };
  Position ground_pos = {0, -10};
  Size ground_size = {20, 1};
  auto ground = Rect(ground_pos, ground_size);
  Simulation sim(boxes, ground);
  sf::Color body_color = sf::Color::Blue;

  while (window.isOpen()) {
    for (auto event = sf::Event{}; window.pollEvent(event);) {
      ImGui::SFML::ProcessEvent(window, event);
      if (event.type == sf::Event::Closed)
        window.close();
    }

    auto delta_time = clock.restart();
    sim.step();
    ImGui::SFML::Update(window, delta_time);

    ImGui::Begin("Control Panel");
    static float color[3] = {body_color.r / 255.0f, body_color.g / 255.0f, body_color.b / 255.0f};
    if (ImGui::ColorEdit3("Body Color", color)) {
      body_color.r = static_cast<sf::Uint8>(color[0] * 255);
      body_color.g = static_cast<sf::Uint8>(color[1] * 255);
      body_color.b = static_cast<sf::Uint8>(color[2] * 255);
    }
    if (ImGui::Button("Kick")) {
      sim.kickBox();
      std::cout << "Kicked" << std::endl;
    }
    ImGui::End();

    debugPanel(sim);

    window.clear();
    drawSimulation(window, sim, transform, body_color);
    ImGui::SFML::Render(window);
    window.display();

    sf::sleep(sf::milliseconds(3));
  }

  ImGui::SFML::Shutdown();
}