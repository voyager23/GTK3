/*
 * cairo_tocta_2.c
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
 * Use cairo to paint a surface
 * use gdk to import the surface as pixbuff
 * use gtkimage to display the pixbuf
 */

#include <stdlib.h>
#include <gtk/gtk.h>
#include "cairo_tocta.h"


// Define the 12 sides for drawing
tSide ab = {// line 
			.x1=0.0, .y1=(4.0 * HEIGHT/12.0),
			.x2=(5.0 * WIDTH/12.0), .y2=(4.0 * HEIGHT/12.0),
			.weight=2.0, .r=0.0, .g=0.0, .b=0.0,
			// text
			.tx=(2.0 * WIDTH / 12.0), .ty=(3.8 * HEIGHT / 12.0),
			.font_size=12.0};
			
tSide ae = {// line 
			.x1=0.0, .y1=(4.0 * HEIGHT/12.0), 
			.x2=(8.0 * WIDTH/12.0), .y2=(0.0),
			.weight=5.0, .r=1.0, .g=0.0, .b=0.0,
			// text
			.tx=(2.5*WIDTH/12.0), .ty=(2.0*HEIGHT/12.0), 
			.font_size=12.0};
			
tSide af = {// line 
			.x1=0.0, .y1=(4.0 * HEIGHT/12.0), 
			.x2=(4.0 * WIDTH/12.0), .y2=(12.0 * HEIGHT/12.0),
			.weight=5.0, .r=0.0, .g=0.0, .b=1.0,
			// text
			.tx=(2.0*WIDTH/12.0), .ty=(7.0*HEIGHT/12.0), .font_size=12.0};

tSide bc = {// line 
			.x1=(5.0 * WIDTH/12.0), .y1=(4.0 * HEIGHT/12.0), 
			.x2=(12.0 * WIDTH/12.0), .y2=(8.0 * HEIGHT/12.0),
			.weight=2.0, .r=0.0, .g=0.0, .b=0.0,
			// text
			.tx=(8.5 * WIDTH / 12.0), .ty=(5.6 * HEIGHT / 12.0), 
			.font_size=12.0};

tSide be = {// line 
			.x1=(5.0 * WIDTH/12.0), .y1=(4.0 * HEIGHT/12.0), 
			.x2=(8.0 * WIDTH/12.0), .y2=(0.0),
			.weight=2.0, .r=1.0, .g=0.0, .b=0.0,
			// text
			.tx=6.0*WIDTH/12.0, .ty=3.0*HEIGHT/12.0, .font_size=12.0};

tSide bf = {// line 
			.x1=(5.0 * WIDTH/12.0), .y1=(4.0 * HEIGHT/12.0), 
			.x2=(4.0 * WIDTH/12.0), .y2=(12.0*HEIGHT/12.0),
			.weight=2.0, .r=0.0, .g=0.0, .b=1.0,
			// text
			.tx=4.5*WIDTH/12.0, .ty=9.0*HEIGHT/12.0, .font_size=12.0};

tSide cd = {// line 
			.x1=(12.0 * WIDTH/12.0), .y1=(8.0 * HEIGHT/12.0), 
			.x2=(7.0 * WIDTH/12.0), .y2=(8.0 * HEIGHT/12.0),
			.weight=5.0, .r=0.0, .g=0.0, .b=0.0,
			// text
			.tx=(8.5 * WIDTH / 12.0), .ty=(7.8 * HEIGHT / 12.0), 
			.font_size=12.0};

tSide ce = {// line 
			.x1=(12.0 * WIDTH/12.0), .y1=(8.0 * HEIGHT/12.0), 
			.x2=(8.0 * WIDTH/12.0), .y2=(0.0),
			.weight=5.0, .r=1.0, .g=0.0, .b=0.0,
			// text
			.tx=(10.0*WIDTH/12.0), .ty=(3.0*HEIGHT/12.0), .font_size=12.0};

tSide cf = {// line 
			.x1=(12.0 * WIDTH/12.0), .y1=(8.0 * HEIGHT/12.0), 
			.x2=(4.0 * WIDTH/12.0), .y2=(12.0*HEIGHT/12.0),
			.weight=5.0, .r=0.0, .g=0.0, .b=1.0,
			// text
			.tx=(9.0*WIDTH/12.0), .ty=(10.0*HEIGHT/12.0), .font_size=12.0};

