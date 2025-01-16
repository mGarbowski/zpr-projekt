/**
 * @brief Implementation of TestUtils
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#include "TestUtils.h"

#include <gtest/gtest.h>

CarDescription givenCarDescription( const int i ) {
  const Position top_left = { -1, static_cast<float>( 1 + 0.1 * i ) };
  const Position top = { 0, 1 };
  const Position top_right = { 1, 1 };
  const Position right = { 1, 0 };
  const Position bottom_right = { 1, -1 };
  const Position bottom = { 0, -1 };
  const Position bottom_left = { -1, -1 };
  const Position left = { -1, 0 };
  constexpr float body_density = 1.0f;
  constexpr float rear_wheel_density = 1.0f;
  constexpr float front_wheel_density = 1.0f;
  constexpr float rear_wheel_radius = 1.0f;
  constexpr float front_wheel_radius = 1.0f;

  return CarDescription( top_left, top, top_right, right, bottom_right, bottom, bottom_left, left,
                         body_density, rear_wheel_density, front_wheel_density, rear_wheel_radius,
                         front_wheel_radius );
}

Specimen givenSpecimen( const int i ) {
  return Specimen( givenCarDescription( i ) );
}

void assertContainsElement( const Population& population, const Specimen& specimen ) {
  if( !containsElement( population, specimen ) ) {
    FAIL() << "Population does not contain specimen";
  }
}

void assertDoesNotContainElement( const Population& population, const Specimen& specimen ) {
  if( containsElement( population, specimen ) ) {
    FAIL() << "Population contains specimen";
  }
}

bool containsElement( const Population& population, const Specimen& specimen ) {
  return std::find( population.begin(), population.end(), specimen ) != population.end();
}