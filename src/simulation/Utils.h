//
// Created by mgarbowski on 11/5/24.
//

#ifndef UTILS_H
#define UTILS_H
#include <box2d/id.h>
#include <math.h>

#include "Position.h"
#include "Rect.h"
#include "RectRot.h"
#include "CircleRot.h"
#include "Size.h"

class Utils {
 public:
  static b2BodyId createStaticRectangle(b2WorldId world_id, Position position, Size size);
  static b2BodyId createDynamicRectangle(b2WorldId world_id, Position position, Size size,
                                         float density, float friction);
  static b2BodyId createDynamicCircle(b2WorldId world_id, Position position, Size size,
                                         float density, float friction);
  static Rect getRectangleRect(b2BodyId body_id);
  static RectRot getRectangleRectRot(b2BodyId body_id);

  static Size getRectangleSize(b2BodyId body_id);
  static Position getBodyPosition(b2BodyId body_id);
  static float getBodyAngleRadians(b2BodyId body_id);
  static float radToDeg(float rad);
  static CircleRot getCircleRot(b2BodyId id);
  static float getCircleRadius(b2BodyId id);
};

#endif  // UTILS_H
