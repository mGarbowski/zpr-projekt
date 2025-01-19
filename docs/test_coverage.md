to generate test coverage:
- delete the ./bin directory
- compile the program
```shell
  rm -rf ./build
  cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
  cmake --build build
```
- run all tests:
```shell
ctest --test-dir build
```
- run 
```shell 
./docs/create-coverage.sh 
```