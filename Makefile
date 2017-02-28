#GTK Makefile

all: ct
	
ct: cairo_tocta.c
	gcc `pkg-config --cflags gtk+-3.0` -o ct cairo_tocta.c `pkg-config --libs gtk+-3.0`
	

	
