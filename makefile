HEADERS = string.h
OBJECTS = main.o 
EXEC = Assignment3

$(EXEC): $(OBJECTS)
	g++ -Wall -std=c++11 $^ -o  $@

%.o: %.cpp $(HEADERS)
	g++ -Wall -c $< -o $@

run: $(EXEC)
	./$(EXEC) $(HEADERS) $(OBJECTS)
