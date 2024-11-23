//
// Created by michluszcz on 23.11.24.
//

#ifndef EVOLUTION_ROADCONVERTER_H
#define EVOLUTION_ROADCONVERTER_H

#include "../road/Road.h"
#include <box2d/box2d.h>
class RoadConverter {

  /**
     * Adds a road to the Box2D world starting at the specified position
     * @param world The Box2D world to add the road to
     * @param road The road object to be converted to Box2D body
     * @param x The x-coordinate position for the beginning of the road
     * @param y The y-coordinate position for the beginning of the road
   */
  void addRoad(b2WorldId world_id, const Road& road, float x, float y);




};

#endif  // EVOLUTION_ROADCONVERTER_H
