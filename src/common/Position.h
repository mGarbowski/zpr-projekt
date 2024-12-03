/**
 * @ingroup common
 * @brief Position in 2D space
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#ifndef POSITION_H
#define POSITION_H

struct Position {
  Position(float x, float y) : x_(x), y_(y) {}

  bool operator==(const Position& other) const;

  float x_;
  float y_;
};

#endif //POSITION_H
