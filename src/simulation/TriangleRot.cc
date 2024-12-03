/**
 * @ingroup simulation
 * @brief Implementation of TriangleRot
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#include "TriangleRot.h"
Position TriangleRot::a() const {
  return a_;
}
Position TriangleRot::b() const {
  return b_;
}
Position TriangleRot::c() const {
  return c_;
}
float TriangleRot::rotation() const {
  return rotation_;
}