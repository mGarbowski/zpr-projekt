/**
 * @ingroup simulation
 * @brief Represents size of a 2D object
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#ifndef SIZE_H
#define SIZE_H

struct Size {
  Size( float width, float height ) : width_( width ), height_( height ) {}

  float width_;
  float height_;
};

#endif  // SIZE_H
