HEADERS = Student.h Helper.h
OBJECTS = $(HEADERS:.h=.o)
MAINSOURCE = Main.cpp
MAINOBJ = $(MAINSOURCE:.cpp=.o)
EXEC = Student

$(EXEC): $(OBJECTS) $(MAINOBJ)
	g++ -g $^ -o $@ 
%.o: %.cpp $(Headers)
	g++ -g -c $< -o $@
clean:
	rm *.o 