tSide da = {// line 
			.x1=(7.0 * WIDTH/12.0), .y1=(8.0 * HEIGHT/12.0), 
			.x2=0.0, .y2=(4.0*HEIGHT/12.0),
			.weight=5.0, .r=0.0, .g=0.0, .b=0.0,
			// text
			.tx=(3.1 * WIDTH / 12.0), .ty=(5.6 * HEIGHT / 12.0), 
			.font_size=12.0};

tSide de = {// line 
			.x1=(7.0 * WIDTH/12.0), .y1=(8.0 * HEIGHT/12.0), 
			.x2=(8.0*WIDTH/12.0), .y2=0.0,
			.weight=5.0, .r=1.0, .g=0.0, .b=0.0,
			// text
			.tx=8.0*WIDTH/12.0, .ty=4.0*HEIGHT/12.0, .font_size=12.0};

tSide df = {// line 
			.x1=(7.0 * WIDTH/12.0), .y1=(8.0 * HEIGHT/12.0), 
			.x2=4.0*WIDTH/12.0, .y2=(12.0*HEIGHT/12.0),
			.weight=5.0, .r=0.0, .g=0.0, .b=1.0,
			// text
			.tx=6.0*WIDTH/12.0, .ty=10.0*HEIGHT/12.0, .font_size=12.0};


static void
activate (GtkApplication *app,
          gpointer        user_data)
{
  GtkWidget *window;
  GtkWidget *grid;
  GtkWidget *button;
  GtkWidget *tocta;
  GdkPixbuf *pixbuf;  
    
  cairo_surface_t *surface;
  cairo_t *cr;  
  surface = cairo_image_surface_create (CAIRO_FORMAT_ARGB32, WIDTH, HEIGHT);
  cr = cairo_create (surface);
  
  /*-----------------Drawing code goes here---------------------------*/


  draw_line(cr, &ab, "(17+5i)");
  draw_line(cr, &ae, "(23+16i)");
  draw_line(cr, &af, "(9+7i)");

  draw_line(cr, &bc, "side bc");
  draw_line(cr, &be, "side be");
  draw_line(cr, &bf, "side bf");
  
  draw_line(cr, &cd, "side cd");
  draw_line(cr, &ce, "side ce");
  draw_line(cr, &cf, "side cf");
 
  draw_line(cr, &da, "side da");
  draw_line(cr, &de, "side de");
  draw_line(cr, &df, "side df");
  
  /*------------------------------------------------------------------*/
  
  // create new GTK image from surface  
  pixbuf = gdk_pixbuf_get_from_surface(surface, 0, 0, WIDTH, HEIGHT);
  tocta = gtk_image_new_from_pixbuf(pixbuf);
  
    /* create a new window, and set its title */
  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Tocta_82");
  gtk_container_set_border_width (GTK_CONTAINER (window), 10);

  /* Here we construct the container that is going pack our buttons */
  grid = gtk_grid_new ();

  /* Pack the container in the window */
  gtk_container_add (GTK_CONTAINER (window), grid);
  
  tocta = gtk_image_new_from_pixbuf(pixbuf);
  gtk_grid_attach(GTK_GRID(grid), tocta, 0,0,1,1);
  
  button = gtk_button_new_with_label ("Quit");
  g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_widget_destroy), window);

  /* Place the Quit button in the grid cell (0, 1), and make it
   * span 2 columns.
   */
  gtk_grid_attach (GTK_GRID (grid), button, 0, 1, 2, 1);

  /* Now that we are done packing our widgets, we show them all
   * in one go, by calling gtk_widget_show_all() on the window.
   * This call recursively calls gtk_widget_show() on all widgets
   * that are contained in the window, directly or indirectly.
   */
  gtk_widget_show_all (window);
  
  cairo_surface_destroy(surface);

}

int main(int argc, char **argv)
{
  GtkApplication *app;
  int status;
  
  // printf("%f,%f\n", dx,dy); exit(0);


  app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}

