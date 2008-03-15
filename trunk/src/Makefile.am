## Process this file with automake to produce Makefile.in

## Created by Anjuta

INCLUDES = \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" 

AM_CFLAGS =\
	 -Wall\
	 -g\
	 `sdl-config --cflags`

AM_LDFLAGS = `sdl-config --libs` -lSDL_image

bin_PROGRAMS = \
	birdtoast

birdtoast_SOURCES = \
	animation.cpp\
	gamescreen.cpp \
	gamescreen.h \
	globals.h \
	gui.h \
	gui_button.cpp \
	gui_element.cpp \
	image.cpp \
	image.h \
	input.h \
	main.cpp \
	physics.h \
	sprite.cpp \
	sprite.h \
	tileengine.h \
	tile_engine.cpp \
	vector.cpp
