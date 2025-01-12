/**
 * @ingroup road
 * @brief Implementation of PerlinRoadGenerator
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#include "PerlinRoadGenerator.h"

#include <random>

float randomGradient() {
  std::random_device rd;
  std::mt19937 gen( rd() );
  std::uniform_int_distribution dist( 0, 1 );
  return dist( gen ) == 0 ? -1.0 : 1.0;
}

float dotGridGradient( const int grid_x, const float chosen_point_x ) {
  const float gradient = randomGradient();
  const float dx = chosen_point_x - grid_x;
  return dx * gradient;
}

// quadratic interpolation
float interpolate( const float a0, const float a1, const float weight ) {
  return ( a1 - a0 ) * ( 3.0 - 2.0 * weight ) * weight * weight + a0;
}

/// generate road height at point x
float perlin( const float x ) {
  const int x0 = static_cast<int>( x );
  const int x1 = x0 + 1;
  const float offset_0 = x - static_cast<float>( x0 );
  // generate -1 or 1 for each point x0 and x1

  const float gradient_0 = dotGridGradient( x0, x );
  const float gradient_1 = dotGridGradient( x1, x );
  const float interpolated = interpolate( gradient_0, gradient_1, offset_0 );

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
      height += perlin( static_cast<float>( x ) * frequency / grid_size_ ) * amplitude;
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
