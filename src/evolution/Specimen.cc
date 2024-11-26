//
// Created by mgarbowski on 11/26/24.
//

#include "Specimen.h"

Specimen::Specimen(const CarDescription& car_description) {
  attributes_ = {car_description.topLeft().x,
                 car_description.topLeft().y,
                 car_description.top().x,
                 car_description.top().y,
                 car_description.topRight().x,
                 car_description.topRight().y,
                 car_description.right().x,
                 car_description.right().y,
                 car_description.bottomRight().x,
                 car_description.bottomRight().y,
                 car_description.bottom().x,
                 car_description.bottom().y,
                 car_description.bottomLeft().x,
                 car_description.bottomLeft().y,
                 car_description.left().x,
                 car_description.left().y,
                 car_description.bodyDensity(),
                 car_description.rearWheelDensity(),
                 car_description.frontWheelDensity(),
                 car_description.rearWheelRadius(),
                 car_description.frontWheelRadius()};
}
std::vector<float> Specimen::attributes() const {
  return attributes_;
}
CarDescription Specimen::carDescription() const {
  return CarDescription(
      Position(attributes_[0], attributes_[1]), Position(attributes_[2], attributes_[3]),
      Position(attributes_[4], attributes_[5]), Position(attributes_[6], attributes_[7]),
      Position(attributes_[8], attributes_[9]), Position(attributes_[10], attributes_[11]),
      Position(attributes_[12], attributes_[13]), Position(attributes_[14], attributes_[15]),
      attributes_[16], attributes_[17], attributes_[18], attributes_[19], attributes_[20]);
}
std::vector<float>& Specimen::attributes() {
  return attributes_;
}