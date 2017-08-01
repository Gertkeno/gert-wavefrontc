echo "Building..."
cd build
g++ -c -Wall -std=gnu++14 -I../src ../src/*.cpp &&\
cd .. &&\
g++ -o wavefront_toc build/*.o &&\
echo "Done!"
