LIB_FLAGS = -Wall -lglfw -lX11 -lXrandr -lpthread -ldl 
SRC = main
.PHONY : clean

$(SRC) : $(SRC).cpp set_buffer.o data.o shaders.o window.o options.o movement.o glad.o  opengl.h 
	g++ -o $(SRC) $(SRC).cpp set_buffer.o data.o shaders.o window.o options.o movement.o glad.o $(LIB_FLAGS)

set_buffer.o : set_buffer.cpp opengl.h
	g++ -c set_buffer.cpp 

data.o : data.cpp opengl.h
	g++ -c data.cpp 

shaders.o : shaders.cpp opengl.h
	g++ -c shaders.cpp 

window.o : window.cpp opengl.h
	g++ -c window.cpp 

options.o : options.cpp opengl.h
	g++ -c options.cpp 

movement.o : movement.cpp opengl.h
	g++ -c movement.cpp 

glad.o : glad.c
	gcc -c glad.c



clean : 
	rm $(SRC) set_buffer.o data.o shaders.o window.o options.o movement.o 
