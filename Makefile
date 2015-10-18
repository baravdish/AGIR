CXX 		= g++
LINK 		= g++
CFLAGS 	= -g -Wall -W
LFLAGS 	= 
LIBS 		= 
INCPATH 	= -Isrc/math/  -Isrc/objects -Isrc/
OBJ_DIR 	= obj
SRC_DIR 	= src
DESTDIR 	= .
TARGET 	= raytracer
FILES 		= main.cpp \
		box.cpp \
		material.cpp \
		ray.cpp \
		scene.cpp \
		system.cpp \
		objects/object.cpp \
		objects/plane.cpp \
		objects/rectangle.cpp \
		objects/sphere.cpp \
		math/direction.cpp \
		math/mathstool.cpp \
		math/matrix.cpp \
		math/point.cpp \
		math/vector.cpp 
SRC 		= $(addprefix src/, $(FILES))
OBJ 		= $(addprefix obj/, $(FILES:.cpp=.o))

all: $(TARGET)

$(TARGET): $(OBJ)
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJ) $(LIBS)

obj/%.o: src/%.cpp
	@mkdir -p $(dir $(subst src, obj, $@))
	$(CXX) -c $(CFLAGS) $(INCPATH) $< -o  $(subst src, obj, $@)

.PHONY: clean

clean:
	rm -rf obj






