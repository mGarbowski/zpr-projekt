/**
 * @ingroup road
 * @brief Implementation of PerlinRoadGenerator
 * @authors Mikolaj Garbowski, Michal Luszczek
 */
#include "PerlinRoadGenerator.h"

#include <random>

float randomGradient( int x ) {
  std::random_device rd;
  std::mt19937 gen( rd() );
  std::uniform_int_distribution<int> dist( 0, 1 );
  return dist( gen ) == 0 ? -1.0 : 1.0;
  ;
}

float dotGridGradient( int grid_x, float chosen_point_x ) {
  float gradient = randomGradient( grid_x );

  float dx = chosen_point_x - grid_x;

  return ( dx * gradient );
}

// quadratic interpolation
float interpolate( float a0, float a1, float weight ) {
  return ( a1 - a0 ) * ( 3.0 - 2.0 * weight ) * weight * weight + a0;
}

/// generate road height at point x
float perlin( float x ) {
  int x0 = (int)x;
  int x1 = x0 + 1;
  float offset_0 = x - (float)x0;
  // generate -1 or 1 for each point x0 and x1

  float graident_0 = dotGridGradient( x0, x );
  float graident_1 = dotGridGradient( x1, x );
  float interpolated = interpolate( graident_0, graident_1, offset_0 );

  return interpolated;
}

Road PerlinRoadGenerator::generateRoadImpl() const {
  std::vector<Point> road;
  road.push_back( { 0, 0 } );

  for( int x = 1; x < length_; ++x ) {
    float height = 0;
    float frequency = 1;
    float amplitude = 1;
    for( int layer_index = 0; layer_index < layers_; ++layer_index ) {
      height += perlin( (float)x * frequency / grid_size_ ) * amplitude;
      frequency *= 2;
      amplitude *= 0.5;
    }
    if( height < -1 ) {
      height = -1;
    } else if( height > 1 ) {
      height = 1;
    }
    road.push_back( { x * scale_x_, height * scale_y_ } );
  }

  return Road( road );
}
