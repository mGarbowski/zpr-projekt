/**
 * @ingroup common
 * @brief Position in 2D space
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#ifndef POSITION_H
#define POSITION_H

#include <string>
#include <utility>

struct Position {
  Position( const float x, const float y ) : x_( x ), y_( y ) {}

  bool operator==( const Position& other ) const;

  Position operator+( const Position& other ) const;

  std::pair<float, float> asPair() const;

  std::string toString() const;

  float x_;
  float y_;
};

#endif  // POSITION_H
