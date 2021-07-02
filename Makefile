LIB_FLAGS = -Wall -lglfw -lX11 -lXrandr -lpthread -ldl 
SRC = main
.PHONY : clean

$(SRC) : $(SRC).cpp set_buffer.o data.o shaders.o window.o options.o movement.o glad.o  opengl.h 
	g++ -o $(SRC) $(SRC).cpp set_buffer.o data.o shaders.o window.o options.o movement.o glad.o $(LIB_FLAGS)

set_buffer.o : set_buffer.cpp opengl.h
	g++ -c set_buffer.cpp $(LIB_FLAGS)

data.o : data.cpp opengl.h
	g++ -c data.cpp $(LIB_FLAGS)

shaders.o : shaders.cpp opengl.h
	g++ -c shaders.cpp $(LIB_FLAGS)

window.o : window.cpp opengl.h
	g++ -c window.cpp $(LIB_FLAGS)

options.o : options.cpp opengl.h
	g++ -c options.cpp $(LIB_FLAGS)

movement.o : movement.cpp opengl.h
	g++ -c movement.cpp $(LIB_FLAGS)

glad.o : glad.c
	gcc -c glad.c



clean : 
	rm $(SRC) set_buffer.o data.o shaders.o window.o options.o movement.o glad.o
