makewords: main.cpp
	$(CC) --std=c++11 -march=native -o makewords -lstdc++ main.cpp
	
clean:
	rm makewords
