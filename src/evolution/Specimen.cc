/**
 * @ingroup evolution
 * @brief Implementation of Specimen class
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#include "Specimen.h"

#include <cassert>

Specimen::Specimen( const CarDescription& car_description ) {
  attributes_ = { car_description.topLeft().x_,
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
                  car_description.frontWheelRadius() };
}
bool Specimen::operator==( const Specimen& rhs ) const {
  return attributes_ == rhs.attributes_;
}

std::vector<float> Specimen::attributes() const {
  return attributes_;
}
CarDescription Specimen::carDescription() const {
  return CarDescription( Position( attributes_[0], attributes_[1] ), Position( 0, attributes_[2] ),
                         Position( attributes_[3], attributes_[4] ), Position( attributes_[5], 0 ),
                         Position( attributes_[6], attributes_[7] ), Position( 0, attributes_[8] ),
                         Position( attributes_[9], attributes_[10] ),
                         Position( attributes_[11], 0 ), attributes_[12], attributes_[13],
                         attributes_[14], attributes_[15], attributes_[16] );
}
std::vector<float>& Specimen::attributesRef() {
  return attributes_;
}
void Specimen::clampAttributes() {
  constexpr auto position_abs_min = 0.2f;
  constexpr auto position_abs_max = 6.0f;
  constexpr auto density_min = 0.2f;
  constexpr auto density_max = 6.0f;
  constexpr auto radius_min = 0.2f;
  constexpr auto radius_max = 6.0f;

  const std::vector<float> min_attributes = {
      -position_abs_max,  // car_description.topLeft().x_,
      position_abs_min,   // car_description.topLeft().y_,
      position_abs_min,   // car_description.top().y_,
      position_abs_min,   // car_description.topRight().x_,
      position_abs_min,   // car_description.topRight().y_,
      position_abs_min,   // car_description.right().x_,
      position_abs_min,   // car_description.bottomRight().x_,
      -position_abs_max,  // car_description.bottomRight().y_,
      -position_abs_max,  // car_description.bottom().y_,
      -position_abs_max,  // car_description.bottomLeft().x_,
      -position_abs_max,  // car_description.bottomLeft().y_,
      -position_abs_max,  // car_description.left().x_,
      density_min,        // car_description.bodyDensity(),
      density_min,        // car_description.rearWheelDensity(),
      density_min,        // car_description.frontWheelDensity(),
      radius_min,         // car_description.rearWheelRadius(),
      radius_min          // car_description.frontWheelRadius()
  };

  const std::vector<float> max_attributes = {
      -position_abs_min,  // car_description.topLeft().x_,
      position_abs_max,   // car_description.topLeft().y_,
      position_abs_max,   // car_description.top().y_,
      position_abs_max,   // car_description.topRight().x_,
      position_abs_max,   // car_description.topRight().y_,
      position_abs_max,   // car_description.right().x_,
      position_abs_max,   // car_description.bottomRight().x_,
      -position_abs_min,  // car_description.bottomRight().y_,
      -position_abs_min,  // car_description.bottom().y_,
      -position_abs_min,  // car_description.bottomLeft().x_,
      -position_abs_min,  // car_description.bottomLeft().y_,
      -position_abs_min,  // car_description.left().x_,
      density_max,        // car_description.bodyDensity(),
      density_max,        // car_description.rearWheelDensity(),
      density_max,        // car_description.frontWheelDensity(),
      radius_max,         // car_description.rearWheelRadius(),
      radius_max          // car_description.frontWheelRadius()
  };

  assert( attributes_.size() == max_attributes.size() );
  assert( attributes_.size() == min_attributes.size() );

  for( size_t i = 0; i < attributes_.size(); ++i ) {
    if( attributes_[i] < min_attributes[i] ) {
      attributes_[i] = min_attributes[i];
    } else if( attributes_[i] > max_attributes[i] ) {
      attributes_[i] = max_attributes[i];
    }
  }
}