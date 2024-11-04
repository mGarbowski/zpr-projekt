//
// Created by mgarbowski on 11/4/24.
//

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <box2d/box2d.h>

#include "Position.h"
#include "Size.h"

b2BodyId makeStaticRectangle(b2WorldId world_id, Position position, Size size);
b2BodyId makeDynamicRectangle(b2WorldId world_id, Position position, Size size, float density, float friction);

#endif  // RECTANGLE_H
