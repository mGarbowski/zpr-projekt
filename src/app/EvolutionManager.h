/**
 * @ingroup app
 * @brief Manages the entire evolution process.
 * @authors Mikolaj Garbowski, Michal Luszczek
 *
 * Managing evolution includes:
 *  - maintaining the population
 *  - simulating the cars to calculate their fitness
 *  - evolving the population
 */

#ifndef EVOLUTIONMANAGER_H
#define EVOLUTIONMANAGER_H

#include <optional>

#include "Evolution.h"
#include "FitnessFunction.h"
#include "RoadGenerator.h"
#include "SimulationsManager.h"
#include "mutation/GaussianMutationScheme.h"
#include "reproduction/ProportionalReproductionScheme.h"

struct BestCar {
  CarDescription description_;
  float distance_;
  int iterations_;
  float fitness_;
  int generation_;
};

class EvolutionManager {
 public:
  EvolutionManager( std::mt19937 random_generator, SimulationsManager simulations_manager,
                    URoadGenerator road_generator, Evolution evolution, Population population,
                    FitnessFunction fitness_function )
      : random_generator_( std::move( random_generator ) ),
        simulations_manager_( std::move( simulations_manager ) ),
        road_generator_( std::move( road_generator ) ),
        evolution_( std::move( evolution ) ),
        population_( std::move( population ) ),
        fitness_function_( std::move( fitness_function ) ),
        generation_( 0 ),
        best_car_( std::nullopt ) {}

  int generation() const;

  SimulationsManager simulationsManager() const;

  void update();

  void initializeSimulationsForNewGeneration();

  std::optional<BestCar> bestCar() const;

 private:
  std::vector<float> calculateFitness() const;

  void handleEndOfSimulation();

  void updateBestCar( std::vector<float> fitness );

  std::mt19937 random_generator_;
  SimulationsManager simulations_manager_;
  URoadGenerator road_generator_;
  Evolution evolution_;
  Population population_;
  FitnessFunction fitness_function_;
  int generation_;
  std::optional<BestCar> best_car_;
};

#endif  // EVOLUTIONMANAGER_H
