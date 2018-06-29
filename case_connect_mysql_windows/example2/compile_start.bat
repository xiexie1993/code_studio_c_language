gcc  -c  write_log.c
gcc write_log.o connect_mysql.c   -o connect_mysql  -L ./vendor/mysql-connector-c-noinstall-6.0.2-win32/lib -l ./vendor/mysql-connector-c-noinstall-6.0.2-win32/lib/libmysql