/**
 * @ingroup evolution
 * @brief Represents a single specimen in the evolving population.
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#ifndef SPECIMEN_H
#define SPECIMEN_H

#include <vector>

#include "CarDescription.h"

class Specimen;
using Population = std::vector<Specimen>;

class Specimen {
 public:
  static Population createRandomPopulation( int population_size, std::mt19937 random_generator );

  explicit Specimen( const CarDescription& car_description );

  bool operator==( const Specimen& rhs ) const;

  std::vector<float> attributes() const;

  CarDescription carDescription() const;

  std::vector<float>& attributesRef();

  void clampAttributes();

 private:
  std::vector<float> attributes_;
};

#endif  // SPECIMEN_H
