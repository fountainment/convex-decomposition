CPPS = vec2.cpp vec3.cpp segment.cpp polygon.cpp test.cpp
OBJS = vec2.o vec3.o segment.o polygon.o test.o
CC = g++
CFLAGS = -Wall -g -DDEBUG -fexceptions -std=c++11

test: $(OBJS)
	rm -f test
	$(CC) $(CFLAGS) $(OBJS) -o test

vec2.o: vec2.cpp vec2.h
	$(CC) $(CFLAGS) vec2.cpp -c

vec3.o: vec3.cpp vec3.h
	$(CC) $(CFLAGS) vec3.cpp -c

segment.o: segment.cpp segment.h vec2.h
	$(CC) $(CFLAGS) segment.cpp -c

polygon.o: polygon.cpp polygon.h vec2.h
	$(CC) $(CFLAGS) polygon.cpp -c

test.o: test.cpp vec2.h vec3.h segment.h polygon.h
	$(CC) $(CFLAGS) test.cpp -c

clean:
	rm -rf *.o test
