/**
 * @ingroup evolution
 * @brief Implementation of Specimen class
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#include "Specimen.h"

Specimen::Specimen(const CarDescription& car_description) {
  attributes_ = {car_description.topLeft().x_,
                 car_description.topLeft().y_,
                 car_description.top().y_,
                 car_description.topRight().x_,
                 car_description.topRight().y_,
                 car_description.right().x_,
                 car_description.bottomRight().x_,
                 car_description.bottomRight().y_,
                 car_description.bottom().y_,
                 car_description.bottomLeft().x_,
                 car_description.bottomLeft().y_,
                 car_description.left().x_,
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
  return CarDescription(Position(attributes_[0], attributes_[1]), Position(0, attributes_[2]),
                        Position(attributes_[3], attributes_[4]), Position(attributes_[5], 0),
                        Position(attributes_[6], attributes_[7]), Position(0, attributes_[8]),
                        Position(attributes_[9], attributes_[10]), Position(attributes_[11], 0),
                        attributes_[12], attributes_[13], attributes_[14], attributes_[15],
                        attributes_[16]);
}
std::vector<float>& Specimen::attributesRef() {
  return attributes_;
}