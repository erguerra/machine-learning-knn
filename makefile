all: k-nearest-neighbors

k-nearest-neighbors: main.o csvio.o knn.o distances.o
	g++ -o k-nearest-neighbors main.o csvio.o knn.o distances.o

main.o: src/main.cpp src/csvio.hpp src/knn.hpp
	g++ -o main.o src/main.cpp -c -W -Wall -ansi -pedantic -std=c++11 

csvio.o: src/csvio.cpp src/csvio.hpp
	g++ -o csvio.o src/csvio.cpp -c -W -Wall -ansi -pedantic -std=c++11

knn.o: src/knn.cpp src/knn.hpp src/distances.hpp
	g++ -o knn.o src/knn.cpp -c -W -Wall -ansi -pedantic -std=c++11

distances.o: src/distances.cpp src/distances.hpp
	g++ -o distances.o src/distances.cpp -c -W -Wall -ansi -pedantic -std=c++11

clean:
	rm -rf *.o *~ k-nearest-neighbors