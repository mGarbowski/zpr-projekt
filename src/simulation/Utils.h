/**
 * @ingroup simulation
 * @brief General utilities for working with Box2D objects
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#ifndef UTILS_H
#define UTILS_H
#include <box2d/box2d.h>

#include "CircleRot.h"
#include "Position.h"
#include "RectRot.h"
#include "Size.h"

class Utils {
 public:
  static b2BodyId createDynamicCircle( b2WorldId world_id, Position position, float radius,
                                       float density, float friction );
  static RectRot getRectangleRectRot( b2BodyId body_id );

  static Size getRectangleSize( b2BodyId body_id );
  static Position getBodyPosition( b2BodyId body_id );
  static float getBodyAngleRadians( b2BodyId body_id );
  static float radToDeg( float rad );
  static CircleRot getCircleRot( b2BodyId id );
  static float getCircleRadius( b2BodyId id );

  static b2Vec2 asVec( Position position );
};

#endif  // UTILS_H
