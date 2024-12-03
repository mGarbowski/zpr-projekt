/**
 * @ingroup road
 * @brief Container for points representing a road
 * @author Mikolaj Garbowski, Michal Luszczek
 */

#ifndef ROAD_H
#define ROAD_H

#include <vector>

class Road {
 public:
  explicit Road( std::vector<std::pair<float, float>> road ) : points_( std::move( road ) ) {}

  std::vector<std::pair<float, float>> points_;
};
#endif  // ROAD_H
