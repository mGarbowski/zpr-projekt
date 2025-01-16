/**
 * @ingroup common
 * @brief Implementation of Position.
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#include "Position.h"

#include <iomanip>

bool Position::operator==( const Position& other ) const {
  return x_ == other.x_ && y_ == other.y_;
}

std::pair<float, float> Position::asPair() const {
  return { x_, y_ };
}

std::string Position::toString() const {
  std::stringstream stream;
  stream << std::fixed << std::setprecision(2);
  stream << "(" << x_ << ", " << y_ << ")";
  return stream.str();
}