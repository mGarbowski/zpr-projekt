//
// Created by mgarbowski on 11/4/24.
//

#ifndef RECT_H
#define RECT_H
#include "Position.h"
#include "Size.h"

class Rect {
 public:
  Rect(): pos_({0, 0}), size_({0, 0}) {}
  Rect(Position pos, Size size) : pos_(pos), size_(size) {}

  Position pos() const {
    return pos_;
  }
  Size size() const {
    return size_;
  }

 private:
  Position pos_;
  Size size_;
};
#endif  // RECT_H
