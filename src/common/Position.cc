/**
 * @ingroup common
 * @brief Implementation of Position.
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#include "Position.h"

bool Position::operator==(const Position& other) const {
  return x_ == other.x_ && y_ == other.y_;
}