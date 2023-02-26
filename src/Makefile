CXX := g++
CXXFLAGS := -std=c++11 -Wall -Werror -Wpedantic -Wextra
TARGETS := hello questions_3 ascii_image image_file four_square simple_squares_ascii hero flag_romania buck flag_columbia ppm_menu
OFILES := PPM.o Image.o controllers.o user_io.o image_drawing.o image_output.o ActionData.o MenuData.o image_filters.o NumberGrid.o ColorTable.o ComplexFractal.o JuliaSet.o MandelbrotSet.o ThreadedGrid.o Task.o BurningShip.o
LDFLAGS := -lpthread

# UNIT_TEST_WORKING_DIR=tmp/06 SRC_ROOT_DIR=$(pwd)/../cs-3005-ie-jhutchings99 make unit-test-06

all: $(TARGETS)

# BurningShip Class
BurningShip.o: BurningShip.cpp BurningShip.h
	$(CXX) $(CXXFLAGS) -c $<

# Task Class
Task.o: Task.cpp Task.h
	$(CXX) $(CXXFLAGS) -c $<

# ThreadedGrid
ThreadedGrid.o: ThreadedGrid.cpp ThreadedGrid.h
	$(CXX) $(CXXFLAGS) -c $<

# MandelbrotSet
MandelbrotSet.o: MandelbrotSet.cpp MandelbrotSet.h
	$(CXX) $(CXXFLAGS) -c $<

# JuliaSet
JuliaSet.o: JuliaSet.cpp JuliaSet.h
	$(CXX) $(CXXFLAGS) -c $<

# ComplexFractal
ComplexFractal.o: ComplexFractal.cpp ComplexFractal.h
	$(CXX) $(CXXFLAGS) -c $<

# ColorTable
ColorTable.o: ColorTable.cpp ColorTable.h
	$(CXX) $(CXXFLAGS) -c $<

# NumberGrid
NumberGrid.o: NumberGrid.cpp NumberGrid.h
	$(CXX) $(CXXFLAGS) -c $<


# Image Filters
image_filters.o: image_filters.cpp image_menu.h
	$(CXX) $(CXXFLAGS) -c $<


# PPM Menu
ppm_menu: ppm_menu.o $(OFILES) 
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

ppm_menu.o: ppm_menu.cpp image_menu.h
	$(CXX) $(CXXFLAGS) -c $<


# Action and Menu data
ActionData.o: ActionData.cpp image_menu.h
	$(CXX) $(CXXFLAGS) -c $<

MenuData.o: MenuData.cpp image_menu.h
	$(CXX) $(CXXFLAGS) -c $<


# BUCK EXAM 1
buck: buck.o $(OFILES)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

buck.o: buck.cpp image_menu.h
	$(CXX) $(CXXFLAGS) -c $<


# ROMANIA FLAG EXAM 1
flag_romania:  flag_romania.o $(OFILES)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

flag_romania.o: flag_romania.cpp image_menu.h
	$(CXX) $(CXXFLAGS) -c $<


# COLUMBIA FLAG EXAM 1
flag_columbia: flag_columbia.o $(OFILES)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

flag_columbia.o: flag_columbia.cpp image_menu.h
	$(CXX) $(CXXFLAGS) -c $<


# FOUR SQUARE EXAM 1 REVIEW
four_square: four_square.o $(OFILES)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

four_square.o: four_square.cpp image_menu.h
	$(CXX) $(CXXFLAGS) -c $<


# SIMPLE SQUARES EXAM 1 REVIEW
simple_squares_ascii: simple_squares_ascii.o $(OFILES)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

simple_squares_ascii.o: simple_squares_ascii.cpp image_menu.h
	$(CXX) $(CXXFLAGS) -c $<


# HERO EXAM 1 REVIEW
hero: hero.o $(OFILES)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

hero.o: hero.cpp image_menu.h
	$(CXX) $(CXXFLAGS) -c $<


#  IMAGE FILE 
image_file: image_file.o $(OFILES)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

image_file.o: image_file.cpp image_menu.h
	$(CXX) $(CXXFLAGS) -c $<

PPM.o: PPM.cpp PPM.h image_menu.h
	$(CXX) $(CXXFLAGS) -c $<


# ASCII IMAGE
ascii_image: ascii_image.o $(OFILES)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

Image.o: Image.cpp image_menu.h
	$(CXX) $(CXXFLAGS) -c $<

image_drawing.o: image_drawing.cpp image_menu.h
	$(CXX) $(CXXFLAGS) -c $<

ascii_image.o: ascii_image.cpp image_menu.h
	$(CXX) $(CXXFLAGS) -c $<

image_output.o: image_output.cpp image_menu.h
	$(CXX) $(CXXFLAGS) -c $<


# QUESTIONS 3
questions_3: questions_3.o $(OFILES)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

questions_3.o: questions_3.cpp image_menu.h
	$(CXX) $(CXXFLAGS) -c $<

user_io.o: user_io.cpp image_menu.h
	$(CXX) $(CXXFLAGS) -c $<

controllers.o: controllers.cpp image_menu.h
	$(CXX) $(CXXFLAGS) -c $<


# HELLO
hello: hello.o
	$(CXX) $(CXXFLAGS) -o $@ $^

hello.o: hello.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	-rm -f *.o *~ *.ppm $(TARGETS)