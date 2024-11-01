#define IMGUI_DEFINE_MATH_OPERATORS
#include <string>
#include <iostream>
#include <iomanip>
#include <box2d/box2d.h>
#include <imgui-SFML.h>
#include <imgui.h>
#include <SFML/Graphics.hpp>

const int window_width = 1600;
const int window_height = 1000;

class Simulation {
public:
  Simulation() : timeStep(1.0f / 60.0f), subStepCount(4) {
    b2WorldDef worldDef = b2DefaultWorldDef();
    worldDef.gravity = b2Vec2{0.0f, -10.0f};
    this->worldId = b2CreateWorld(&worldDef);

    b2BodyDef groundBodyDef = b2DefaultBodyDef();
    groundBodyDef.position = b2Vec2{0.0f, -10.0f};
    this->groundId = b2CreateBody(worldId, &groundBodyDef);
    b2Polygon groundBox = b2MakeBox(50.0f, 10.0f);
    b2ShapeDef groundShapeDef = b2DefaultShapeDef();
    b2CreatePolygonShape(groundId, &groundShapeDef, &groundBox);

    b2BodyDef bodyDef = b2DefaultBodyDef();
    bodyDef.type = b2_dynamicBody;
    bodyDef.position = b2Vec2{0.0f, 10.0f};
    this->bodyId = b2CreateBody(worldId, &bodyDef);
    b2Polygon dynamicBox = b2MakeBox(1.0f, 1.0f);
    b2ShapeDef shapeDef = b2DefaultShapeDef();
    shapeDef.density = 1.0f;
    shapeDef.friction = 0.3f;
    b2CreatePolygonShape(bodyId, &shapeDef, &dynamicBox);
  }

  ~Simulation() {
    b2DestroyWorld(worldId);
  }

  void step() {
    b2World_Step(worldId, timeStep, subStepCount);
  }

  b2Vec2 getBodyPosition() const {
    return b2Body_GetPosition(bodyId);
  }

  b2Vec2 getGroundPosition() const {
    return b2Body_GetPosition(groundId);
  }

  b2Vec2 getGroundDimensions() const {
    return getDimensions(groundId);
  }

  b2Vec2 getBodyDimensions() const {
    return getDimensions(bodyId);
  }

  void kickBox() {
    b2Body_ApplyForce(bodyId, {100.0f, 5000.0f}, getBodyPosition(), true);
  }

private:
  b2Vec2 getDimensions(b2BodyId bodyId) const {
    std::vector<b2ShapeId> shapeIds(5);
    auto nShapes = b2Body_GetShapes(bodyId, shapeIds.data(), shapeIds.size());
    assert(nShapes == 1);

    auto polygon = b2Shape_GetPolygon(shapeIds[0]);
    assert(polygon.count == 4);

    auto width = polygon.vertices[1].x * 2;
    auto height = polygon.vertices[2].y * 2;
    return {width, height};
  }

  b2WorldId worldId;
  b2BodyId groundId;
  b2BodyId bodyId;
  float timeStep;
  int subStepCount;
};

void drawSimulation(sf::RenderWindow& window, const Simulation& simulation, sf::Color bodyColor) {
    b2Vec2 groundPos = simulation.getGroundPosition();
    b2Vec2 groundSize = simulation.getGroundDimensions();
    b2Vec2 bodyPos = simulation.getBodyPosition();
    b2Vec2 bodySize = simulation.getBodyDimensions();

    const float scale = 30.0f;

    sf::RectangleShape ground(sf::Vector2f(groundSize.x * scale, groundSize.y * scale));
    ground.setOrigin(groundSize.x * scale / 2, groundSize.y * scale / 2);
    ground.setPosition(groundPos.x * scale + window_width / 2, window_height/2 - groundPos.y * scale);
    ground.setFillColor(sf::Color::Green);

    sf::RectangleShape body(sf::Vector2f(bodySize.x * scale, bodySize.y * scale));
    body.setOrigin(bodySize.x * scale / 2, bodySize.y * scale / 2);
    body.setPosition(bodyPos.x * scale + window_width / 2, window_height/2 - bodyPos.y * scale);
    body.setFillColor(bodyColor);

    window.draw(ground);
    window.draw(body);
}

int main() {
  sf::Clock clock;
  sf::ContextSettings settings;
  settings.antialiasingLevel = 8;

  auto window = sf::RenderWindow{{window_width, window_height}, "Box2D with ImGui and SFML", sf::Style::Default, settings};
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
  sf::Color bodyColor = sf::Color::Blue;

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
    static float color[3] = { bodyColor.r / 255.0f, bodyColor.g / 255.0f, bodyColor.b / 255.0f };
    if (ImGui::ColorEdit3("Body Color", color)) {
      bodyColor.r = static_cast<sf::Uint8>(color[0] * 255);
      bodyColor.g = static_cast<sf::Uint8>(color[1] * 255);
      bodyColor.b = static_cast<sf::Uint8>(color[2] * 255);
    }
    if (ImGui::Button("Kick")) {
      sim.kickBox();
    }
    ImGui::End();

    window.clear();
    drawSimulation(window, sim, bodyColor);
    ImGui::SFML::Render(window);
    window.display();
  }

  ImGui::SFML::Shutdown();
}
