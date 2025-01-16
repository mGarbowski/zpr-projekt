/**
 * @brief Utilities for testing
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#ifndef TESTUTILS_H
#define TESTUTILS_H

#include "Specimen.h"

CarDescription givenCarDescription( int i );

Specimen givenSpecimen( int i );

void assertContainsElement( const Population& population, const Specimen& specimen );

#endif  // TESTUTILS_H
