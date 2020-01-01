#ifndef MEDIALIB_H_
#define MEDIALIB_H_
#define MAX_TITLE_LENGTH 512
#define MAX_ATRIST_LENGTH 512
#define MAX_ALBUM_LENGTH 256
#define MAX_GENRE_LENGTH 256
#define MAX_PATH_LENGTH 4096
typedef struct _medialib Medialib;
struct _medialib{
  char title[MAX_TITLE_LENGTH];
  char atrist[MAX_ATRIST_LENGTH];
  char album[MAX_ATRIST_LENGTH];
  char genre[MAX_GENRE_LENGTH];
  double record_time;
  char filepath[MAX_PATH_LENGTH];
  
};
typedef struct _node_t node_t;
struct _node_t{
  Medialib item;
  node_t *p;
  
};

typedef struct _link_t link_t;
struct _link_t{
  node_t *np;
  int length;
};

typedef enum find_cond {
                BY_TITLE,
                BY_ARTIST,
                BY_ABLUM,
                BY_GENRE,
                BY_FILEPATH

}_find_cond;






#endif


