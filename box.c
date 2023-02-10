#include<stdio.h>
#include<gtk/gtk.h>



void func1(GtkWidget *widget,gpointer data){
    printf("hello! button1 is pressed!\n");
}
void func2(GtkWidget *widget,gpointer data){
    printf("hello! button2 is pressed!\n");
}

int main(int argc,char *argv[]){

    gtk_init(&argc,&argv);
    GtkWidget *window;
    GtkWidget *button;
    GtkWidget *box;

    window=gtk_window_new(GTK_WINDOW_TOPLEVEL);


    gtk_window_set_title(GTK_WINDOW(window),"This is the title");


    gtk_container_set_border_width(GTK_CONTAINER(window),500);


    g_signal_connect(G_OBJECT(window),"destroy",G_CALLBACK(gtk_main_quit),NULL);


    box=gtk_box_new(FALSE,0);
    gtk_container_add(GTK_CONTAINER(window),box);


    button=gtk_button_new_with_label("Button 1");


    g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(func1),NULL);

    gtk_box_pack_start (GTK_BOX(box), button, FALSE, FALSE, 0);
    //gtk_widget_show(button);

    button = gtk_button_new_with_label ("Button 2");
    g_signal_connect (G_OBJECT (button), "clicked",G_CALLBACK (func2),NULL);
    gtk_box_pack_start(GTK_BOX (box), button, FALSE, FALSE, 30);



    //gtk_widget_show (button);
    //gtk_widget_show (box);
    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}