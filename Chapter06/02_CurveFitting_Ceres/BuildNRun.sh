#!/bin/bash

# clear
echo "Building and running Ceres Optimization example..."

if [ -d "build" ]; then
    echo "Found existing build directory..."
    rm -rf build/
else
    echo "No existing build directory found, creating one..."
fi
mkdir build

rm -rf bin/
cd build/
echo "Building in $(pwd)"
cmake ..
make -j4

cd ..
echo "Running Ceres Optimization example..."
bin/CeresExample
