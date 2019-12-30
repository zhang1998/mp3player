#include <stdlib.h>
#include <gtk-2.0/gtk/gtk.h>
#include <glib-2.0/glib.h>

#ifndef INTERFACE_H_
#define INTERFACE_H_
typedef struct _interface InterFace;
struct _interface {
	GtkWidget *winMain;
        GtkWidget *window_login;
        GtkWidget *window_login_with_phone;
        GtkWidget *vbMain;
	GtkWidget *diaPlaylist;
	GtkWidget *diaMedialib;
	GtkWidget *diaVolume;
	GtkWidget *diaFile;
	GtkWidget *diaDir;
	GtkWidget *treeClass;
	GtkWidget *treeMedialib;
	GtkWidget *treePlaylist;
	GtkWidget *etFind;
	GtkWidget *cbbFind;
  GtkWidget* window_home ;
  GtkWidget* table_home ;


  GtkWidget*label_home_title ;

  GtkWidget*button_home_zc ;

  GtkWidget*button_home_dl ;

};
GtkWidget *create_winMain (InterFace *ui);
GtkWidget *create_diaPlaylist (InterFace *ui);
GtkWidget *create_diaMedialib (InterFace *ui);
GtkWidget *create_diaVolume (InterFace *ui);
GtkWidget *create_logwindow(InterFace *ui);
GtkWidget *create_login_window_with_phone(InterFace *ui);

GtkWidget *btVolume;

int set_treeClass(InterFace *ui);
#endif /* INTERFACE_H_ */
