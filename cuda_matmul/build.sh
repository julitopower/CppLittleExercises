mkdir -p build
cd build
cmake .. -DCMAKE_CUDA_ARCHITECTURES=52 -DCMAKE_CUDA_HOST_COMPILER="/usr/bin/g++72"
make -j4
./app 1000 200 200 500
