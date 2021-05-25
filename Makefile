LIB_FLAGS = -Wall -lGL -lGLU -lglut -lGLEW -lglfw -lX11 -lXxf86vm -lXrandr -lpthread -lXi -ldl -lXinerama -lXcursor
SRC = main
.PHONY : clean

$(SRC) : $(SRC).cpp set_buffer.o shaders.o window.o options.o glad.o  opengl.h 
	g++ -o $(SRC) $(SRC).cpp set_buffer.o shaders.o window.o options.o glad.o $(LIB_FLAGS)

set_buffer.o : set_buffer.cpp
	g++ -c set_buffer.cpp $(LIB_FLAGS)

shaders.o : shaders.cpp opengl.h
	g++ -c shaders.cpp $(LIB_FLAGS)

window.o : window.cpp opengl.h
	g++ -c window.cpp $(LIB_FLAGS)

options.o : options.cpp opengl.h
	g++ -c options.cpp $(LIB_FLAGS)

glad.o : glad.c
	gcc -c glad.c



clean : 
	rm $(SRC) set_buffer.o shaders.o window.o options.o glad.o
