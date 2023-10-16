#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_shafts 10000
#define MAX_STRING 100
struct ziku{
    int id;
    char *mold;
    int line;
    char *content;
};

typedef struct ziku SHAFT;

void create_shaft(SHAFT *shafts,int node,char *string,int n,int lin);

void set_id(SHAFT *shafts,int node);

void set_mold(SHAFT *shafts,int node);

void print_id(SHAFT *shafts,int node);

void print_id_mold(SHAFT *shafts,int node);

void print_line_id_mold(SHAFT *shafts,int node);

void print_all(SHAFT *shafts,int node);