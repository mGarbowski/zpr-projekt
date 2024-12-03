/**
 * @ingroup simulation
 * @brief Represents a rectangle with rotation in 2D space
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#ifndef RECTROT_H
#define RECTROT_H

#include "Position.h"
#include "Size.h"

class RectRot {
 public:
  RectRot(const Position& pos, const Size& size, float rotation)
      : pos_(pos), size_(size), rotation_(rotation) {}

  Position pos() const {
    return pos_;
  }
  Size size() const {
    return size_;
  }
  float rotation() const {
    return rotation_;
  }

 private:
  Position pos_;
  Size size_;
  float rotation_;
};

#endif  // RECTROT_H
