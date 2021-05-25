LIB_FLAGS = -Wall -lGL -lGLU -lglut -lGLEW -lglfw -lX11 -lXxf86vm -lXrandr -lpthread -lXi -ldl -lXinerama -lXcursor
SRC = main
.PHONY : clean

$(SRC) : $(SRC).cpp data.o shaders.o window.o options.o glad.o  opengl.h 
	g++ -o $(SRC) $(SRC).cpp data.o shaders.o window.o options.o glad.o $(LIB_FLAGS)

data.o : data.cpp
	g++ -c data.cpp $(LIB_FLAGS)

shaders.o : shaders.cpp opengl.h
	g++ -c shaders.cpp $(LIB_FLAGS)

window.o : window.cpp opengl.h
	g++ -c window.cpp $(LIB_FLAGS)

options.o : options.cpp opengl.h
	g++ -c options.cpp $(LIB_FLAGS)

glad.o : glad.c
	gcc -c glad.c



clean : 
	rm $(SRC) data.o shaders.o window.o options.o glad.o
