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

  std::vector<float> attributes() const;

  CarDescription carDescription() const;

 private:
  std::vector<float> attributes_;
};

#endif //SPECIMEN_H
