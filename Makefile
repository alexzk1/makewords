makewords: main.cpp
	$(CXX) ${CXXFLAGS} -o makewords -lstdc++ main.cpp
	
clean:
	rm makewords
