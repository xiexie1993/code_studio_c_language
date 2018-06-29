gcc  -c  write_log.c
gcc -Iinclude -Llib write_log.o connect_mysql.c -llibmysql  -o connect_mysql