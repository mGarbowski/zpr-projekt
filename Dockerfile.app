FROM ubuntu:24.04

# Install dependencies
# Verify if all are actually needed
RUN apt update
RUN apt install -y build-essential
RUN apt install -y git
RUN apt install -y cmake
RUN apt install -y libsfml-dev


# Build
COPY src /app/src
COPY CMakeLists.txt /app/CMakeLists.txt
COPY cmake /app/cmake

WORKDIR /app

RUN cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
RUN cmake --build build

# Run
CMD ["./bin/Debug/app"]