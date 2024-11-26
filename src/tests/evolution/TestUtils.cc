//
// Created by mgarbowski on 11/26/24.
//

#include "TestUtils.h"
Specimen givenSpecimen(const int i) {
  return Specimen(CarDescription(Position(i + 0.0f, i + 1.0f), Position(i + 2.0f, i + 3.0f),
                                 Position(i + 4.0f, i + 5.0f), Position(i + 6.0f, i + 7.0f),
                                 Position(i + 8.0f, i + 9.0f), Position(i + 10.0f, i + 11.0f),
                                 Position(i + 12.0f, i + 13.0f), Position(i + 14.0f, i + 15.0f),
                                 i + 16.0f, i + 17.0f, i + 18.0f, i + 19.0f, i + 20.0f));
}