to generate test coverage:
- compile the program
```shell
  rm -rf ./build
  cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
  cmake --build build
```
- after files are created in ./bin/Debug:
- run 
```shell 
docs/create_coverage.sh
```