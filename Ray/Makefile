TARGET = Ray
SOURCE = GLSLProgram.cpp mouse.cpp mouse.cpp camera.cpp cone.todo.cpp directionalLight.cpp shapeList.cpp pointLight.cpp scene.todo.cpp spotLight.cpp triangle.todo.cpp box.cpp camera.todo.cpp cylinder.cpp directionalLight.todo.cpp shapeList.todo.cpp pointLight.todo.cpp sphereLight.cpp sphereLight.todo.cpp sphere.cpp spotLight.todo.cpp window.cpp box.todo.cpp cone.cpp cylinder.todo.cpp fileInstance.cpp scene.cpp sphere.todo.cpp triangle.cpp shape.cpp torus.cpp torus.todo.cpp

TARGET_LIB = lib$(TARGET).a

CFLAGS += -I. -I.. -Wunused-result -g
CPPFLAGS += -I. -I.. -std=c++20 -Wunused-result

CPPFLAGS_DEBUG = -DDEBUG -g3 -g
CPPFLAGS_RELEASE = -O3 -DRELEASE -funroll-loops -ffast-math -DNDEBUG

SRC = ./
BIN = ../
BIN_O = ../Bin/Linux/Release/$(TARGET)/
INCLUDE = /usr/include/

CC  = gcc
CXX = g++
MD  = mkdir
AR  = ar

OBJECTS=$(addprefix $(BIN_O), $(addsuffix .o, $(basename $(SOURCE))))

all: CFLAGS += $(CFLAGS_RELEASE)
all: CPPFLAGS += $(CFLAGS_RELEASE)
all: $(BIN)
all: $(BIN_O)
all: $(BIN)$(TARGET_LIB)

debug: CFLAGS += $(CPPFLAGS_DEBUG)
debug: CPPFLAGS += $(CPPFLAGS_DEBUG)
debug: $(BIN)
debug: $(BIN)$(TARGET_LIB)

clean:
	rm -f $(BIN)$(TARGET_LIB)
	rm -f $(OBJECTS)

depend:
	makedepend -- $(CFLAGS) -- -I../SVD -I../Util -I../Image -Y $(SOURCE)

$(BIN):
	$(MD) -p $(BIN)

$(BIN_O):
	$(MD) -p $(BIN_O)

$(BIN)$(TARGET_LIB): $(OBJECTS)
	$(AR) rcs $@ $(OBJECTS)

$(BIN_O)%.o: $(SRC)%.c
	$(CC) -c -o $@ $(CFLAGS) -I$(INCLUDE) $<

$(BIN_O)%.o: $(SRC)%.cpp
	$(CXX) -c -o $@ $(CPPFLAGS) -I$(INCLUDE) $<
	
# DO NOT DELETE

