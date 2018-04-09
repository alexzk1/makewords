makewords: main.cpp
	$(CXX) ${CXXFLAGS} --std=c++11 -o makewords -licuuc -licuio -lstdc++ main.cpp
	
clean:
	rm makewords
