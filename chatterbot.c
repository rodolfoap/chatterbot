#include <stdlib.h>
#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <time.h>

GtkWidget *window, *image;
GdkBitmap *mask; 
int face=1, speaking=0;
char filename[]="chatterbot0.png", sentence[256], command[256];

int destroy(GtkWidget *widget, gpointer data) { 
	gtk_main_quit(); 
}
static gpointer readphrase(){
	printf("Write a text: ");
	while(scanf("%s", sentence)!=EOF){
		speaking=1;
		sprintf(command, "espeak %s", sentence);
		system(command);
		speaking=0;
	}
	exit(0);
}
int movelips() {
	if(speaking) sprintf(filename, "chatterbot%d.png", face=1-face);
	else sprintf(filename, "chatterbot%d.png", face=0);
	gtk_image_set_from_file(GTK_IMAGE(image), filename);
}
int main (int argc, char * argv[]) {
	gtk_init (&argc, &argv);
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	image = gtk_image_new_from_file(filename);
	gtk_container_add(GTK_CONTAINER(window), image);

	g_signal_connect(G_OBJECT (window), "destroy", G_CALLBACK (destroy), NULL);
	gtk_widget_show_all(window);
	gtk_window_set_keep_above(GTK_WINDOW(window), TRUE);
	gtk_window_set_decorated(GTK_WINDOW(window), FALSE);
	gtk_window_stick(GTK_WINDOW(window));

	gdk_pixbuf_render_pixmap_and_mask(gtk_image_get_pixbuf(GTK_IMAGE(image)), NULL, &mask, 255); 
	gtk_widget_shape_combine_mask(window,mask,0,0); 
	g_timeout_add (200, movelips, NULL);
	g_thread_new("bnd-struc", readphrase, NULL);
	gtk_main();
	return 0;
}
/* rodolfoap@gmail.com */