GLSLProgram.o: ../Util/exceptions.h GLSLProgram.h ../GL/glew.h
mouse.o: mouse.h ../Util/geometry.h ../Util/algebra.h ../Util/geometry.inl
mouse.o: ../SVD/SVDFit.h ../SVD/MatrixMNTC.h ../SVD/MatrixMNTC.inl
mouse.o: ../SVD/SVD.h ../SVD/SVD.inl ../SVD/SVDFit.inl ../SVD/MatrixMNTC.h
mouse.o: ../Util/exceptions.h ../Util/geometry.todo.inl ../GL/glew.h
mouse.o: ../GL/glut.h
mouse.o: mouse.h ../Util/geometry.h ../Util/algebra.h ../Util/geometry.inl
mouse.o: ../SVD/SVDFit.h ../SVD/MatrixMNTC.h ../SVD/MatrixMNTC.inl
mouse.o: ../SVD/SVD.h ../SVD/SVD.inl ../SVD/SVDFit.inl ../SVD/MatrixMNTC.h
mouse.o: ../Util/exceptions.h ../Util/geometry.todo.inl ../GL/glew.h
mouse.o: ../GL/glut.h
camera.o: ../Util/exceptions.h shape.h ../Util/geometry.h ../Util/algebra.h
camera.o: ../Util/geometry.inl ../SVD/SVDFit.h ../SVD/MatrixMNTC.h
camera.o: ../SVD/MatrixMNTC.inl ../SVD/SVD.h ../SVD/SVD.inl ../SVD/SVDFit.inl
camera.o: ../SVD/MatrixMNTC.h ../Util/geometry.todo.inl ../Util/factory.h
camera.o: ../GL/glew.h ../GL/glut.h GLSLProgram.h camera.h
cone.todo.o: ../Util/exceptions.h ../Util/polynomial.h ../Util/geometry.h
cone.todo.o: ../Util/algebra.h ../Util/geometry.inl ../SVD/SVDFit.h
cone.todo.o: ../SVD/MatrixMNTC.h ../SVD/MatrixMNTC.inl ../SVD/SVD.h
cone.todo.o: ../SVD/SVD.inl ../SVD/SVDFit.inl ../SVD/MatrixMNTC.h
cone.todo.o: ../Util/geometry.todo.inl ../Util/polynomial.inl
cone.todo.o: ../Util/poly34.h scene.h ../Image/image.h
cone.todo.o: ../Image/lineSegments.h shape.h ../Util/factory.h ../GL/glew.h
cone.todo.o: ../GL/glut.h GLSLProgram.h light.h shapeList.h keyFrames.h
cone.todo.o: ../Util/interpolation.h ../Util/interpolation.todo.inl
cone.todo.o: keyFrames.inl camera.h scene.inl cone.h
directionalLight.o: ../Util/geometry.h ../Util/algebra.h ../Util/geometry.inl
directionalLight.o: ../SVD/SVDFit.h ../SVD/MatrixMNTC.h ../SVD/MatrixMNTC.inl
directionalLight.o: ../SVD/SVD.h ../SVD/SVD.inl ../SVD/SVDFit.inl
directionalLight.o: ../SVD/MatrixMNTC.h ../Util/exceptions.h
directionalLight.o: ../Util/geometry.todo.inl directionalLight.h light.h
directionalLight.o: shape.h ../Util/factory.h ../GL/glew.h ../GL/glut.h
directionalLight.o: GLSLProgram.h
shapeList.o: ../Util/exceptions.h triangle.h ../Util/geometry.h
shapeList.o: ../Util/algebra.h ../Util/geometry.inl ../SVD/SVDFit.h
shapeList.o: ../SVD/MatrixMNTC.h ../SVD/MatrixMNTC.inl ../SVD/SVD.h
shapeList.o: ../SVD/SVD.inl ../SVD/SVDFit.inl ../SVD/MatrixMNTC.h
shapeList.o: ../Util/geometry.todo.inl ../Util/polynomial.h
shapeList.o: ../Util/polynomial.inl ../Util/poly34.h shape.h
shapeList.o: ../Util/factory.h ../GL/glew.h ../GL/glut.h GLSLProgram.h
shapeList.o: scene.h ../Image/image.h ../Image/lineSegments.h light.h
shapeList.o: shapeList.h keyFrames.h ../Util/interpolation.h
shapeList.o: ../Util/interpolation.todo.inl keyFrames.inl camera.h scene.inl
pointLight.o: ../Util/exceptions.h ../Util/geometry.h ../Util/algebra.h
pointLight.o: ../Util/geometry.inl ../SVD/SVDFit.h ../SVD/MatrixMNTC.h
pointLight.o: ../SVD/MatrixMNTC.inl ../SVD/SVD.h ../SVD/SVD.inl
pointLight.o: ../SVD/SVDFit.inl ../SVD/MatrixMNTC.h ../Util/geometry.todo.inl
pointLight.o: pointLight.h light.h shape.h ../Util/factory.h ../GL/glew.h
pointLight.o: ../GL/glut.h GLSLProgram.h
scene.todo.o: ../Util/exceptions.h scene.h ../Util/geometry.h
scene.todo.o: ../Util/algebra.h ../Util/geometry.inl ../SVD/SVDFit.h
scene.todo.o: ../SVD/MatrixMNTC.h ../SVD/MatrixMNTC.inl ../SVD/SVD.h
scene.todo.o: ../SVD/SVD.inl ../SVD/SVDFit.inl ../SVD/MatrixMNTC.h
scene.todo.o: ../Util/geometry.todo.inl ../Image/image.h
scene.todo.o: ../Image/lineSegments.h shape.h ../Util/factory.h ../GL/glew.h
scene.todo.o: ../GL/glut.h GLSLProgram.h light.h shapeList.h keyFrames.h
scene.todo.o: ../Util/interpolation.h ../Util/interpolation.todo.inl
scene.todo.o: keyFrames.inl camera.h scene.inl
spotLight.o: ../Util/exceptions.h ../Util/geometry.h ../Util/algebra.h
spotLight.o: ../Util/geometry.inl ../SVD/SVDFit.h ../SVD/MatrixMNTC.h
spotLight.o: ../SVD/MatrixMNTC.inl ../SVD/SVD.h ../SVD/SVD.inl
spotLight.o: ../SVD/SVDFit.inl ../SVD/MatrixMNTC.h ../Util/geometry.todo.inl
spotLight.o: spotLight.h light.h shape.h ../Util/factory.h ../GL/glew.h
spotLight.o: ../GL/glut.h GLSLProgram.h scene.h ../Image/image.h
spotLight.o: ../Image/lineSegments.h shapeList.h keyFrames.h
spotLight.o: ../Util/interpolation.h ../Util/interpolation.todo.inl
spotLight.o: keyFrames.inl camera.h scene.inl
triangle.todo.o: ../Util/exceptions.h triangle.h ../Util/geometry.h
triangle.todo.o: ../Util/algebra.h ../Util/geometry.inl ../SVD/SVDFit.h
triangle.todo.o: ../SVD/MatrixMNTC.h ../SVD/MatrixMNTC.inl ../SVD/SVD.h
triangle.todo.o: ../SVD/SVD.inl ../SVD/SVDFit.inl ../SVD/MatrixMNTC.h
triangle.todo.o: ../Util/geometry.todo.inl ../Util/polynomial.h
triangle.todo.o: ../Util/polynomial.inl ../Util/poly34.h shape.h
triangle.todo.o: ../Util/factory.h ../GL/glew.h ../GL/glut.h GLSLProgram.h
triangle.todo.o: scene.h ../Image/image.h ../Image/lineSegments.h light.h
triangle.todo.o: shapeList.h keyFrames.h ../Util/interpolation.h
triangle.todo.o: ../Util/interpolation.todo.inl keyFrames.inl camera.h
triangle.todo.o: scene.inl
box.o: ../Util/exceptions.h box.h ../Util/geometry.h ../Util/algebra.h
box.o: ../Util/geometry.inl ../SVD/SVDFit.h ../SVD/MatrixMNTC.h
box.o: ../SVD/MatrixMNTC.inl ../SVD/SVD.h ../SVD/SVD.inl ../SVD/SVDFit.inl
box.o: ../SVD/MatrixMNTC.h ../Util/geometry.todo.inl shape.h
box.o: ../Util/factory.h ../GL/glew.h ../GL/glut.h GLSLProgram.h scene.h
box.o: ../Image/image.h ../Image/lineSegments.h light.h shapeList.h
box.o: keyFrames.h ../Util/interpolation.h ../Util/interpolation.todo.inl
box.o: keyFrames.inl camera.h scene.inl
camera.todo.o: ../Util/exceptions.h camera.h ../Util/geometry.h
camera.todo.o: ../Util/algebra.h ../Util/geometry.inl ../SVD/SVDFit.h
camera.todo.o: ../SVD/MatrixMNTC.h ../SVD/MatrixMNTC.inl ../SVD/SVD.h
camera.todo.o: ../SVD/SVD.inl ../SVD/SVDFit.inl ../SVD/MatrixMNTC.h
camera.todo.o: ../Util/geometry.todo.inl shape.h ../Util/factory.h
camera.todo.o: ../GL/glew.h ../GL/glut.h GLSLProgram.h
cylinder.o: ../Util/exceptions.h cylinder.h ../Util/geometry.h
cylinder.o: ../Util/algebra.h ../Util/geometry.inl ../SVD/SVDFit.h
cylinder.o: ../SVD/MatrixMNTC.h ../SVD/MatrixMNTC.inl ../SVD/SVD.h
cylinder.o: ../SVD/SVD.inl ../SVD/SVDFit.inl ../SVD/MatrixMNTC.h
cylinder.o: ../Util/geometry.todo.inl ../Util/polynomial.h
cylinder.o: ../Util/polynomial.inl ../Util/poly34.h shape.h ../Util/factory.h
cylinder.o: ../GL/glew.h ../GL/glut.h GLSLProgram.h scene.h ../Image/image.h
cylinder.o: ../Image/lineSegments.h light.h shapeList.h keyFrames.h
cylinder.o: ../Util/interpolation.h ../Util/interpolation.todo.inl
cylinder.o: keyFrames.inl camera.h scene.inl
directionalLight.todo.o: ../Util/exceptions.h directionalLight.h light.h
directionalLight.todo.o: shape.h ../Util/geometry.h ../Util/algebra.h
directionalLight.todo.o: ../Util/geometry.inl ../SVD/SVDFit.h
directionalLight.todo.o: ../SVD/MatrixMNTC.h ../SVD/MatrixMNTC.inl
directionalLight.todo.o: ../SVD/SVD.h ../SVD/SVD.inl ../SVD/SVDFit.inl
directionalLight.todo.o: ../SVD/MatrixMNTC.h ../Util/geometry.todo.inl
directionalLight.todo.o: ../Util/factory.h ../GL/glew.h ../GL/glut.h
directionalLight.todo.o: GLSLProgram.h scene.h ../Image/image.h
directionalLight.todo.o: ../Image/lineSegments.h shapeList.h keyFrames.h
directionalLight.todo.o: ../Util/interpolation.h
directionalLight.todo.o: ../Util/interpolation.todo.inl keyFrames.inl
directionalLight.todo.o: camera.h scene.inl
shapeList.todo.o: ../Util/exceptions.h ../Util/threads.h ../Util/exceptions.h
shapeList.todo.o: shapeList.h ../Util/geometry.h ../Util/algebra.h
shapeList.todo.o: ../Util/geometry.inl ../SVD/SVDFit.h ../SVD/MatrixMNTC.h
shapeList.todo.o: ../SVD/MatrixMNTC.inl ../SVD/SVD.h ../SVD/SVD.inl
shapeList.todo.o: ../SVD/SVDFit.inl ../SVD/MatrixMNTC.h
shapeList.todo.o: ../Util/geometry.todo.inl shape.h ../Util/factory.h
shapeList.todo.o: ../GL/glew.h ../GL/glut.h GLSLProgram.h triangle.h
shapeList.todo.o: ../Util/polynomial.h ../Util/polynomial.inl
shapeList.todo.o: ../Util/poly34.h scene.h ../Image/image.h
shapeList.todo.o: ../Image/lineSegments.h light.h keyFrames.h
shapeList.todo.o: ../Util/interpolation.h ../Util/interpolation.todo.inl
shapeList.todo.o: keyFrames.inl camera.h scene.inl
pointLight.todo.o: ../Util/exceptions.h pointLight.h light.h shape.h
pointLight.todo.o: ../Util/geometry.h ../Util/algebra.h ../Util/geometry.inl
pointLight.todo.o: ../SVD/SVDFit.h ../SVD/MatrixMNTC.h ../SVD/MatrixMNTC.inl
pointLight.todo.o: ../SVD/SVD.h ../SVD/SVD.inl ../SVD/SVDFit.inl
pointLight.todo.o: ../SVD/MatrixMNTC.h ../Util/geometry.todo.inl
pointLight.todo.o: ../Util/factory.h ../GL/glew.h ../GL/glut.h GLSLProgram.h
pointLight.todo.o: scene.h ../Image/image.h ../Image/lineSegments.h
pointLight.todo.o: shapeList.h keyFrames.h ../Util/interpolation.h
pointLight.todo.o: ../Util/interpolation.todo.inl keyFrames.inl camera.h
pointLight.todo.o: scene.inl
sphereLight.o: ../Util/exceptions.h ../Util/geometry.h ../Util/algebra.h
sphereLight.o: ../Util/geometry.inl ../SVD/SVDFit.h ../SVD/MatrixMNTC.h
sphereLight.o: ../SVD/MatrixMNTC.inl ../SVD/SVD.h ../SVD/SVD.inl
sphereLight.o: ../SVD/SVDFit.inl ../SVD/MatrixMNTC.h
sphereLight.o: ../Util/geometry.todo.inl sphereLight.h pointLight.h light.h
sphereLight.o: shape.h ../Util/factory.h ../GL/glew.h ../GL/glut.h
sphereLight.o: GLSLProgram.h scene.h ../Image/image.h ../Image/lineSegments.h
sphereLight.o: shapeList.h keyFrames.h ../Util/interpolation.h
sphereLight.o: ../Util/interpolation.todo.inl keyFrames.inl camera.h
sphereLight.o: scene.inl
sphereLight.todo.o: ../Util/exceptions.h scene.h ../Util/geometry.h
sphereLight.todo.o: ../Util/algebra.h ../Util/geometry.inl ../SVD/SVDFit.h
sphereLight.todo.o: ../SVD/MatrixMNTC.h ../SVD/MatrixMNTC.inl ../SVD/SVD.h
sphereLight.todo.o: ../SVD/SVD.inl ../SVD/SVDFit.inl ../SVD/MatrixMNTC.h
sphereLight.todo.o: ../Util/geometry.todo.inl ../Image/image.h
sphereLight.todo.o: ../Image/lineSegments.h shape.h ../Util/factory.h
sphereLight.todo.o: ../GL/glew.h ../GL/glut.h GLSLProgram.h light.h
sphereLight.todo.o: shapeList.h keyFrames.h ../Util/interpolation.h
sphereLight.todo.o: ../Util/interpolation.todo.inl keyFrames.inl camera.h
sphereLight.todo.o: scene.inl sphereLight.h pointLight.h
sphere.o: ../Util/exceptions.h sphere.h ../Util/geometry.h ../Util/algebra.h
sphere.o: ../Util/geometry.inl ../SVD/SVDFit.h ../SVD/MatrixMNTC.h
sphere.o: ../SVD/MatrixMNTC.inl ../SVD/SVD.h ../SVD/SVD.inl ../SVD/SVDFit.inl
sphere.o: ../SVD/MatrixMNTC.h ../Util/geometry.todo.inl ../Util/polynomial.h
sphere.o: ../Util/polynomial.inl ../Util/poly34.h shape.h ../Util/factory.h
sphere.o: ../GL/glew.h ../GL/glut.h GLSLProgram.h scene.h ../Image/image.h
sphere.o: ../Image/lineSegments.h light.h shapeList.h keyFrames.h
sphere.o: ../Util/interpolation.h ../Util/interpolation.todo.inl
sphere.o: keyFrames.inl camera.h scene.inl
spotLight.todo.o: ../Util/exceptions.h scene.h ../Util/geometry.h
spotLight.todo.o: ../Util/algebra.h ../Util/geometry.inl ../SVD/SVDFit.h
spotLight.todo.o: ../SVD/MatrixMNTC.h ../SVD/MatrixMNTC.inl ../SVD/SVD.h
spotLight.todo.o: ../SVD/SVD.inl ../SVD/SVDFit.inl ../SVD/MatrixMNTC.h
spotLight.todo.o: ../Util/geometry.todo.inl ../Image/image.h
spotLight.todo.o: ../Image/lineSegments.h shape.h ../Util/factory.h
spotLight.todo.o: ../GL/glew.h ../GL/glut.h GLSLProgram.h light.h shapeList.h
spotLight.todo.o: keyFrames.h ../Util/interpolation.h
spotLight.todo.o: ../Util/interpolation.todo.inl keyFrames.inl camera.h
spotLight.todo.o: scene.inl spotLight.h
window.o: window.h ../Util/timer.h ../Ray/mouse.h ../Util/geometry.h
window.o: ../Util/algebra.h ../Util/geometry.inl ../SVD/SVDFit.h
window.o: ../SVD/MatrixMNTC.h ../SVD/MatrixMNTC.inl ../SVD/SVD.h
window.o: ../SVD/SVD.inl ../SVD/SVDFit.inl ../SVD/MatrixMNTC.h
window.o: ../Util/exceptions.h ../Util/geometry.todo.inl ../Ray/scene.h
window.o: ../Image/image.h ../Image/lineSegments.h shape.h ../Util/factory.h
window.o: ../GL/glew.h ../GL/glut.h GLSLProgram.h light.h shapeList.h
window.o: keyFrames.h ../Util/interpolation.h ../Util/interpolation.todo.inl
window.o: keyFrames.inl camera.h scene.inl
box.todo.o: ../Util/exceptions.h scene.h ../Util/geometry.h ../Util/algebra.h
box.todo.o: ../Util/geometry.inl ../SVD/SVDFit.h ../SVD/MatrixMNTC.h
box.todo.o: ../SVD/MatrixMNTC.inl ../SVD/SVD.h ../SVD/SVD.inl
box.todo.o: ../SVD/SVDFit.inl ../SVD/MatrixMNTC.h ../Util/geometry.todo.inl
box.todo.o: ../Image/image.h ../Image/lineSegments.h shape.h
box.todo.o: ../Util/factory.h ../GL/glew.h ../GL/glut.h GLSLProgram.h light.h
box.todo.o: shapeList.h keyFrames.h ../Util/interpolation.h
box.todo.o: ../Util/interpolation.todo.inl keyFrames.inl camera.h scene.inl
box.todo.o: box.h
cone.o: ../Util/exceptions.h cone.h ../Util/geometry.h ../Util/algebra.h
cone.o: ../Util/geometry.inl ../SVD/SVDFit.h ../SVD/MatrixMNTC.h
cone.o: ../SVD/MatrixMNTC.inl ../SVD/SVD.h ../SVD/SVD.inl ../SVD/SVDFit.inl
cone.o: ../SVD/MatrixMNTC.h ../Util/geometry.todo.inl ../Util/polynomial.h
cone.o: ../Util/polynomial.inl ../Util/poly34.h shape.h ../Util/factory.h
cone.o: ../GL/glew.h ../GL/glut.h GLSLProgram.h scene.h ../Image/image.h
cone.o: ../Image/lineSegments.h light.h shapeList.h keyFrames.h
cone.o: ../Util/interpolation.h ../Util/interpolation.todo.inl keyFrames.inl
cone.o: camera.h scene.inl
cylinder.todo.o: ../Util/exceptions.h scene.h ../Util/geometry.h
cylinder.todo.o: ../Util/algebra.h ../Util/geometry.inl ../SVD/SVDFit.h
cylinder.todo.o: ../SVD/MatrixMNTC.h ../SVD/MatrixMNTC.inl ../SVD/SVD.h
cylinder.todo.o: ../SVD/SVD.inl ../SVD/SVDFit.inl ../SVD/MatrixMNTC.h
cylinder.todo.o: ../Util/geometry.todo.inl ../Image/image.h
cylinder.todo.o: ../Image/lineSegments.h shape.h ../Util/factory.h
cylinder.todo.o: ../GL/glew.h ../GL/glut.h GLSLProgram.h light.h shapeList.h
cylinder.todo.o: keyFrames.h ../Util/interpolation.h
cylinder.todo.o: ../Util/interpolation.todo.inl keyFrames.inl camera.h
cylinder.todo.o: scene.inl cylinder.h ../Util/polynomial.h
cylinder.todo.o: ../Util/polynomial.inl ../Util/poly34.h
fileInstance.o: fileInstance.h ../Util/geometry.h ../Util/algebra.h
fileInstance.o: ../Util/geometry.inl ../SVD/SVDFit.h ../SVD/MatrixMNTC.h
fileInstance.o: ../SVD/MatrixMNTC.inl ../SVD/SVD.h ../SVD/SVD.inl
fileInstance.o: ../SVD/SVDFit.inl ../SVD/MatrixMNTC.h ../Util/exceptions.h
fileInstance.o: ../Util/geometry.todo.inl shape.h ../Util/factory.h
fileInstance.o: ../GL/glew.h ../GL/glut.h GLSLProgram.h scene.h
fileInstance.o: ../Image/image.h ../Image/lineSegments.h light.h shapeList.h
fileInstance.o: keyFrames.h ../Util/interpolation.h
fileInstance.o: ../Util/interpolation.todo.inl keyFrames.inl camera.h
fileInstance.o: scene.inl
scene.o: ../Util/exceptions.h ../Util/cmdLineParser.h
scene.o: ../Util/cmdLineParser.inl ../Util/ProgressBar.h ../Util/timer.h
scene.o: ../Util/ProgressBar.inl ../Image/bmp.h ../Image/image.h
scene.o: ../Util/geometry.h ../Util/algebra.h ../Util/geometry.inl
scene.o: ../SVD/SVDFit.h ../SVD/MatrixMNTC.h ../SVD/MatrixMNTC.inl
scene.o: ../SVD/SVD.h ../SVD/SVD.inl ../SVD/SVDFit.inl ../SVD/MatrixMNTC.h
scene.o: ../Util/geometry.todo.inl ../Image/lineSegments.h scene.h
scene.o: ../Image/image.h shape.h ../Util/factory.h ../GL/glew.h ../GL/glut.h
scene.o: GLSLProgram.h light.h shapeList.h keyFrames.h
scene.o: ../Util/interpolation.h ../Util/interpolation.todo.inl keyFrames.inl
scene.o: camera.h scene.inl fileInstance.h ../Util/threads.h
scene.o: ../Util/exceptions.h
sphere.todo.o: ../Util/exceptions.h scene.h ../Util/geometry.h
sphere.todo.o: ../Util/algebra.h ../Util/geometry.inl ../SVD/SVDFit.h
sphere.todo.o: ../SVD/MatrixMNTC.h ../SVD/MatrixMNTC.inl ../SVD/SVD.h
sphere.todo.o: ../SVD/SVD.inl ../SVD/SVDFit.inl ../SVD/MatrixMNTC.h
sphere.todo.o: ../Util/geometry.todo.inl ../Image/image.h
sphere.todo.o: ../Image/lineSegments.h shape.h ../Util/factory.h ../GL/glew.h
sphere.todo.o: ../GL/glut.h GLSLProgram.h light.h shapeList.h keyFrames.h
sphere.todo.o: ../Util/interpolation.h ../Util/interpolation.todo.inl
sphere.todo.o: keyFrames.inl camera.h scene.inl sphere.h ../Util/polynomial.h
sphere.todo.o: ../Util/polynomial.inl ../Util/poly34.h
triangle.o: ../Util/exceptions.h triangle.h ../Util/geometry.h
triangle.o: ../Util/algebra.h ../Util/geometry.inl ../SVD/SVDFit.h
triangle.o: ../SVD/MatrixMNTC.h ../SVD/MatrixMNTC.inl ../SVD/SVD.h
triangle.o: ../SVD/SVD.inl ../SVD/SVDFit.inl ../SVD/MatrixMNTC.h
triangle.o: ../Util/geometry.todo.inl ../Util/polynomial.h
triangle.o: ../Util/polynomial.inl ../Util/poly34.h shape.h ../Util/factory.h
triangle.o: ../GL/glew.h ../GL/glut.h GLSLProgram.h scene.h ../Image/image.h
triangle.o: ../Image/lineSegments.h light.h shapeList.h keyFrames.h
triangle.o: ../Util/interpolation.h ../Util/interpolation.todo.inl
triangle.o: keyFrames.inl camera.h scene.inl
shape.o: shape.h ../Util/geometry.h ../Util/algebra.h ../Util/geometry.inl
shape.o: ../SVD/SVDFit.h ../SVD/MatrixMNTC.h ../SVD/MatrixMNTC.inl
shape.o: ../SVD/SVD.h ../SVD/SVD.inl ../SVD/SVDFit.inl ../SVD/MatrixMNTC.h
shape.o: ../Util/exceptions.h ../Util/geometry.todo.inl ../Util/factory.h
shape.o: ../GL/glew.h ../GL/glut.h GLSLProgram.h
torus.o: ../Util/exceptions.h torus.h ../Util/geometry.h ../Util/algebra.h
torus.o: ../Util/geometry.inl ../SVD/SVDFit.h ../SVD/MatrixMNTC.h
torus.o: ../SVD/MatrixMNTC.inl ../SVD/SVD.h ../SVD/SVD.inl ../SVD/SVDFit.inl
torus.o: ../SVD/MatrixMNTC.h ../Util/geometry.todo.inl ../Util/polynomial.h
torus.o: ../Util/polynomial.inl ../Util/poly34.h shape.h ../Util/factory.h
torus.o: ../GL/glew.h ../GL/glut.h GLSLProgram.h scene.h ../Image/image.h
torus.o: ../Image/lineSegments.h light.h shapeList.h keyFrames.h
torus.o: ../Util/interpolation.h ../Util/interpolation.todo.inl keyFrames.inl
torus.o: camera.h scene.inl
torus.todo.o: ../Util/exceptions.h scene.h ../Util/geometry.h
torus.todo.o: ../Util/algebra.h ../Util/geometry.inl ../SVD/SVDFit.h
torus.todo.o: ../SVD/MatrixMNTC.h ../SVD/MatrixMNTC.inl ../SVD/SVD.h
torus.todo.o: ../SVD/SVD.inl ../SVD/SVDFit.inl ../SVD/MatrixMNTC.h
torus.todo.o: ../Util/geometry.todo.inl ../Image/image.h
torus.todo.o: ../Image/lineSegments.h shape.h ../Util/factory.h ../GL/glew.h
torus.todo.o: ../GL/glut.h GLSLProgram.h light.h shapeList.h keyFrames.h
torus.todo.o: ../Util/interpolation.h ../Util/interpolation.todo.inl
torus.todo.o: keyFrames.inl camera.h scene.inl torus.h ../Util/polynomial.h
torus.todo.o: ../Util/polynomial.inl ../Util/poly34.h
