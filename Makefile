CPPS = vec2.cpp vec3.cpp test.cpp
OBJS = vec2.o vec3.o test.o
CC = g++
CFLAGS = -Wall -g -DDENIG -fexceptions

test: $(OBJS)
	rm -f test
	$(CC) $(CFLAGS) $(OBJS) -o test

vec2.o: vec2.cpp vec2.h
	$(CC) $(CFLAGS) vec2.cpp -c

vec3.o: vec3.cpp vec3.h
	$(CC) $(CFLAGS) vec3.cpp -c

test.o: test.cpp vec2.h vec3.h
	$(CC) $(CFLAGS) test.cpp -c

clean:
	rm -rf *.o test
