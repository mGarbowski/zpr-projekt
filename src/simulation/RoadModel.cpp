/**
 * @ingroup simulation
 * @brief Implementation of RoadModel
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#include "RoadModel.h"

#include <cassert>

RoadModel RoadModel::create( b2WorldId world_id, const Road& road, Position position ) {
  int road_length = road.points_.size();
  b2BodyDef body_def = b2DefaultBodyDef();
  body_def.type = b2_staticBody;
  body_def.position = { position.x_, position.y_ };
  b2BodyId ground_id = b2CreateBody( world_id, &body_def );

  b2ShapeDef shape_def = b2DefaultShapeDef();
  shape_def.density = 1.0f;
  shape_def.friction = 0.3f;
  shape_def.isSensor = false;
  shape_def.restitution = 0.0f;
  // back wall
  for( int i = 20; i > 0; --i ) {
    b2Segment segment;
    segment.point1 = { -20, static_cast<float>( i ) };
    segment.point2 = { -20, static_cast<float>( i - 1 ) };

    // Create segment shape
    b2CreateSegmentShape( ground_id, &shape_def, &segment );
  }
  // runway
  for( int i = -20; i < 0; ++i ) {
    b2Segment segment;
    segment.point1 = { static_cast<float>( i ), 0 };
    segment.point2 = { static_cast<float>( i + 1 ), 0 };

    // Create segment shape
    b2CreateSegmentShape( ground_id, &shape_def, &segment );
  }

  for( size_t i = 0; i < road.points_.size() - 1; ++i ) {
    b2Segment segment;
    segment.point1 = { road.points_[i].first, road.points_[i].second };
    segment.point2 = { road.points_[i + 1].first, road.points_[i + 1].second };

    // Create segment shape
    b2CreateSegmentShape( ground_id, &shape_def, &segment );
  }

  Position ending{ road.points_[road_length - 1].first, road.points_[road_length - 1].second };
  return RoadModel( ground_id, position, ending );
}

b2BodyId RoadModel::bodyId() const {
  return body_id_;
}
Position RoadModel::getBeginning() const {
  return beginning_;
}

Position RoadModel::getEnd() const {
  return end_;
}
std::vector<b2Segment> RoadModel::getSegments() const {
  std::vector<b2Segment> segments;

  // Get the number of shapes in the body
  int shape_count = b2Body_GetShapeCount( body_id_ );
  if( shape_count == 0 ) {
    return segments;
  }
  std::vector<b2ShapeId> shape_ids( shape_count );
  b2Body_GetShapes( body_id_, shape_ids.data(), shape_count );

  for( const auto& shape_id : shape_ids ) {
    // Check if it's a segment shape, only segments should be present in the RoadModel body
    assert( b2Shape_GetType( shape_id ) == b2ShapeType::b2_segmentShape );
    b2Segment segment = b2Shape_GetSegment( shape_id );
    segments.push_back( segment );
  }

  return segments;
}
Position RoadModel::getPosition() const {
  auto [x, y] = b2Body_GetPosition( body_id_ );
  return { x, y };
}
