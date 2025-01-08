//
// Created by Michał on 08/01/2025.
//

#include "PerlinRoadGenerator.h"

#include <random>

float randomGradient( int x ) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> dist(0, 1);
  return dist(gen) == 0 ? -1.0 : 1.0;;
}

float dotGridGradient( int grid_x, float chosen_point_x ) {
  //TODO might be incorrect
  float gradient = randomGradient( grid_x );

  float dx = chosen_point_x - grid_x;

  return ( dx * gradient );
}

// quadratic interpolation
float interpolate(float a0, float a1, float weight){
  return (a1-a0) * (3.0 - 2.0 * weight ) * weight * weight + a0;

}

/// generate road height at point x
float perlin( float x ) {
  int x0 = (int)x;
  int x1 = x0 + 1;
  float offset_0 = x - (float)x0;
  // generate -1 or 1 for each point x0 and x1

  float graident_0 = dotGridGradient(x0, x);
  float graident_1 = dotGridGradient( x1, x );
  float interpolated = interpolate( graident_0, graident_1, offset_0 );

  return interpolated;
}