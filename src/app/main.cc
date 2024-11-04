#define IMGUI_DEFINE_MATH_OPERATORS
#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include <imgui-SFML.h>
#include <imgui.h>
#include <iostream>

#include "Simulation.h"

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;

void drawSimulation(sf::RenderWindow& window, const Simulation& simulation, sf::Color bodyColor) {
  b2Vec2 ground_pos = simulation.getGroundPosition();
  b2Vec2 ground_size = simulation.getGroundDimensions();
  b2Vec2 body_pos = simulation.getBodyPosition();
  b2Vec2 body_size = simulation.getBodyDimensions();

  sf::RectangleShape ground(sf::Vector2f(ground_size.x, ground_size.y));
  ground.setOrigin(ground_size.x/2, ground_size.y/2);
  ground.setPosition(ground_pos.x, ground_pos.y);
  ground.setFillColor(sf::Color::Green);

  sf::RectangleShape body(sf::Vector2f(body_size.x, body_size.y));
  body.setOrigin(body_size.x/2, body_size.y/2);
  body.setPosition(body_pos.x, body_pos.y);
  body.setFillColor(bodyColor);

  sf::Transform transform;
  transform.translate(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
  transform.scale(30.0f, -30.0f);

  window.draw(ground, transform);
  window.draw(body, transform);
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

    window.clear();
    drawSimulation(window, sim, body_color);
    ImGui::SFML::Render(window);
    window.display();
  }

  ImGui::SFML::Shutdown();
}
