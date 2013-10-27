# Compiler of your choosing
CC := g++

# Collects all the cpp files
SRC := $(wildcard *.cpp)

# Linker Options
LOPS := -lsfml-graphics -lsfml-window -lsfml-system -std=c++0x

# Executable name (without .exe!)
PROG := roh

#Dir where objects are stored
OBJDIR = obj

# For each cpp file the compiler will make a separate object
OBJS = $(SRC:.cpp=.o)

# Add a directory prefix to each object file
OUT_OBJS = $(addprefix $(OBJDIR)/, $(OBJS))


bin/roh: $(OUT_OBJS)
	g++ -o $@ $^ $(LOPS)

obj/%.o: %.cpp
	g++ -c $^ -o $@

.PHONY: clean
clean:
	del "obj\*" /Q
	del "bin\$(PROG).exe"
	make

# obj/main.o: main.cpp
# 	g++ -c $^ -o $@

# obj/gamestate.o: gamestate.cpp
# 	g++ -c gamestate.cpp -o obj/gamestate.o

# obj/gsGame.o: gsGame.cpp
# 	g++ -c $^ -o $@

# obj/gsMenu.o: gsMenu.cpp
# 	g++ -c $^ -o $@

# obj/globals.o: globals.cpp
# 	g++ -c $^ -o $@