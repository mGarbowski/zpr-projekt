/**
 * @ingroup simulation
 * @brief Physical model of the road composed of line segments
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#ifndef EVOLUTION_ROADMODEL_H
#define EVOLUTION_ROADMODEL_H

#include <box2d/box2d.h>

#include "Position.h"
#include "Road.h"

class RoadModel {
 public:
  /**
   * Adds a road to the Box2D world starting at the specified position
   * @param world_id The Box2D world to create the road in
   * @param road The Road object to be converted to Box2D body
   * @param position The position for the beginning of the road
   */
  static RoadModel create(b2WorldId world_id, const Road& road, Position position);

  Position getPosition() const;
  Position getBeginning() const;
  Position getEnd() const;
  b2BodyId bodyId() const;
  std::vector<b2Segment> getSegments() const;

 private:
  explicit RoadModel(const b2BodyId body_id, Position beginning, Position end)
      : body_id_(body_id), beginning_(beginning), end_(end) {}

  b2BodyId body_id_;
  Position beginning_;
  Position end_;
};

#endif  // EVOLUTION_ROADMODEL_H
