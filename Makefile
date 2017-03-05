#GTK Makefile

all: ct
	
ct: cairo_tocta_2.c cairo_tocta_utils.c cairo_tocta.h
	gcc `pkg-config --cflags gtk+-3.0` -o ct2 cairo_tocta_2.c cairo_tocta_utils.c `pkg-config --libs gtk+-3.0`
	

	
