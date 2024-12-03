/**
 * @ingroup common
 * @brief Position in 2D space
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#ifndef POSITION_H
#define POSITION_H

struct Position {
  Position(float x, float y) : x(x), y(y) {}

  bool operator==(const Position& other) const;

  float x;
  float y;
};

#endif //POSITION_H
