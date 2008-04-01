## Process this file with automake to produce Makefile.in
## Created by Anjuta

SUBDIRS = src po \
	tests

bird_toastdocdir = ${prefix}/doc/bird-toast
bird_toastdoc_DATA = \
	README\
	COPYING\
	AUTHORS\
	ChangeLog\
	INSTALL\
	NEWS

EXTRA_DIST = $(bird_toastdoc_DATA)

INCLUDES = \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	`sdl-config --cflags` \
	`xml2-config --cflags` \
	`freetype-config --cflags`

bin_PROGRAMS = \
	birdtoast

birdtoast_SOURCES = \
	src/main.cxx\
	src/scene_globals.h\
	src/sys_globals.h \
	src/globals.h

AM_LDFLAGS = \
			`sdl-config --libs` \
			`xml2-config --libs` \
			`freetype-config --libs` \
			-lSDL_image -lGL \
			-L./src -lbt -lphysfs

# Copy all the spec files. Of cource, only one is actually used.
dist-hook:
	for specfile in *.spec; do \
		if test -f $$specfile; then \
			cp -p $$specfile $(distdir); \
		fi \
	done

