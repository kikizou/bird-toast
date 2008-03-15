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
	tileenginetest

tileenginetest_SOURCES = \
	tileenginetest.cxx\
	../src/animation.cpp \
	../src/gamescreen.cpp \
	../src/gamescreen.h \
	../src/globals.h \
	../src/gui.h \
	../src/gui_button.cpp \
	../src/gui_element.cpp \
	../src/image.cpp \
	../src/image.h \
	../src/input.h \
	../src/physics.h \
	../src/sprite.cpp \
	../src/sprite.h \
	../src/tileengine.h \
	../src/tile_engine.cpp \
	../src/vector.cpp

tileenginetest_CXXFLAGS = \
	-I../src

## File created by the gnome-build tools

