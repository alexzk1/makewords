makewords: main.cpp
	$(CXX) ${CXXFLAGS} -o makewords -licuuc -licuio -lstdc++ main.cpp
	
clean:
	rm makewords
