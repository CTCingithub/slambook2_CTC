#!/bin/bash

echo "Building and running Gauss-Newton iteration example..."

if [ -d "build" ]; then
    echo "Found existing build directory..."
    rm -rf build/
    mkdir build
else
    echo "No existing build directory found, creating one..."
    mkdir build
fi

rm -rf bin/
cd build/
echo "Building in $(pwd)"
cmake ..
make -j4

cd ..
echo "Running Gauss-Newton iteration example..."
bin/GaussNewtonExample
