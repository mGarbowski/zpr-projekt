//
// Created by mgarbowski on 11/26/24.
//

#ifndef SPECIMEN_H
#define SPECIMEN_H

#include <CarDescription.h>
#include <vector>

/**
 * @ingroup evolution
 * @brief Represents a single specimen in the evolving population.
 */
class Specimen {
 public:
  explicit Specimen(const CarDescription &car_description);

  bool operator==(const Specimen &rhs) const;

  std::vector<float> attributes() const;

  CarDescription carDescription() const;

  std::vector<float>& attributesRef();

 private:
  std::vector<float> attributes_;
};

using Population = std::vector<Specimen>;

#endif //SPECIMEN_H
