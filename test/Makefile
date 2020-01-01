
all:$(OBJ)
        gcc  $(cat ./name_for_c)  -o demo   -lgtk-x11-2.0 -lgdk-x11-2.0 -lpangocairo-1.0 -latk-1.0 -lcairo -lgdk_pixbuf-2.0 -lgio-2.0 -lpangoft2-1.0 -lpango-1.0 -lgobject-2.0 -lglib-2.0 -lfontconfig -lfreetype -lsqlite3 -lgstreamer-1.0  `pkg-config --cflags --libs gtk+-2.0`  -I/usr/include/gstreamer-1.0/ -g

$.o:%.c
        $(CC)  -c $< -o $@ GTKV



clean:
        rm $(OBJ) $(BIN)
    
    gcc  $(cat ./name_for_c)  -o demo   -lgtk-x11-2.0 -lgdk-x11-2.0 -lpangocairo-1.0 -latk-1.0 -lcairo -lgdk_pixbuf-2.0 -lgio-2.0 -lpangoft2-1.0 -lpango-1.0 -lgobject-2.0 -lglib-2.0 -lfontconfig -lfreetype -lsqlite3 -lgstreamer-1.0  `pkg-config --cflags --libs gtk+-2.0`  -I/usr/include/gstreamer-1.0/ -g
  #   gdb ./demo




