/**
 * Implementation of VisualisationUtils
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#include "VisualisationUtils.h"

sf::Transform box2dToSFML( const int window_width, const int window_height, const float scale,
                           const Position tracked_position ) {
  sf::Transform transform;
  transform.translate( window_width / 2, window_height / 2 );
  transform.scale( scale, -scale );
  transform.translate( -tracked_position.x_, -tracked_position.y_ );
  return transform;
}

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

void drawCarChassis( sf::RenderWindow& window, const CarChassis& car_chassis,
                     const sf::Transform& transform, const sf::Color color ) {
  const auto position = car_chassis.getPosition();
  for( int i = 0; i < 8; ++i ) {
    const auto triangle = car_chassis.getTriangleRot( i );
    auto shape = createTriangle( triangle, position, color );
    window.draw( shape, transform );
  }
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

void drawCarSimulation( sf::RenderWindow& window, const CarSimulation& simulation,
                        const sf::Transform& transform, sf::Color car_color ) {
  const auto rear_wheel = createCircle( simulation.getRearWheelCircle(), car_color, car_color );
  const auto front_wheel = createCircle( simulation.getFrontWheelCircle(), car_color, car_color );
  auto car_chassis = simulation.getCarChassis();

  drawCarChassis( window, car_chassis, transform, car_color );
  window.draw( rear_wheel, transform );
  window.draw( front_wheel, transform );
}

sf::ConvexShape triangle( sf::Vector2f offset, Position a, Position b, Position c,
                          sf::Color color ) {
  sf::ConvexShape shape( 3 );
  shape.setPoint( 0, offset + sf::Vector2f( a.x_, a.y_ ) );
  shape.setPoint( 1, offset + sf::Vector2f( b.x_, b.y_ ) );
  shape.setPoint( 2, offset + sf::Vector2f( c.x_, c.y_ ) );
  shape.setFillColor( color );
  return shape;
}

void drawCarModel( sf::RenderWindow& window, const CarDescription& description,
                   const sf::Transform& transform, sf::Color car_color, sf::Vector2f position ) {
  sf::CircleShape rear_circle;
  rear_circle.setOrigin( description.rearWheelRadius(), description.rearWheelRadius() );
  rear_circle.setRadius( description.rearWheelRadius() );
  rear_circle.setOutlineColor( car_color );
  rear_circle.setOutlineThickness( 0.05f );
  rear_circle.setPosition( position + asVector( description.bottomLeft() ) );
  rear_circle.setFillColor( car_color );

  sf::CircleShape front_wheel;
  front_wheel.setOrigin( description.frontWheelRadius(), description.frontWheelRadius() );
  front_wheel.setRadius( description.frontWheelRadius() );
  front_wheel.setOutlineColor( car_color );
  front_wheel.setOutlineThickness( 0.05f );
  front_wheel.setPosition( position + asVector( description.bottomRight() ) );
  front_wheel.setFillColor( car_color );

  auto c = Position( 0, 0 );
  auto t1 = triangle( position, c, description.left(), description.topLeft(), car_color );
  auto t2 = triangle( position, c, description.topLeft(), description.top(), car_color );
  auto t3 = triangle( position, c, description.top(), description.topRight(), car_color );
  auto t4 = triangle( position, c, description.topRight(), description.right(), car_color );
  auto t5 = triangle( position, c, description.right(), description.bottomRight(), car_color );
  auto t6 = triangle( position, c, description.bottomRight(), description.bottom(), car_color );
  auto t7 = triangle( position, c, description.bottom(), description.bottomLeft(), car_color );
  auto t8 = triangle( position, c, description.bottomLeft(), description.left(), car_color );

  window.draw( rear_circle, transform );
  window.draw( front_wheel, transform );
  window.draw( t1, transform );
  window.draw( t2, transform );
  window.draw( t3, transform );
  window.draw( t4, transform );
  window.draw( t5, transform );
  window.draw( t6, transform );
  window.draw( t7, transform );
  window.draw( t8, transform );
}