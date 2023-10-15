#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
    int node=0;
    if(argc!=2){
        fprintf(stderr,"ファイルを1つのみ指定してください\n");
        return 1;
    }
	FILE *p;
    SHAFT shafts[MAX_shafts];
    if((p=fopen(argv[1],"r"))==NULL){
        fprintf(stderr,"ファイルのオープンが出来ません\n");
        return 1;
    }
    char tmp;
    char *string=malloc(sizeof(char)*MAX_STRING);
    int n=0;
    while((tmp=fgetc(p))!=EOF){
        if(tmp=='\n' || tmp==';'){
            continue;
        }
        if(tmp=='>' || tmp=='<'){
            char tmp2;
            tmp2=fgetc(p);
            if(tmp2=='='){
                strcpy(&string[n],&tmp);
                n++;
                strcpy(&string[n],&tmp2);
                n++;
            }else{
                ungetc(tmp2,p);
                strcpy(&string[n],&tmp);
                n++;
            }
            continue;
        }
        if(tmp==' ' || tmp=='(' || tmp==')'){
            if(n!=0){
                string[n]='\0';
                shafts[node].content=malloc(sizeof(char)*n);
                strcpy(shafts[node].content,string);
                //printf("%s\n",string);
                //printf("%s\n",shafts[node].content);
                node++;
                free(string);
                string=malloc(sizeof(char)*MAX_STRING);
                n=0;
            }
            continue;
        }
        if(tmp=='#'){
            while((tmp=fgetc(p))!='\n'){
            }
            continue;
        }
        if(tmp=='\"'){
            while((tmp=fgetc(p))!='\"'){
                strcpy(&string[n],&tmp);
                n++;
            }
            string[n]='\0';
            shafts[node].content=malloc(sizeof(char)*n);
            strcpy(shafts[node].content,string);
            //printf("%s\n",string);
            //printf("%s\n",shafts[node].content);
            node++;
            free(string);
            string=malloc(sizeof(char)*MAX_STRING);
            n=0;
            continue;
        }
        if(tmp=='+'||tmp=='-'||tmp=='*'||tmp=='/'){
            if(n!=0){
                string[n]='\0';
                shafts[node].content=malloc(sizeof(char)*n);
                strcpy(shafts[node].content,string);
                node++;
                free(string);
                string=malloc(sizeof(char)*MAX_STRING);
                n=0;
            }
            strcpy(&string[n],&tmp);
            n++;
            string[n]='\0';
            shafts[node].content=malloc(sizeof(char)*n);
            strcpy(shafts[node].content,string);
            node++;
            free(string);
            string=malloc(sizeof(char)*MAX_STRING);
            n=0;
            continue;
        }
        strcpy(&string[n],&tmp);
        n++;
    }
    for(int i=0;i<node;i++){
        printf("%s\n",shafts[i].content);
    }
    return 0;
}