#include <gtk-2.0/gtk/gtk.h>
#include <gtk-2.0/gtk/gtkwidget.h>
#include <glib-2.0/glib.h>





int main(int argc, char *argv[])
{
  GtkWidget *window_zc;
  window_zc = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (win_zc), "媒体播放器");
  gtk_widget_show(window_zc);

     GtkWidget *vb_Main_zc;
     vb_Main_zc = gtk_hbox_new (FALSE, 0);
     gtk_widget_show (vb_Main_zc);
     gtk_container_add (GTK_CONTAINER (window_zc), vb_Main_zc);

         GtkWidget *button_login_1=gtk_button_new_with_label("手机号注册");
         gtk_widget_show (button_login_1);
         gtk_box_pack_start (GTK_BOX (vb_Main_zc), button_login_1, FALSE, FALSE, 0);


         GtkWidget *button_login_2=gtk_button_new_with_label("登录");
         gtk_widget_show (button_login_2);
         gtk_box_pack_start (GTK_BOX (vb_Main_zc), button_login_2, FALSE, FALSE, 0);




/*
         GtkWidget *logo_image=gtk_image_new_from_file("./image/logo_for_wangyi.png");
         gtk_widget_show(logo_image);
         gtk_box_pack_start (GTK_BOX (vb_Main_zc), logo_image, TRUE, TRUE, 0);


*/





  return 0;
}
