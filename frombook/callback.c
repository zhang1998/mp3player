﻿#include <gtk-2.0/gtk/gtk.h>
#include <glib-2.0/glib.h>
#include <string.h>
#include <gtk-2.0/gtk/gtkstock.h>
#include <gtk-2.0/gtk/gtktypeutils.h>
#include "callback.h"
#include "interface.h"
#include "main_core.h"
#include "medialib.h"

void on_button_zc_2_clicked(GtkWidget *button_login,
		                   InterFace *ui)
{
  
}
//on_button_login_2_clicked  登录按键的处理
//on_button_zc_from_phone_clicked :手机号注册
//on_button_login_from_phone_clicked
void on_button_login_from_phone_clicked(GtkWidget *button_zc_from_phone,
		                   InterFace *ui)
{
  

    gtk_widget_show(ui->window_login_with_phone);
  //window_zc_1
  
  
}
void on_button_login_3_clicked(GtkWidget *button_login,
		                   InterFace *ui)
{
  //tod
  //  gtk_widget_show(ui->window_zc_1);
  
}


void button_home_zc_login(GtkWidget *button_login,
		                   InterFace *ui)
{
  //gtk_widget_show(ui->window_zc_1);
}
//on_button_login_clicked的登录



void on_button_login_clicked(GtkWidget *button_login,
		                   InterFace *ui)
{
  //		gtk_widget_hide(ui->window_zc);
  
		gtk_widget_show(ui->window_login);
  

}
//
void on_button_home_phone_login_clicked(GtkWidget *button_login_1,
		                   UserData *userdata)
{
     sqlite3 *db;
   char *zErrMsg = 0;
   char *sql;
  int rc;
     rc = sqlite3_open("phone_login.db", &db);

   if( rc ){
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      exit(0);
   }else{
      fprintf(stderr, "Opened database successfully\n");
   }
   /*
     struct _userdata{
  char *phone_number=[];
  char *qq_number=[];
  char *password=[];
  int *need_autologin=0;

    */
   //查询相关表
   *sql=sqlite_mprintf("SELECT * FROM test2 where phone_number=%s",userdata->phone_number);
   
     //对比相关表
   rc=sqlite3_get_table(db,sql,&result,row,col,&errmsg);

   if(res!=SQLITE_OK)
     printf("查询失败，代码:%d-%s\n",res,errmsg);
   else if (row<2)
     puts("查询结果为零条");
   else{
     puts("查询成功，查询结果为");
     UserData *get_User_data=malloc
   }
   

   

}
//注册
//  
//

void on_button_login_1_clicked(GtkWidget *button_login_1,
		                   InterFace *ui)
{
  //		gtk_widget_show(ui->window_zc);
  
  gtk_widget_hide(ui->window_login_with_phone);

  
}
void on_btVolume_clicked(GtkWidget *btVolume,
		                   InterFace *ui)
{
	if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(btVolume)))
		gtk_widget_show(ui->diaVolume);
	else
		gtk_widget_hide(ui->diaVolume);


        
}




void on_btPlaylist_clicked(GtkWidget *btPlaylist,
                           InterFace *ui)
{
	gtk_widget_show(ui->diaPlaylist);
	gboolean visible;
	g_object_get(GTK_WINDOW(ui->diaPlaylist), "visible",
	             &visible, NULL);
	if (!visible)
		main_core(PLAYLIST_SHOW, ui);
}

void on_btMedialib_clicked(GtkWidget *btMedialib,
                           InterFace *ui)
{
	gboolean visible;
	g_object_get(GTK_WINDOW(ui->diaMedialib), "visible",
	             &visible, NULL);
	if (!visible)
		main_core(MEDIALIB_SHOW, ui);

}

