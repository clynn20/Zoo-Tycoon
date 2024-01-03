CC = g++ -std=c++11
exe_file = zootycoon
$(exe_file): zoo.o animal.o sealion.o tiger.o bear.o driver.o
		$(CC) -g zoo.o animal.o sealion.o tiger.o bear.o driver.o -o $(exe_file)
zoo.o: zoo.cpp
		$(CC) -c zoo.cpp
animal.o: animal.cpp
		$(CC) -c animal.cpp
sealion.o: sealion.cpp
		$(CC) -c sealion.cpp
tiger.o: tiger.cpp
		$(CC) -c tiger.cpp
bear.o: bear.cpp
		$(CC) -c bear.cpp
driver.o: driver.cpp
		$(CC) -c driver.cpp
clean:
		rm -f *.out *.o *.gch $(exe_file)
