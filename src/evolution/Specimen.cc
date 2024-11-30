//
// Created by mgarbowski on 11/26/24.
//

#include "Specimen.h"

Specimen::Specimen(const CarDescription& car_description) {
  attributes_ = {car_description.topLeft().x,
                 car_description.topLeft().y,
                 car_description.top().y,
                 car_description.topRight().x,
                 car_description.topRight().y,
                 car_description.right().x,
                 car_description.bottomRight().x,
                 car_description.bottomRight().y,
                 car_description.bottom().y,
                 car_description.bottomLeft().x,
                 car_description.bottomLeft().y,
                 car_description.left().x,
                 car_description.bodyDensity(),
                 car_description.rearWheelDensity(),
                 car_description.frontWheelDensity(),
                 car_description.rearWheelRadius(),
                 car_description.frontWheelRadius()};
}
bool Specimen::operator==(const Specimen& rhs) const {
  return attributes_ == rhs.attributes_;
}

std::vector<float> Specimen::attributes() const {
  return attributes_;
}
CarDescription Specimen::carDescription() const {
  return CarDescription(
      Position(attributes_[0], attributes_[1]), Position(0, attributes_[2]),
      Position(attributes_[3], attributes_[4]), Position(attributes_[5], 0),
      Position(attributes_[6], attributes_[7]), Position(0, attributes_[8]),
      Position(attributes_[9], attributes_[10]), Position(attributes_[11], 0),
      attributes_[12], attributes_[13], attributes_[14], attributes_[15], attributes_[16]);
}
std::vector<float>& Specimen::attributesRef() {
  return attributes_;
}