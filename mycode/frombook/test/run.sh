#!/bin/bash

function show_table(){
	sqlite3 -init upgradeDB.sql test.db << EOF
	select * from COMPANY1;
	.quit		

EOF

}
function run_gcc_and_demo(){
    rm demo

    
    # ./demo
    
    gcc  $(cat ./name_for_c)  -o demo   -lgtk-x11-2.0 -lgdk-x11-2.0 -lpangocairo-1.0 -latk-1.0 -lcairo -lgdk_pixbuf-2.0 -lgio-2.0 -lpangoft2-1.0 -lpango-1.0 -lgobject-2.0 -lglib-2.0 -lfontconfig -lfreetype -lsqlite3 -lgstreamer-1.0  `pkg-config --cflags --libs gtk+-2.0`  -I/usr/include/gstreamer-1.0/ -g
  #   gdb ./demo
  ./demo

}





cmd=$1

if [ ! -n "$1" ] ;then
    # 编译并运行
    run_gcc_and_demo
else
    #修改文件名 然后 编译运行
    echo $1 > name_for_c
    run_gcc_and_demo
fi



