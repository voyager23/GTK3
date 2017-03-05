/*
 * gtk_tocta.c
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

static gboolean on_prev_btn_clicked( GtkWidget *widget, gpointer data);
static gboolean on_next_btn_clicked( GtkWidget *widget, gpointer data);
static gboolean delete_event( GtkWidget *widget, GdkEvent  *event, gpointer   data );
static void destroy( GtkWidget *widget, gpointer   data );

static gboolean delete_event( GtkWidget *widget,
                              GdkEvent  *event,
                              gpointer   data )
{
    /* If you return FALSE in the "delete-event" signal handler,
     * GTK will emit the "destroy" signal. Returning TRUE means
     * you don't want the window to be destroyed.
     * This is useful for popping up 'are you sure you want to quit?'
     * type dialogs. */

    g_print ("delete event occurred\n");

    /* Change TRUE to FALSE and the main window will be destroyed with
     * a "delete-event". */

    return FALSE;
}

/* Another callback */
static void destroy( GtkWidget *widget,
                     gpointer   data )
{
    gtk_main_quit ();
}


static gboolean on_prev_btn_clicked( GtkWidget *widget, gpointer data) {
	printf("previous\n");
	return FALSE;
}


static gboolean on_next_btn_clicked( GtkWidget *widget, gpointer data) {
	printf("next\n");
	return FALSE;
}


int main(int argc, char **argv)
{
    GtkWidget *window;
    GtkWidget *vbox;
    GtkWidget *image;
    GtkWidget *hbox_lr;
    GtkWidget *btn_prev;
    GtkWidget *btn_next;
    GtkWidget *hbox_stat_quit;
    GtkWidget *lbl_status;
    GtkWidget *btn_quit;
    GtkWidget *file_chooser;
    
    gtk_init (&argc, &argv);
    
    /* create a new window */
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);   
    /* Sets the border width of the window. */
    gtk_container_set_border_width (GTK_CONTAINER (window), 10);
    g_signal_connect (window, "delete-event",
		G_CALLBACK (delete_event), NULL);    
    g_signal_connect (window, "destroy",
		G_CALLBACK (destroy), NULL);
    
    vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), vbox);    
    gtk_widget_show(vbox);
    
    image = gtk_image_new_from_file("./360x360.png");
    gtk_box_pack_start(GTK_BOX(vbox),image,TRUE,TRUE,5);
    gtk_widget_show(image);
    
    hbox_lr = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    gtk_box_pack_start(GTK_BOX(vbox),hbox_lr,TRUE,TRUE,5);
    
    btn_prev = gtk_button_new_with_label("prev");
    gtk_box_pack_start(GTK_BOX(hbox_lr), btn_prev, TRUE, TRUE, 5);
    g_signal_connect (btn_prev, "clicked",G_CALLBACK (on_prev_btn_clicked), NULL);
    
    btn_next = gtk_button_new_with_label("next");
    gtk_box_pack_start(GTK_BOX(hbox_lr), btn_next, TRUE, TRUE, 5);
    g_signal_connect (btn_next, "clicked",G_CALLBACK (on_next_btn_clicked), NULL);
    
    gtk_widget_show(btn_next);
    gtk_widget_show(btn_prev);
    gtk_widget_show(hbox_lr);
    
    /* show the window */
    gtk_widget_show (window);
    
    gtk_main ();
}

