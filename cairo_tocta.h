/*
 * cairo_tocta.h
 * 
 * Copyright 2017 mike <mike@sedawk>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */
 
#ifndef __CAIRO_TOCTA__
#define __CAIRO_TOCTA__

	#define WIDTH  480.0
	#define HEIGHT 480.0
	
	typedef struct side {
		// Define line co-ords, weight and color
		double x1,y1,x2,y2;
		double weight;
		double r,g,b;
		// Define text position, font_size and contents
		double tx,ty;
		double font_size;
	}tSide;

	void draw_line(cairo_t *cr, tSide *s, char *text);

#endif
