#include "mysql.h"


int init_mysql(MYSQL *mysql) {

  if (mysql_init(mysql) == NULL) {
    printf("\nInitialization error\n");
    return 2;
  }
  if (mysql_real_connect(mysql, "localhost", "root", "root",
            "db_fingerprint", 3306, NULL, 0) == NULL)
    {
        fprintf(stderr, "%s\n", mysql_error(mysql));
        mysql_close(mysql);
        printf("Error when init mysql\n");
        return 2;
    }

  return 0;
}
int save_data_to_db(unsigned char *data, size_t data_size,char *finger_type,char *q)
{


  MYSQL con;
  init_mysql(&con);

  // done

  // insert
  int escaped_size = 2 * data_size + 1;
  char chunk[escaped_size];
  mysql_real_escape_string(&con, chunk, (const char*)data, data_size);
  const char* query_template =  "INSERT INTO fingerprints(finger_type, data,users_idusers) VALUES ('%s', '%s','%s')";
  size_t template_len = strlen(query_template);
  int query_buffer_len = template_len + escaped_size  + sizeof(data_size) +sizeof(q) +strlen(finger_type);
  char query[query_buffer_len];
  // testAPI(chunk);
  int query_len = snprintf(query, query_buffer_len, query_template,finger_type, chunk,q);

  if (mysql_real_query(&con, query, query_len))
  {
    printf("Something went wrong when INSERT");
    return 2;
  }

  mysql_close(&con);
  return 0;
}

//int save_data_to_db(unsigned char *data, size_t data_size)
//{


//  MYSQL con;
//  init_mysql(&con);

//  // done

//  // insert
//  int escaped_size = 2 * data_size + 1;
//  char chunk[escaped_size];
//  mysql_real_escape_string(&con, chunk, (const char*)data, data_size);
// // const char* query_template =  "INSERT INTO users(image) VALUES ('%s')";
//  const char* query_template =  "INSERT INTO fingerprints(data_indexfinger) VALUES ('%s')";

//  size_t template_len = strlen(query_template);
//  int query_buffer_len = template_len + escaped_size  +sizeof(data_size);
//  char query[query_buffer_len];
//  // testAPI(chunk);
//  int query_len = snprintf(query, query_buffer_len, query_template,chunk, data_size);

//  if (mysql_real_query(&con, query, query_len))
//  {
//    printf("Something went wrong when INSERT");
//    return 2;
//  }

//  mysql_close(&con);
//  return 0;
//}