void on_tlbAdd_clicked(GtkWidget *btMedialib,
                       InterFace *ui)
{
   GtkWidget *dialog;
   /*
   dialog = gtk_file_chooser_dialog_new ("选择媒体文件",
					      GTK_WINDOW(ui->diaMedialib),
					      GTK_FILE_CHOOSER_ACTION_OPEN,
					      GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
					      GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT,
					      NULL);

					      */
   dialog = gtk_file_chooser_dialog_new ("选择媒体文件",
					      GTK_WINDOW(ui->diaMedialib),
					      GTK_FILE_CHOOSER_ACTION_OPEN,
					      GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
					      GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT,
					      NULL);

   GtkFileFilter *filefilter;
   filefilter = gtk_file_filter_new();
   gtk_file_filter_set_name(filefilter, "mp3");
   gtk_file_filter_add_pattern(filefilter, "*.mp3");
   gtk_file_chooser_add_filter(GTK_FILE_CHOOSER(dialog),
		   filefilter);
   if (gtk_dialog_run (GTK_DIALOG (dialog)) == GTK_RESPONSE_ACCEPT)
   {
	    char *filename;
	    filename = gtk_file_chooser_get_filename (GTK_FILE_CHOOSER (dialog));
	    main_core(MEDIALIB_ADD_FILE, filename);
	    main_core(MEDIALIB_BRUSH, ui);
	    g_free (filename);
   }
	gtk_widget_destroy (dialog);
}


void on_tlbDel_clicked(GtkWidget *btMedialib,
                       InterFace *ui)
{
	GValue value = {0};
	GtkTreeIter iter = {0};
	GtkListStore *liststore;
	GtkTreeSelection *selection;
	char filename[MAX_PATH_LENGTH];
	GtkWidget *dialog;
	liststore = (GtkListStore *)gtk_tree_view_get_model(GTK_TREE_VIEW(ui->treeMedialib));
	selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(ui->treeMedialib));
	if (gtk_tree_selection_count_selected_rows (selection)) {
		gtk_tree_selection_get_selected(selection, (GtkTreeModel**) &liststore, &iter);
		gtk_tree_model_get_value(GTK_TREE_MODEL(liststore), &iter, 5, &value);
		strcpy(filename, g_value_get_string(&value));
		main_core(MEDIALIB_DEL, filename);
	   main_core(MEDIALIB_BRUSH, ui);
	}
	else {
		dialog = gtk_message_dialog_new (GTK_WINDOW(ui->diaMedialib),
				                             GTK_DIALOG_MODAL,
		                                  GTK_MESSAGE_ERROR,
		                                  GTK_BUTTONS_CLOSE,
		                                                   "未选择媒体文件");
		 gtk_dialog_run (GTK_DIALOG (dialog));
		 gtk_widget_destroy (dialog);
	}
}

void on_tlbDelall_clicked(GtkWidget *btMedialib,
                       InterFace *ui)
{
	GtkWidget *dialog;
	dialog = gtk_message_dialog_new (GTK_WINDOW(ui->diaMedialib),
					                     GTK_DIALOG_MODAL,
			                           GTK_MESSAGE_QUESTION,
			                           GTK_BUTTONS_YES_NO,
			                                    "是否删除媒体库中所有文件信息？");
	if(gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_YES) {
		main_core(MEDIALIB_DEL_ALL, ui);
		main_core(MEDIALIB_BRUSH, ui);
	}
	gtk_widget_destroy (dialog);
}

void on_tlbSearch_clicked(GtkWidget *btMedialib,
                       InterFace *ui)
{
	GtkWidget *dialog;
	dialog = gtk_message_dialog_new (GTK_WINDOW(ui->diaMedialib),
					                     GTK_DIALOG_MODAL,
			                           GTK_MESSAGE_QUESTION,
			                           GTK_BUTTONS_YES_NO,
			                                    "是否开始搜索？");
	if(gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_YES) {
		main_core(MEDIALIB_SEARCH, ui);
		main_core(MEDIALIB_BRUSH, ui);
	}
	gtk_widget_destroy (dialog);
}

