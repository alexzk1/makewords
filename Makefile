makewords: main.cpp
	$(CC) ${CXXFLAGS} -O3 -o makewords -lstdc++ main.cpp
	
clean:
	rm makewords
