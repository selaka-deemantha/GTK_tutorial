#include<stdio.h>
#include<gtk/gtk.h>



void func1(GtkWidget *widget,gpointer data){
    printf("hello! button is pressed!\n");
}

int main(int argc,char *argv[]){

    gtk_init(&argc,&argv);
    GtkWidget *window;
    GtkWidget *button;

    window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window),"This is the title");
    gtk_container_set_border_width(GTK_CONTAINER(window),500);
    g_signal_connect(G_OBJECT(window),"destroy",G_CALLBACK(gtk_main_quit),NULL);
    button=gtk_button_new_with_label("hello world");
    gtk_container_add(GTK_CONTAINER(window),button);
    g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(gtk_main_quit),NULL);
    gtk_widget_show(button);

    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}