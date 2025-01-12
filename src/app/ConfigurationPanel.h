/**
 * @ingroup app
 * @brief Panel for configuring the evolution parameters before it starts.
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#ifndef CONFIGURATIONPANEL_H
#define CONFIGURATIONPANEL_H

class ConfigurationPanel {
 public:
  explicit ConfigurationPanel() : population_size_( 20 ), start_evolution_( false ) {}

  int populationSize() const;
  bool shouldStartEvolution() const;

  void render();

 private:
  int population_size_;
  bool start_evolution_;
};

#endif  // CONFIGURATIONPANEL_H
