#include <gtk/gtk.h>
void quit(GtkWidget *window, gpointer data)
{
	gtk_main_quit();
}

int main(int argc, char *argv[])
{
	GtkWidget *window;
	GtkWidget *label1, *label2, *label3;
	GtkWidget *hbox;
	GtkWidget *vbox;

	gtk_init(&argc, &argv);
	window= gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "The Window Title");
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_default_size(GTK_WINDOW(window), 100, 200);

/* 윈도우를닫을때“destroy” 시그널이발생함*/
	g_signal_connect (window, "destroy", G_CALLBACK ( quit), NULL);
	label1= gtk_label_new("20163356");
	label2= gtk_label_new("hwang");
	label3= gtk_label_new("jeongho");

	hbox = gtk_hbox_new (GTK_ORIENTATION_HORIZONTAL, 10 );
	vbox = gtk_vbox_new (GTK_ORIENTATION_VERTICAL, 10);
	gtk_box_pack_start(GTK_BOX(hbox), label1, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(hbox), label2, TRUE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 5);
	gtk_box_pack_start(GTK_BOX(vbox), label3, FALSE, FALSE, 5);
	gtk_container_add(GTK_CONTAINER(window), vbox);
	gtk_widget_show_all(window);
	gtk_main ();
	
	return 0;
}
