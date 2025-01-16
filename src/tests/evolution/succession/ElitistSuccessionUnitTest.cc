#include <gtest/gtest.h>

#include "../TestUtils.h"
#include "Specimen.h"
#include "succession/ElitistSuccessionScheme.h"
#include "succession/SuccessionScheme.h"

namespace ElitistSuccessionUnitTest {

int countMutantsInNextGeneration( const Population& next_generation, const Population& mutants ) {
  return std::count_if( mutants.begin(), mutants.end(),
                        [&next_generation]( const Specimen& mutant ) {
                          return containsElement( next_generation, mutant );
                        } );
}

TEST( ElitistSuccessionScheme, eliteSize1 ) {
  const Population original_population = { givenSpecimen( 0 ), givenSpecimen( 1 ),
                                           givenSpecimen( 2 ) };
  const Population mutants = { givenSpecimen( 3 ), givenSpecimen( 4 ), givenSpecimen( 5 ) };
  const std::vector<float> fitness = { 1, 2, 3 };
  const USuccessionScheme succession = std::make_unique<ElitistSuccessionScheme>( 1 );

  const auto next_generation = succession->nextGeneration( original_population, mutants, fitness );

  EXPECT_EQ( original_population.size(), next_generation.size() );
  assertDoesNotContainElement( next_generation, original_population[0] );
  assertDoesNotContainElement( next_generation, original_population[1] );
  assertContainsElement( next_generation, original_population[2] );

  EXPECT_EQ( countMutantsInNextGeneration( next_generation, mutants ), 2 );
}

TEST( ElitistSuccessionScheme, eliteSize2 ) {
  const Population original_population = { givenSpecimen( 0 ), givenSpecimen( 1 ),
                                           givenSpecimen( 2 ) };
  const Population mutants = { givenSpecimen( 3 ), givenSpecimen( 4 ), givenSpecimen( 5 ) };
  const std::vector<float> fitness = { 5, 2, 3 };
  const USuccessionScheme succession = std::make_unique<ElitistSuccessionScheme>( 2 );

  const auto next_generation = succession->nextGeneration( original_population, mutants, fitness );

  EXPECT_EQ( original_population.size(), next_generation.size() );
  assertContainsElement( next_generation, original_population[0] );
  assertDoesNotContainElement( next_generation, original_population[1] );
  assertContainsElement( next_generation, original_population[2] );

  EXPECT_EQ( countMutantsInNextGeneration( next_generation, mutants ), 1 );
}

TEST( ElitistSuccessionScheme, eliteSizeEqualOriginalPopulationSize ) {
  const Population original_population = { givenSpecimen( 0 ), givenSpecimen( 1 ),
                                           givenSpecimen( 2 ) };
  const Population mutants = { givenSpecimen( 3 ), givenSpecimen( 4 ), givenSpecimen( 5 ) };
  const std::vector<float> fitness = { 5, 2, 3 };
  const USuccessionScheme succession = std::make_unique<ElitistSuccessionScheme>( 3 );

  const auto next_generation = succession->nextGeneration( original_population, mutants, fitness );

  EXPECT_EQ( original_population.size(), next_generation.size() );
  assertContainsElement( next_generation, original_population[0] );
  assertContainsElement( next_generation, original_population[1] );
  assertContainsElement( next_generation, original_population[2] );
}

TEST( ElitistSuccessionScheme, eliteSizeInvalid ) {
  EXPECT_THROW( ElitistSuccessionScheme( 0 ), std::invalid_argument );
  EXPECT_THROW( ElitistSuccessionScheme( -1 ), std::invalid_argument );
}

TEST( ElitistSuccessionScheme, eliteLargerThanPopulation ) {
  const Population original_population = { givenSpecimen( 0 ), givenSpecimen( 1 ),
                                           givenSpecimen( 2 ) };
  const Population mutants = { givenSpecimen( 3 ), givenSpecimen( 4 ), givenSpecimen( 5 ) };
  const std::vector<float> fitness = { 1, 2, 3 };

  const USuccessionScheme succession = std::make_unique<ElitistSuccessionScheme>( 4 );

  EXPECT_THROW( succession->nextGeneration( original_population, mutants, fitness ),
                std::runtime_error );
}

}  // namespace ElitistSuccessionUnitTest