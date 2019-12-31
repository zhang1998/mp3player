#include <gtk/gtk.h>
#include <sqlite3.h>
GtkWidget *entry;
char *str[];

void *on_click_button(GtkWidget *button,int ls){

  //char *str[];   *str=gtk_entry_get_text(entry);
  *str=gtk_entry_get_text(entry);
   sqlite3 *db;
   char *zErrMsg = 0;
   char *sql;
   int rc;

   rc = sqlite3_open("test.db", &db);

   if( rc ){
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      exit(0);
   }else{
      fprintf(stderr, "Opened database successfully\n");
   }


   //操作
   /*
     INSERT 模板
     sql = "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
         "VALUES (1, 'Paul', 32, 'California', 20000.00 ); " \
         "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
         "VALUES (2, 'Allen', 25, 'Texas', 15000.00 ); "     \
         "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
         "VALUES (3, 'Teddy', 23, 'Norway', 20000.00 );" \
         "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
         "VALUES (4, 'Mark', 25, 'Rich-Mond ', 65000.00 );";
     */

   /*
sql = "CREATE TABLE COMPANY1("  \
         "ID INT PRIMARY KEY     NOT NULL," \
         "NAME           TEXT    NOT NULL," \
         "AGE            INT     NOT NULL," \
         "ADDRESS        CHAR(50)," \
         "SALARY         REAL );";

    */

      //"CREATE TABLE COMPANY(ID INT PRIMARY KEY ,NAME TEXT ,AGE INT ,ADDRESS CHAR(50),SALARY REAL);";
   /*Sql=sqlite3_mprintf("insert into players(字段名用逗号隔开) values('%d','%d','%d','%s')",x,y,z,char);
sqlite3_exec(db,Sql,NULL,NULL,&zErrMsg); 
    */

sql=sqlite3_mprintf("insert into COMPANY1 values (2, '%s', 32, 'California', 20001.00)",*str);


   /* Execute SQL statement */

   rc = sqlite3_exec(db, sql, NULL, 0, &zErrMsg);
   if( rc != SQLITE_OK ){
   fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   }else{
      fprintf(stdout, "Table created successfully\n");
   }





   sqlite3_close(db);
}

int main(int argc, char *argv[])
{
  gtk_init(&argc, &argv);
  int tmp_pos;
  GtkWidget *window_zc;
  window_zc = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window_zc), "媒体播放器");
  gtk_widget_show(window_zc);


  GtkWidget *hbox;

hbox = gtk_vbox_new(FALSE, 5);
gtk_widget_show(hbox) ;
 // gtk_widget_show();

gtk_container_add (GTK_CONTAINER (window_zc), hbox);

//添加文本空间

   entry = gtk_entry_new();						// 创建文本输入构件
   gtk_widget_show(entry);
   gtk_box_pack_start(GTK_CONTAINER(hbox),entry,FALSE,FALSE,0);
   gtk_entry_set_max_length(GTK_ENTRY (entry), 50);
                                             // 设置文本输入构件接纳文本最大长度

   gtk_entry_set_text(GTK_ENTRY(entry), "hello");
                      								// 修改文本输入构件中的文本
   tmp_pos = GTK_ENTRY (entry)->text_length;	// 获得文本输入构件中文本长度
   gtk_editable_insert_text (GTK_EDITABLE (entry), " world", -1, &tmp_pos);
   
   GtkWidget *button=gtk_button_new_with_label("提交");
   gtk_widget_show(button);
   gtk_box_pack_start(GTK_BOX(hbox),button,FALSE,FALSE,0);
   
   g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(on_click_button),0);

g_signal_connect(window_zc, "destroy", G_CALLBACK(gtk_main_quit), NULL);
  /*

   */
gtk_main();
  return 0;
}
