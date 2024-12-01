#!/bin/bash

echo "Building and running the trajectory error example"

if [ -d "build" ]; then
    echo "Found existing build directory..."
else
    echo "No existing build directory found, creating one..."
    mkdir build
fi

rm -rf bin/
cd build/
echo "Building in $(pwd)"
cmake ..
make -j4

cd ../bin/
echo "Running the trajectory error example..."
./traj_error