void on_tlbSendto_clicked(GtkWidget *btMedialib,
                       InterFace *ui)
{
	GValue value = {0};
	GtkTreeIter iter = {0};
	GtkListStore *liststore;
	GtkTreeSelection *selection;
	char filename[MAX_PATH_LENGTH];
	GtkWidget *dialog;
	liststore = (GtkListStore *)gtk_tree_view_get_model(GTK_TREE_VIEW(ui->treeMedialib));
	selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(ui->treeMedialib));
	if (gtk_tree_selection_count_selected_rows (selection)) {
		gtk_tree_selection_get_selected(selection, (GtkTreeModel**) &liststore, &iter);
		gtk_tree_model_get_value(GTK_TREE_MODEL(liststore), &iter, 5, &value);
		strcpy(filename, g_value_get_string(&value));
		main_core(MEDIALIB_SEND_TO_PLAYLIST, filename);
	   main_core(PLAYLIST_BRUSH, ui);
	}
	else {
		dialog = gtk_message_dialog_new (GTK_WINDOW(ui->diaMedialib),
				                             GTK_DIALOG_MODAL,
		                                  GTK_MESSAGE_ERROR,
		                                  GTK_BUTTONS_CLOSE,
		                                                   "未选择媒体文件");
		 gtk_dialog_run (GTK_DIALOG (dialog));
		 gtk_widget_destroy (dialog);
	}
}

void on_btFind_clicked(GtkWidget *btMedialib,
                       InterFace *ui)
{
	if (! gtk_entry_get_text_length (GTK_ENTRY(ui->etFind)))
		gtk_entry_set_text ((GTK_ENTRY(ui->etFind)), "*");
	main_core(MEDIALIB_FIND, ui);
	main_core(MEDIALIB_BRUSH, ui);
}

void on_tbtAdd_clicked(GtkWidget *tbtAdd,
                       InterFace *ui)
{
	GtkWidget *dialog;
	dialog = gtk_file_chooser_dialog_new ("选择媒体文件",
				      GTK_WINDOW(ui->diaPlaylist),
				      GTK_FILE_CHOOSER_ACTION_OPEN,
				      GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
				      GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT,
				      NULL);
	GtkFileFilter *filefilter;
	filefilter = gtk_file_filter_new();
	gtk_file_filter_set_name(filefilter, "mp3");
	gtk_file_filter_add_pattern(filefilter, "*.mp3");
	gtk_file_chooser_add_filter(GTK_FILE_CHOOSER(dialog),
	   filefilter);
	if (gtk_dialog_run (GTK_DIALOG (dialog)) == GTK_RESPONSE_ACCEPT)
	 {
	   char *filename;
	   filename = gtk_file_chooser_get_filename (GTK_FILE_CHOOSER (dialog));
	   main_core(PLAYLIST_ADD_FILE, filename);
	   main_core(PLAYLIST_BRUSH, ui);
	   g_free (filename);
	   }
		gtk_widget_destroy (dialog);
}

void on_tbtAdddir_clicked(GtkWidget *tbtAdddir,
                          InterFace *ui)
{
	   GtkWidget *dialog;
	   dialog = gtk_file_chooser_dialog_new ("选择媒体目录",
						      GTK_WINDOW(ui->diaPlaylist),
						      GTK_FILE_CHOOSER_ACTION_SELECT_FOLDER,
						      GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
						      GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT,
						      NULL);
	   if (gtk_dialog_run (GTK_DIALOG (dialog)) == GTK_RESPONSE_ACCEPT)
	   {
		    char *pathname;
		    pathname = gtk_file_chooser_get_filename (GTK_FILE_CHOOSER (dialog));
		    main_core(PLAYLIST_ADD_DIR, pathname);
		    main_core(PLAYLIST_BRUSH, ui);
		    g_free (pathname);
	   }
		gtk_widget_destroy (dialog);
}

