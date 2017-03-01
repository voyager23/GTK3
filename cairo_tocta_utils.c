/*
 * cairo_tocta_utils.c
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


#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

#include "cairo_tocta.h"

void draw_line(cairo_t *cr, tSide *s, char *text) {
	// set_source_rgb
	cairo_set_source_rgb (cr, s->r, s->g, s->b);
		
	// set_line_width
	cairo_set_line_width (cr, s->weight);
	
	// move_to start of line
	cairo_move_to(cr, s->x1, s->y1);
		
	// line_to
	cairo_line_to(cr, s->x2, s->y2);
	
	// stroke
	cairo_stroke(cr);
	
	// move_to text position
	cairo_move_to(cr, s->tx, s->ty);
	
	// set_font_face
	cairo_select_font_face(cr, "Liberation Sans",
      CAIRO_FONT_SLANT_ITALIC,
      CAIRO_FONT_WEIGHT_NORMAL);
	
	// set_font_size
	cairo_set_font_size(cr, s->font_size);
	
	// show_text
	cairo_show_text(cr, text);
	
}


