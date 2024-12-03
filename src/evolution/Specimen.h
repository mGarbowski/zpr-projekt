/**
 * @ingroup evolution
 * @brief Represents a single specimen in the evolving population.
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#ifndef SPECIMEN_H
#define SPECIMEN_H

#include <vector>

#include "CarDescription.h"

class Specimen {
 public:
  explicit Specimen( const CarDescription& car_description );

  bool operator==( const Specimen& rhs ) const;

  std::vector<float> attributes() const;

  CarDescription carDescription() const;

  std::vector<float>& attributesRef();

 private:
  std::vector<float> attributes_;
};

using Population = std::vector<Specimen>;

#endif  // SPECIMEN_H
