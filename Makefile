CXX = g++
CXXFLAGS = -g -Iinclude

HEADERS = include/Student.h include/Helper.h
OBJECTS = source/Main.o source/Student.o source/Helper.o
SOURCES = source/Main.cpp source/Student.cpp source/Helper.cpp

EXEC = Student

$(EXEC): $(OBJECTS) 
	$(CXX) $(CXXFLAGS) $^ -o $@ 
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@
clean:
	rm source/*.o 