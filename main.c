#include <gtk/gtk.h>

static void activate(GtkApplication *app,
                     gpointer user_data)
{
  GtkWidget *window;
  GtkWidget *vbox;
  GtkWidget *hbox;
  GtkWidget *button;
  GtkWidget *textView;
  GtkWidget *menu;
  GtkWidget *menuItem1;
  GtkWidget *menuItem2;
  GtkWidget *submenu1;
  GtkWidget *submenu2;
  GtkWidget *menuItem3;
  GtkWidget *menuItem4;
  GtkWidget *menuItem5;
  GtkWidget *menuItem6;

  window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "C GTK Example App");
  gtk_window_set_default_size(GTK_WINDOW(window), 1000, 600);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

  vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
  hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
  button = gtk_button_new_with_label("Hello World");
  textView = gtk_text_view_new();

  // Textview
  GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(textView));
  gtk_text_buffer_set_text(buffer, "Hello", -1);

  // Menu
  menu = gtk_menu_bar_new();
  menuItem1 = gtk_menu_item_new_with_label("File");
  menuItem2 = gtk_menu_item_new_with_label("Help");
  submenu1  = gtk_menu_new();
  submenu2  = gtk_menu_new();

  menuItem3 = gtk_menu_item_new_with_label("New File");
  menuItem4 = gtk_menu_item_new_with_label("Open File...");
  menuItem5 = gtk_menu_item_new_with_label("Quit");
  menuItem6 = gtk_menu_item_new_with_label("About");

  gtk_menu_shell_append(GTK_MENU_SHELL(submenu1), menuItem3);
  gtk_menu_shell_append(GTK_MENU_SHELL(submenu1), menuItem4);
  gtk_menu_shell_append(GTK_MENU_SHELL(submenu1), menuItem5);
  gtk_menu_shell_append(GTK_MENU_SHELL(submenu2), menuItem6);  

  gtk_menu_item_set_submenu(GTK_MENU_ITEM(menuItem1), submenu1);
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(menuItem2), submenu2);
  gtk_menu_shell_append(GTK_MENU_SHELL(menu), menuItem1);
  gtk_menu_shell_append(GTK_MENU_SHELL(menu), menuItem2);

  // Add elements to horizontal box
  gtk_box_pack_start(GTK_BOX(hbox), button, FALSE, FALSE, 4);
  gtk_box_pack_end(GTK_BOX(hbox), textView, TRUE, TRUE, 4);



  // Add menu and horizontal box to vbox
  gtk_box_pack_start(GTK_BOX(vbox), menu, FALSE, FALSE, 0);
  gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 4);
  // Add vbox to Window

  gtk_container_add(GTK_CONTAINER(window), vbox);
  gtk_widget_show_all(window);
}

int main(int argc, char *argv[])
{
  GtkApplication *app;
  int status;

  app = gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);
  g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
  status = g_application_run(G_APPLICATION(app), argc, argv);
  g_object_unref(app);

  return status;
}