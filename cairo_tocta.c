/*
 * cairo_tocta.c
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

#define WIDTH  480.0
#define HEIGHT 480.0


// Co-ords for tocta nodes based on 12 * 12 model
double ax = (0.0);					double ay = (4.0 * HEIGHT/12.0);
double bx = (5.0 * WIDTH/12.0);		double by = (4.0 * HEIGHT/12.0);
double cx = (12.0 * WIDTH/12.0);	double cy = (8.0 * HEIGHT/12.0);
double dx = (7.0 * WIDTH/12.0);		double dy = (8.0 * HEIGHT/12.0);
double ex = (4.0 * WIDTH/12.0);		double ey = (12.0 * HEIGHT/12.0);
double fx = (8.0 * WIDTH/12.0);		double fy = (0.0);

// Co-ords for line values based on 12 * 12 model

double a1x = (2.0 * WIDTH / 12.0);	double a1y = (3.8 * HEIGHT / 12.0); 
double b1x = (8.5 * WIDTH / 12.0);	double b1y = (5.6 * HEIGHT / 12.0); 
double c1x = (8.5 * WIDTH / 12.0);	double c1y = (7.8 * HEIGHT / 12.0); 
double d1x = (3.1 * WIDTH / 12.0);	double d1y = (5.6 * HEIGHT / 12.0); 




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

  
  /* Drawing code goes here */
  cairo_set_source_rgb(cr, 0.5,0.94,1.0);
  cairo_paint(cr);
  
  cairo_set_source_rgb (cr, 0.5, 0.2, 0.5);
  cairo_set_line_width (cr, 5);
  cairo_move_to(cr, ax, ay);
  cairo_line_to(cr, ex, ey);
  cairo_line_to(cr, cx, cy);
  cairo_line_to(cr, fx, fy);
  cairo_line_to(cr, ax, ay);
  
  cairo_move_to(cr, ax, ay);
  cairo_line_to(cr, dx, dy);
  cairo_line_to(cr, cx, cy);
  
  cairo_move_to(cr, ex, ey);
  cairo_line_to(cr, dx, dy);
  cairo_line_to(cr, fx, fy);  
  cairo_stroke(cr);
  
  cairo_set_line_width(cr,2);
  cairo_move_to(cr, ex, ey);
  cairo_line_to(cr, bx, by);
  cairo_line_to(cr, fx, fy);
  
  cairo_move_to(cr, ax, ay);
  cairo_line_to(cr, bx, by);
  cairo_line_to(cr, cx, cy);
  
  cairo_stroke(cr);
  
cairo_select_font_face(cr, "Purisa",
      CAIRO_FONT_SLANT_NORMAL,
      CAIRO_FONT_WEIGHT_BOLD);

  cairo_set_font_size(cr, 12);
  cairo_set_source_rgb(cr, 0.8,0.1,0.1);
  cairo_move_to(cr, a1x, a1y);
  cairo_show_text(cr, "(17+13i)");
  cairo_move_to(cr, b1x, b1y);
  cairo_show_text(cr, "(17+13i)");
  cairo_move_to(cr, c1x, c1y);
  cairo_show_text(cr, "(17+13i)");
  cairo_move_to(cr, d1x, d1y);
  cairo_show_text(cr, "(17+13i)");
  
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

