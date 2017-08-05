echo "Building..."
mkdir build
cd build
g++ -c -Wall -std=gnu++11 -I../src ../src/*.cpp &&\
cd .. &&\
g++ -o gert-wavefrontc build/*.o &&\
echo "Done!"
