/**
 * @authors Mikolaj Garbowski, Michal Luszczek
 *
 * \mainpage Car Evolution Project
 *
 * \section intro_sec Introduction
 * The project is a simulation of a car evolution.
 * The user can select parameters of the simulation including
 *    - variants of operators in the evolutionary algorithm
 *    - size of the population
 *    - parameters of the fitness function
 *    - parameters of road generation algorithm
 *    - etc.
 *
 * Then, the user can start simulation and generations of cars traversing random roads.
 * After the end of each generation, the cars evolve and the next, possibly better generation is created.
 * The user can see the model of the best car as well as its parameters.
 * The user can pause/resume, speed up/down and change colors in the simulation.
 *
 * \section Evolution
 * A specimen is a vector of real numbers representing a car
 *  - positions of car chassis vertices (it is made up of 8 traingles)
 *  - size of wheels
 *  - density of wheels
 *
 * The evolutionary algorithm is based on the following operators:
 *  - reproduction
 *     - proportional
 *     - tournament
 *     - random
 *  - crossover
 *     - two-point
 *     - none
 *  - mutation
 *     - gaussian
 *     - none
 *  - succession
 *     - generational
 *     - elitist
 */
