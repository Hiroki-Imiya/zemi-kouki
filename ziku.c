#include<stdio.h>
#include"bstree.h"

#define MAX_shafts 10000
#define MAX_STRING 100
struct ziku{
    int id;
    char *mold;
    int line;
    char *content;
};

typedef struct ziku SHAFT;

int main(int argc,char *argv[]){
    if(argc!=2){
        fprintf(stderr,"ファイルを1つのみ指定してください\n");
        return 1;
    }
	FILE *p;
    SHAFT shafts[MAX_shafts];
    if(fopen(p,argv[1])==NULL){
        fprintf(stderr,"ファイルのオープンが出来ません\n");
        return 1;
    }
    char tmp;
    char string[MAX_STRING];
    int n=0;
    while(tmp=fgetc(p)!=EOF){
        if((tmp>='a' && tmp<='z') || (tmp>='A' && tmp<='Z')){
            string[n]=tmp;
            n++;
            continue;
        }
        if(tmp=='>' || tmp=='<'){
            char tmp2=
        }
    }
}