/**
 * @ingroup app
 * @brief UI element for displaying parameters of the best car.
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#ifndef BESTCARPARAMSPANEL_H
#define BESTCARPARAMSPANEL_H

#include "EvolutionManager.h"

class BestCarParamsPanel {
 public:
  BestCarParamsPanel(): best_car_( std::nullopt ) {}

  void render();

  void update(const EvolutionManager& evolution_manager);

 private:
  void renderEmpty();
  void renderNormal();

  std::optional<BestCar> best_car_;
};

#endif  // BESTCARPARAMSPANEL_H
