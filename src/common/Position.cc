//
// Created by mgarbowski on 11/26/24.
//

#include "Position.h"

bool Position::operator==(const Position& other) const {
  return x == other.x && y == other.y;
}