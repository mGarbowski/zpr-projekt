FROM ubuntu:24.04

# Install dependencies
# Verify if all are actually needed
RUN apt update
RUN apt install -y build-essential
RUN apt install -y git
RUN apt install -y cmake
RUN apt install -y libwayland-dev
RUN apt install -y libxkbcommon-dev
RUN apt install -y libxrandr-dev
RUN apt install -y libxinerama-dev
RUN apt install -y libxcursor-dev
RUN apt install -y libxi-dev
RUN apt install -y pkg-config
RUN apt install -y libgl-dev
RUN apt install -y lcov

# from https://github.com/micromouseonline/cmake-sfml-imgui-project
RUN apt install -y libxcursor-dev
RUN apt install -y libudev-dev
RUN apt install -y libfreetype-dev
RUN apt install -y libopenal-dev
RUN apt install -y libflac-dev
RUN apt install -y libvorbis-dev
RUN apt install -y libgl1-mesa-dev
RUN apt install -y libegl1-mesa-dev

# Build
COPY src /app/src
COPY CMakeLists.txt /app/CMakeLists.txt
COPY cmake /app/cmake

WORKDIR /app

RUN cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
RUN cmake --build build

# Run
CMD ["ctest", "--test-dir", "build"]