#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

static int callback(void *data, int argc, char **argv, char **azColName){

  int i;

   //   fprintf(stderr, "%s: ", (const char*)data);

        for(i=0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");


   return 0;
}

int main(int argc, char* argv[])
{
  typedef struct _userdata UserData;
struct _userdata{
  char *phone_number[104];
  char *qq_number[104];
  char *password[104];
  int *need_autologin;
  /*need_autologin 的值
    0:不需要
    1:需要
   */
}

   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char *sql;
   char **result;
   int row ,colomn;
   const char* data = "Callback function called";

   /* Open database */
   rc = sqlite3_open("phone_login.db", &db);
   if( rc ){
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      exit(0);
   }else{
      fprintf(stderr, "Opened database successfully\n");
   }

   /* Create SQL statement */
   //   sql = "SELECT * from test2 where ";
   sql="select * from test2 where phone_number=17853309270";

   /* Execute SQL statement */
   rc = sqlite3_get_table(db, sql, &result,&row,&colomn,&zErrMsg);
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   }else if(row<2){
     puts("查询结果为零条");

   }else{
      fprintf(stdout, "Operation done successfully\n");
      UserData *userd=malloc(sizeof(UserData)*row-1);
      UserData *userdata;
      userdata=userd;
      for(int i=0;i<=row;i++){
        userdata->phone_number  =atol(result[i*colomn]);
        userdata->qq_number  =atol(result[i*colomn+1]);
        userdata->password  =atol(result[i*colomn]);
        userdata->need_autologin  =atol(result[i*colomn]);

          /*  char *phone_number=[];
              char *qq_number=[];
              char *password=[];
              int *need_autologin=0;

           */
      }
   }

   sqlite3_close(db);
   return 0;
}
