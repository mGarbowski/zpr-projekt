//
// Created by mgarbowski on 11/4/24.
//

#ifndef POSITION_H
#define POSITION_H

struct Position {
  Position(float x, float y) : x(x), y(y) {}

  bool operator==(const Position& other) const;

  float x;
  float y;
};

#endif //POSITION_H
