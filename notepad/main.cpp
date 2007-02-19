#include <gtk/gtk.h>
#include <glade/glade.h>

/*
 * Dummy Notepad
 */

void quitClicked (GtkWidget *widget, gpointer user_data)
{
	gtk_main_quit();
}


int main (int argc, char* argv[])
{
	GladeXML* mainWindow;
	//GtkWidget* widget;
	
	gtk_init (&argc, &argv);

	/* load the interface */
	mainWindow = glade_xml_new ("dummy.glade", NULL, NULL);
	
	/* Have the ok button call the ok_button_clicked callback */
	g_signal_connect (G_OBJECT (glade_xml_get_widget (mainWindow, "imagemenuitem5")), "button_press_event", G_CALLBACK (quitClicked), NULL);

	/* Have the delete event (window close) end the program */
	g_signal_connect (G_OBJECT (glade_xml_get_widget (mainWindow, "window1")), "delete_event", G_CALLBACK (gtk_main_quit), NULL);

	gtk_widget_show (glade_xml_get_widget (mainWindow, "window1"));

	/* start the event loop */
	gtk_main ();
	
	return 0;
}
