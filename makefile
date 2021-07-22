LFLAGS = -Wall -lGL -lGLU -lglut -lglad -lglfw -lGLEW -lX11 -lXrandr -lXxf86vm -lpthread -lXi -lXcursor -lXinerama -lstb_image

SRC = main
.PHONY : clean

$(SRC) : $(SRC).cpp shader.o shaderPrograms.o vertexInitializer.o rotator.o window.o camera.o
	g++ -o $(SRC) $(SRC).cpp shader.o shaderPrograms.o vertexInitializer.o rotator.o window.o camera.o $(LFLAGS)

shader.o : shader.cpp
	g++ -c shader.cpp

shaderPrograms.o : shaderPrograms.cpp
	g++ -c shaderPrograms.cpp

vertexInitializer.o:vertexInitializer.cpp
	g++ -c vertexInitializer.cpp

rotator.o : rotator.cpp
	g++ -c rotator.cpp

window.o : window.cpp
	g++ -c window.cpp

camera.o : camera.cpp
	g++ -c camera.cpp	

clean :
	rm $(SRC)