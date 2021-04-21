CXX       := g++
CXX_FLAGS := -std=c++17 -ggdb -lstdc++ -lstdc++fs 

BIN     := bin
SRC     := src
INCLUDE := include

LIBRARIES   := 
EXECUTABLE  := main


all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp main.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) $^ -o $@ $(LIBRARIES)
	$(BIN)/$(EXECUTABLE)

clean:
	del /q $(BIN)
	