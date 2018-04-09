makewords: main.cpp
	$(CXX) ${CXXFLAGS} -O3 -o makewords -lstdc++ main.cpp
	
clean:
	rm makewords
