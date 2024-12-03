/**
 * @ingroup simulation
 * @brief Physical model of the car chassis composed of triangles with a shared center vertex
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#ifndef CARCHASSIS_H
#define CARCHASSIS_H

#include <box2d/box2d.h>

#include "CarDescription.h"
#include "Position.h"
#include "TriangleRot.h"

class CarChassis {
 public:
  static CarChassis create( b2WorldId world_id, Position position,
                            const CarDescription& car_description );

  b2BodyId bodyId() const;
  TriangleRot getTriangleRot( int idx ) const;
  b2Polygon getTriangle( int idx ) const;
  Position getPosition() const;

 private:
  explicit CarChassis( const b2BodyId body_id ) : body_id_( body_id ) {}

  b2BodyId body_id_;
};

#endif  // CARCHASSIS_H
