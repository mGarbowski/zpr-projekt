/**
 * @ingroup common
 * @brief Implementation of Position.
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#include "Position.h"

bool Position::operator==(const Position& other) const {
  return x == other.x && y == other.y;
}