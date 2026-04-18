CXX = g++
CXXFLAGS = -std=c++17 -Wall

RAYLIB_PATH = /home/smit/libs/raylib

INCLUDE = -I$(RAYLIB_PATH)/include
LIBS = -L$(RAYLIB_PATH)/lib -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

TARGET = SIGMA_DRAWING

SRC = main.cpp circle.cpp

all:
	$(CXX) $(SRC) $(CXXFLAGS) $(INCLUDE) $(LIBS) \
	-Wl,-rpath=$(RAYLIB_PATH)/lib \
	-o $(TARGET)
