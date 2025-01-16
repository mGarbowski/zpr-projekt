#ifndef TESTUTILS_H
#define TESTUTILS_H

#include "CarDescription.h"
#include "CarSimulation.h"
#include "Road.h"
#include "Specimen.h"

Road givenRoad();

CarDescription givenCarDescription();

CarSimulation givenSimulation();

CarSimulation givenFinishedSimulation();

Specimen givenSpecimen( const int i );

Population givenPopulation();

#endif  // TESTUTILS_H
