LIB_FLAGS = -Wall -lglfw -lX11 -lXrandr -lpthread -ldl 
GTEST_FLAGS = -lgtest -lgtest_main 
SRC = main
.PHONY : clean 

$(SRC) : $(SRC).cpp set_buffer.o data.o shaders.o window.o options.o movement.o glad.o testing.o opengl.h
	g++ -o $(SRC) $(SRC).cpp set_buffer.o data.o shaders.o window.o options.o movement.o glad.o testing.o $(LIB_FLAGS) $(GTEST_FLAGS)

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

testing.o : testing.cpp opengl.h
	g++ -c testing.cpp



clean : 
	rm  set_buffer.o data.o shaders.o window.o options.o movement.o 
