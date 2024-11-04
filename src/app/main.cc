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

sf::RectangleShape createRectangle(const Position& position, const Size& size,
                                   const sf::Color color) {
  sf::RectangleShape rectangle(asVector(size));
  rectangle.setPosition(asVector(position));
  rectangle.setFillColor(color);
}

void drawSimulation(sf::RenderWindow& window, const Simulation& simulation, sf::Color bodyColor) {
  auto ground_pos = simulation.getGroundPosition();
  auto ground_size = simulation.getGroundDimensions();
  auto body_pos = simulation.getBodyPosition();
  auto body_size = simulation.getBodyDimensions();

  sf::RectangleShape ground(sf::Vector2f(ground_size.width, ground_size.height));
  ground.setOrigin(ground_size.width / 2, ground_size.height / 2);
  ground.setPosition(ground_pos.x, ground_pos.y);
  ground.setFillColor(sf::Color::Green);

  sf::RectangleShape body(sf::Vector2f(body_size.width, body_size.height));
  body.setOrigin(body_size.width / 2, body_size.height / 2);
  body.setPosition(body_pos.x, body_pos.y);
  body.setFillColor(bodyColor);

  sf::Transform transform;
  transform.translate(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
  transform.scale(30.0f, -30.0f);

  window.draw(ground, transform);
  window.draw(body, transform);
}

void debugPanel(const Simulation& sim) {
  const auto ground_pos = sim.getGroundPosition();
  const auto ground_size = sim.getGroundDimensions();
  const auto body_pos = sim.getBodyPosition();
  const auto body_size = sim.getBodyDimensions();

  ImGui::Begin("Simulation");
  ImGui::Text("Ground x: %.2f y: %.2f", ground_pos.x, ground_pos.y);
  ImGui::Text("Ground width: %.2f height: %.2f", ground_size.width, ground_size.height);
  ImGui::Text("Box x: %.2f y: %.2f", body_pos.x, body_pos.y);
  ImGui::Text("Box width: %.2f height: %.2f", body_size.width, body_size.height);
  ImGui::End();
}

int main() {
  sf::Clock clock;
  sf::ContextSettings settings;
  settings.antialiasingLevel = 8;

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

  Simulation sim;
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
    }
    ImGui::End();

    debugPanel(sim);

    window.clear();
    drawSimulation(window, sim, body_color);
    ImGui::SFML::Render(window);
    window.display();

    sf::sleep(sf::milliseconds(3));
  }

  ImGui::SFML::Shutdown();
}
