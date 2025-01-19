to generate test coverage:
- compile the program
```shell
  rm -rf ./build
  cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
  cmake --build build
```
- run all tests: 
```shell
./bin/Debug/app_tests;
./bin/Debug/common_tests;
./bin/Debug/evolution_tests;
./bin/Debug/road_tests;
./bin/Debug/simulation_tests
```
- run 
```shell 
./docs/create-coverage.sh 
```