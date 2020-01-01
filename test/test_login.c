#include <gtk-2.0/gtk/gtkbbox.h>
#include <gtk-2.0/gtk/gtk.h>
#include <gtk-2.0/gtk/gtkwidget.h>
#include <glib-2.0/glib.h>


int main(int argc, char *argv[])
{
  gtk_init(&argc, &argv);

  GtkWidget *window_zc;
  window_zc = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window_zc), "媒体播放器");
  gtk_widget_show(window_zc);

     GtkWidget *vb_Main_zc;
     vb_Main_zc = gtk_vbox_new (FALSE, 0);
     gtk_widget_show (vb_Main_zc);
     gtk_container_add (GTK_CONTAINER (window_zc), vb_Main_zc);

         GtkWidget *logo_image=gtk_image_new_from_file("./image/logo_for_wangyi.png");
         gtk_widget_show(logo_image);
         gtk_box_pack_start (GTK_BOX (vb_Main_zc), logo_image, TRUE, TRUE, 0);


         GtkWidget *button_login_1=gtk_button_new_with_label("手机号注册");
         gtk_widget_show (button_login_1);
         gtk_box_pack_start (GTK_BOX (vb_Main_zc), button_login_1, FALSE, FALSE, 0);


         GtkWidget *button_login_2=gtk_button_new_with_label("登录");
         gtk_widget_show (button_login_2);
         gtk_box_pack_start (GTK_BOX (vb_Main_zc), button_login_2, FALSE, FALSE, 0);

         GtkWidget *vb_four_button_zc;
         vb_four_button_zc = gtk_hbox_new (FALSE, 0);
         gtk_widget_show (vb_four_button_zc);
         gtk_box_pack_start(GTK_BOX(vb_Main_zc),vb_four_button_zc, FALSE, FALSE, 0);

              //测试

         GtkWidget *button_qq_login_2=gtk_button_new();
                gtk_widget_show (button_qq_login_2);
              gtk_box_pack_start (GTK_BOX (vb_four_button_zc), button_qq_login_2, FALSE, FALSE, 0);


             GtkWidget *qq_image = gtk_button_new();
             qq_image = gtk_image_new_from_file("./image/qq_image.jpg");
             gtk_image_set_from_file(qq_image,"./image/stand_pixel_four.jpg");
             gtk_widget_show(qq_image);

             gtk_container_add(GTK_CONTAINER(button_qq_login_2), qq_image);



             gtk_main();





  return 0;
}
