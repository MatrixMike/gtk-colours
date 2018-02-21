/* Compile with: 
*       gcc -Wall -o csswindow `pkg-config --cflags --libs gtk+-3.0` csswindow.c                           
*/
// https://developer.gnome.org/gio/stable/GIcon.html
// https://wiki.gnome.org/Attic/GnomeArt/Tutorials/IconThemes


#include <gtk/gtk.h>
// 25 Nov 2014
// 27 Nov
//  8 Dec 2014
// 10 October 2016 - used indent to tidy source
// 27.01.2018

//  -pthread -I/usr/include/gtk-3.0 -I/usr/include/atk-1.0 -I/usr/include/at-spi2-atk/2.0 -I/usr/include/pango-1.0 -I/usr/include/gio-unix-2.0/ -I/usr/include/cairo -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/harfbuzz -I/usr/include/freetype2 -I/usr/include/pixman-1 -I/usr/include/libpng12  -lgtk-3 -lgdk-3 -latk-1.0 -lgio-2.0 -lpangocairo-1.0 -lgdk_pixbuf-2.0 -lcairo-gobject -lpango-1.0 -lcairo -lgobject-2.0 -lglib-2.0  

/*
void about_dialog_set() {
gtk_about_dialog_set_program_name (GTK_ABOUT_DIALOG (dialog), "Mike's Test Demo");   // added 'program' 7/12/2014
gtk_about_dialog_set_version (GTK_ABOUT_DIALOG (dialog), "1.2");
gtk_about_dialog_set_copyright (GTK_ABOUT_DIALOG (dialog), "2015 Mike Hewitt");
gtk_about_dialog_set_comments (GTK_ABOUT_DIALOG (dialog), "All about Mike Test Demo Application");
gtk_about_dialog_set_license (GTK_ABOUT_DIALOG (dialog), "Free to a lot of folk");
gtk_about_dialog_set_website (GTK_ABOUT_DIALOG (dialog), "https://www.electroteach.com/mike");
gtk_about_dialog_set_website_label (GTK_ABOUT_DIALOG (dialog), "https://www.electroteach.com/mike");
gtk_about_dialog_set_authors (GTK_ABOUT_DIALOG (dialog), authors);
gtk_about_dialog_set_documenters (GTK_ABOUT_DIALOG (dialog), documenters);
gtk_about_dialog_set_translator_credits (GTK_ABOUT_DIALOG (dialog), "Translator #1\nTranslator #2");
}
*/

int
main (int argc, char *argv[], char **env_var_ptr)	// 
{
  GtkWidget *window;
  GtkWidget *button;
  GtkWidget *dialog;
  GdkPixbuf *logo;
  GError *error = NULL;

  int i;
/*
 * add ability to cope with arg   1= --version
 * i.e. compatibility with most gtk programs
 * 
 */



/*--- CSS -----------------*/
  GtkCssProvider *provider;
  GdkDisplay *display;
  GdkScreen *screen;
/*-------------------------*/
  gtk_init (&argc, &argv);

// 18 nov 2014
  const gchar *authors[] = {
    "Mike J Hewitt",
    "Author #2",
    NULL
  };

  const gchar *documenters[] = {
    "Mike J Hewitt",
    "Documenter #2",
    NULL
  };
  dialog = gtk_about_dialog_new ();

  printf ("\ncmdline args count=%d", argc);	//mike 
/* First argument is executable name only */
  printf ("\nexe name=%s", argv[0]);

  for (i = 0; i < argc; i++)
    {
      printf ("\narg %3d= %s", i, argv[i]);
    }
  i = 0;
  while (*env_var_ptr != NULL)
    {
      i++;
      printf ("\nenv var%3d=> %s", i, *(env_var_ptr++));
    }
	printf("\n");

  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window), "Hello Mike 7");
  gtk_window_set_default_size (GTK_WINDOW (window), 500, 300);
  gtk_container_set_border_width (GTK_CONTAINER (window), 50);
  button = gtk_button_new_with_mnemonic ("Test button");
  gtk_button_set_relief (GTK_BUTTON (button), GTK_RELIEF_HALF);

  gtk_window_move (GTK_WINDOW (window), 900, 300);	//mjh
  g_signal_connect (GTK_WIDGET (window),
		    "destroy", G_CALLBACK (gtk_main_quit), NULL);

/*------  CSS  ----------------------------------------------------------------------------------------*/
  provider = gtk_css_provider_new ();
  display = gdk_display_get_default ();
  screen = gdk_display_get_default_screen (display);

  gtk_style_context_add_provider_for_screen (screen,
					     GTK_STYLE_PROVIDER (provider),
					     GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
  // mjh gtk_container_set_border_width (    ,    15);


  gtk_css_provider_load_from_data (GTK_CSS_PROVIDER (provider),
				   " GtkWindow {\n"
				   "   -GtkWidget-focus-line-width: 0;\n"
/* The next 2 lines are not guaranteed to work, they can be can be overridden by the window manager*/
				   "   -GtkWindow-resize-grip-height: 0;\n"
				   "   -GtkWindow-resize-grip-width: 0;\n"
/* The next 4 lines are just 4 different ways to make the background blue. Each one overrides the last one.
    They are just different color units: named color units, rgb,  rgba, hexadecimal, and shade*/
				   "   background-color: blue;\n"
				   "   background-color: rgb (0, 255, 255);\n"
				   //    "   background-color: rgba (0,0,255,1);\n"
				   //sr           "   background-color: #FFFF00;\n"           
				   //      "   background-color: shade(blue, 1.0);\n" 
				   "}\n", -1, NULL);

  g_object_unref (provider);
/*----------------------------------------------------------------------------------------------------------*/
  gtk_container_add (GTK_CONTAINER (window), button);

  gtk_about_dialog_set_program_name (GTK_ABOUT_DIALOG (dialog), "Mike's Test Demo");	// added 'program' 7/12/2014
  gtk_about_dialog_set_version (GTK_ABOUT_DIALOG (dialog), "1.3");
  gtk_about_dialog_set_copyright (GTK_ABOUT_DIALOG (dialog),
				  "2018 Mike Hewitt");
  gtk_about_dialog_set_comments (GTK_ABOUT_DIALOG (dialog),
				 "All about Mike Test Demo Application");
  gtk_about_dialog_set_license (GTK_ABOUT_DIALOG (dialog),
				"Free to a lot of folk");
  gtk_about_dialog_set_website (GTK_ABOUT_DIALOG (dialog),
				"https://www.electroteach.com/mike");
  gtk_about_dialog_set_website_label (GTK_ABOUT_DIALOG (dialog),
				      "https://www.electroteach.com/mike");
  gtk_about_dialog_set_authors (GTK_ABOUT_DIALOG (dialog), authors);
  gtk_about_dialog_set_documenters (GTK_ABOUT_DIALOG (dialog), documenters);
  gtk_about_dialog_set_translator_credits (GTK_ABOUT_DIALOG (dialog),
					   "Translator #1\nTranslator #2");


  gtk_dialog_run (GTK_DIALOG (dialog));

  gtk_widget_show_all (window);
  gtk_main ();
  return (0);
}
