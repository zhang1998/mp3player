#include <gtk/gtk.h>

int main(int argc, char *argv[])
{
  gtk_init(&argc, &argv);

  GtkWidget *window_zc;
  window_zc = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window_zc), "媒体播放器");
  gtk_widget_show(window_zc);


  GtkWidget *hbox, *playbtn, *pausebtn, *stopbtn, *placeholder, *dlabel;
GtkWidget *playimg, *pauseimg, *stopimg;
hbox = gtk_hbox_new(FALSE, 5);
 gtk_widget_show(hbox) ;
 // gtk_widget_show();

 gtk_container_add (GTK_CONTAINER (window_zc), hbox);


playbtn = gtk_button_new();
 gtk_widget_show(playbtn);
pausebtn = gtk_button_new();
 gtk_widget_show(pausebtn);
stopbtn = gtk_button_new();
gtk_widget_show(stopbtn);



 playimg = gtk_image_new();
gtk_image_set_from_stock(GTK_IMAGE(playimg), GTK_STOCK_MEDIA_PLAY, GTK_ICON_SIZE_LARGE_TOOLBAR);
gtk_container_add(GTK_CONTAINER(playbtn), playimg);

pauseimg = gtk_image_new_from_file("./image/qq_image.jpg");
//gtk_image_set_from_stock(GTK_IMAGE(pauseimg), GTK_STOCK_MEDIA_PAUSE, GTK_ICON_SIZE_LARGE_TOOLBAR);
gtk_widget_show(pauseimg);
 


gtk_container_add(GTK_CONTAINER(pausebtn), pauseimg);

stopimg = gtk_image_new();

gtk_image_set_from_stock(GTK_IMAGE(stopimg), GTK_STOCK_MEDIA_STOP, GTK_ICON_SIZE_LARGE_TOOLBAR);
gtk_container_add(GTK_CONTAINER(stopbtn), stopimg);

placeholder = gtk_label_new("");
dlabel = gtk_label_new("Hi, guys! My name is Transformer~");

gtk_box_pack_start(GTK_BOX(hbox), playbtn, FALSE, FALSE, 5);
gtk_box_pack_start(GTK_BOX(hbox), pausebtn, FALSE, FALSE, 5);
gtk_box_pack_start(GTK_BOX(hbox), stopbtn, FALSE, FALSE, 5);
gtk_box_pack_start(GTK_BOX(hbox), placeholder, TRUE, TRUE, 5);
gtk_box_pack_start(GTK_BOX(hbox), dlabel, FALSE, FALSE, 5);                 
  /*

   */
gtk_main();
  return 0;
}
