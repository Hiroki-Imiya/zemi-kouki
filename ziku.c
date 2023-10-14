#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
            strcpy(string[n],tmp);
            n++;
            continue;
        }
        if(tmp=='>' || tmp=='<'){
            char tmp2=malloc(sizeof(char));
            tmp2=fgetc(p);
            if(tmp2=='='){
                strcpy(string[n],tmp);
                n++;
                strcpy(string[n],tmp2);
                n++;
            }else{
                ungetc(tmp2,p);
                strcpy(string[n],tmp);
                n++;
            }
            free(tmp2);
            continue;
        }
    }
}