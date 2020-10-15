mkdir -p build
cd build
cmake .. -DCMAKE_CUDA_ARCHITECTURES=75 -DCMAKE_CUDA_HOST_COMPILER="/usr/bin/g++72"
make -j4