void on_tbtOpen_clicked(GtkWidget *tbtOpen,
                        InterFace *ui)
{
	   GtkWidget *dialog;
	   dialog = gtk_file_chooser_dialog_new ("打开M3U文件",
						      GTK_WINDOW(ui->diaPlaylist),
						      GTK_FILE_CHOOSER_ACTION_OPEN,
						      GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
						      GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT,
						      NULL);
		GtkFileFilter *filefilter;
		filefilter = gtk_file_filter_new();
		gtk_file_filter_set_name(filefilter, "M3U");
		gtk_file_filter_add_pattern(filefilter, "*.m3u");
		gtk_file_chooser_add_filter(GTK_FILE_CHOOSER(dialog),
		   filefilter);
	   if (gtk_dialog_run (GTK_DIALOG (dialog)) == GTK_RESPONSE_ACCEPT)
	   {
		    char *pathname;
		    pathname = gtk_file_chooser_get_filename (GTK_FILE_CHOOSER (dialog));
		    main_core(PLAYLIST_OPEN, pathname);
		    main_core(PLAYLIST_BRUSH, ui);
		    g_free (pathname);
	   }
		gtk_widget_destroy (dialog);
}

void on_tbtSave_clicked(GtkWidget *tbtSave,
                       InterFace *ui)
{
	   GtkWidget *dialog;
	   dialog = gtk_file_chooser_dialog_new ("保存M3U文件",
						      GTK_WINDOW(ui->diaPlaylist),
						      GTK_FILE_CHOOSER_ACTION_SAVE,
						      GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
						      GTK_STOCK_SAVE, GTK_RESPONSE_ACCEPT,
						      NULL);
		GtkFileFilter *filefilter;
		filefilter = gtk_file_filter_new();
		gtk_file_filter_set_name(filefilter, "M3U");
		gtk_file_filter_add_pattern(filefilter, "*.m3u");
		gtk_file_chooser_add_filter(GTK_FILE_CHOOSER(dialog),
		   filefilter);
	   if (gtk_dialog_run (GTK_DIALOG (dialog)) == GTK_RESPONSE_ACCEPT)
	   {
		    char *pathname;
		    pathname = gtk_file_chooser_get_filename (GTK_FILE_CHOOSER (dialog));
		    main_core(PLAYLIST_OPEN, pathname);
		    main_core(PLAYLIST_BRUSH, ui);
		    g_free (pathname);
	   }
		gtk_widget_destroy (dialog);
}

void on_tbtDel_clicked(GtkWidget *tbtDel,
                       InterFace *ui)
{
	GtkListStore *liststore;
	GtkTreeSelection *selection;
	GtkWidget *dialog;
	liststore = (GtkListStore *)gtk_tree_view_get_model(GTK_TREE_VIEW(ui->treePlaylist));
	selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(ui->treePlaylist));
	if (gtk_tree_selection_count_selected_rows (selection)) {
		main_core(PLAYLIST_DEL, ui);
	   main_core(PLAYLIST_BRUSH, ui);
	}
	else {
		dialog = gtk_message_dialog_new (GTK_WINDOW(ui->diaPlaylist),
				                             GTK_DIALOG_MODAL,
		                                  GTK_MESSAGE_ERROR,
		                                  GTK_BUTTONS_CLOSE,
		                                                   "未选择媒体文件");
		 gtk_dialog_run (GTK_DIALOG (dialog));
		 gtk_widget_destroy (dialog);
	}
}

void on_tbtDelall_clicked(GtkWidget *tbtDelall,
                       InterFace *ui)
{
	GtkWidget *dialog;
	dialog = gtk_message_dialog_new (GTK_WINDOW(ui->diaPlaylist),
					                     GTK_DIALOG_MODAL,
			                           GTK_MESSAGE_QUESTION,
			                           GTK_BUTTONS_YES_NO,
			                                    "是否删除播放列表中所有文件信息？");
	if(gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_YES) {
		main_core(PLAYLIST_DEL_ALL, ui);
		main_core(PLAYLIST_BRUSH, ui);
	}
	gtk_widget_destroy (dialog);
}

void on_cbbMode_active(GtkWidget *cbbMode,
							InterFace *ui)
{
	static int mode;
	mode = gtk_combo_box_get_active(GTK_COMBO_BOX(cbbMode));
	main_core(GENERAL_PLAY_MODE, &mode);
}
