LFLAGS = -Wall -lGL -lGLU -lglut -lglad -lglfw -lGLEW -lX11 -lXrandr -lXxf86vm -lpthread -lXi -lXcursor -lXinerama

SRC = main
.PHONY : clean

$(SRC) : $(SRC).cpp shader.o shaderPrograms.o vertexInitializer.o rotator.o window.o camera.o
	g++ -g -o $(SRC) $(SRC).cpp shader.o shaderPrograms.o vertexInitializer.o rotator.o window.o camera.o $(LFLAGS)

shader.o : shader.cpp
	g++ -g -c shader.cpp

shaderPrograms.o : shaderPrograms.cpp
	g++ -g -c shaderPrograms.cpp

vertexInitializer.o:vertexInitializer.cpp
	g++ -g  -c vertexInitializer.cpp

rotator.o : rotator.cpp
	g++ -g -c rotator.cpp

window.o : window.cpp
	g++ -g -c window.cpp

camera.o : camera.cpp
	g++ -g -c camera.cpp	

clean :
	rm $(SRC)