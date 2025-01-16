/**
 * Implementation of VisualisationUtils
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#include "VisualisationUtils.h"

sf::Vector2f asVector( const Position& position ) {
  return sf::Vector2f( position.x_, position.y_ );
}

sf::CircleShape createCircle( const CircleRot& circle, const sf::Color outline_color,
                              const sf::Color fill_color ) {
  const Position& position = circle.pos();
  const float radius = circle.radius();
  sf::CircleShape sf_circle;
  sf_circle.setOrigin( radius, radius );
  sf_circle.setRadius( radius );
  sf_circle.setOutlineColor( outline_color );
  sf_circle.setOutlineThickness( 0.05f );
  sf_circle.setPosition( asVector( position ) );
  sf_circle.setFillColor( fill_color );

  return sf_circle;
}

sf::VertexArray createLine( const b2Vec2& start, const b2Vec2& end, const Position position,
                            const sf::Color color ) {
  sf::VertexArray line( sf::Lines, 2 );

  line[0].position = sf::Vector2f( start.x + position.x_, start.y + position.y_ );
  line[0].color = color;
  line[1].position = sf::Vector2f( end.x + position.x_, end.y + position.y_ );
  line[1].color = color;

  return line;
}

sf::ConvexShape createTriangle( const TriangleRot& triangle, const Position position,
                                const sf::Color color ) {
  sf::ConvexShape shape( 3 );
  shape.setPoint( 0, sf::Vector2f( triangle.a().x_, triangle.a().y_ ) );
  shape.setPoint( 1, sf::Vector2f( triangle.b().x_, triangle.b().y_ ) );
  shape.setPoint( 2, sf::Vector2f( triangle.c().x_, triangle.c().y_ ) );

  shape.setFillColor( color );
  shape.setPosition( asVector( position ) );
  shape.rotate( triangle.rotation() );

  return shape;
}

void drawRoad( sf::RenderWindow& window, const RoadModel& road_model,
               const sf::Transform& transform, const sf::Color color ) {
  auto road_segments = road_model.getSegments();
  const auto offset = road_model.getPosition();
  for( const auto& [point1, point2] : road_segments ) {
    const auto line = createLine( point1, point2, offset, color );
    window.draw( line, transform );
  }
}
