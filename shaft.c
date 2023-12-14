#include<stdio.h>
#include"shaft.h"

void create_shaft(SHAFT *shafts,int node,char *string,int n,int lin){//内容を挿入
    string[n]='\0';
    shafts[node].content=malloc(sizeof(char)*n);
    strcpy(shafts[node].content,string);
    shafts[node].line=lin;
}

void set_id(SHAFT *shafts,int node){        //トークンに対応する番号を挿入
    if(strcmp(shafts[node].content,"+")==0){
        shafts[node].id=12;
        return;
    }
    if(strcmp(shafts[node].content,"-")==0){
        shafts[node].id=13;
        return;
    }
    if(strcmp(shafts[node].content,"*")==0){
        shafts[node].id=14;
        return;
    }
    if(strcmp(shafts[node].content,"/")==0){
        shafts[node].id=15;
        return;
    }
    if(strcmp(shafts[node].content,"%")==0){
        shafts[node].id=16;
        return;
    }
    if(strcmp(shafts[node].content,"(")==0){
        shafts[node].id=17;
        return;
    }
    if(strcmp(shafts[node].content,")")==0){
        shafts[node].id=18;
        return;
    }
    if(strcmp(shafts[node].content,";")==0){
        shafts[node].id=19;
        return;
    }
    if(strcmp(shafts[node].content,",")==0){
        shafts[node].id=20;
        return;
    }
    if(strcmp(shafts[node].content,"@")==0){
        shafts[node].id=21;
        return;
    }
    if(strcmp(shafts[node].content,":=")==0){
        shafts[node].id=22;
        return;
    }
    if(strcmp(shafts[node].content,"var")==0){
        shafts[node].id=2;
        return;
    }else if(strcmp(shafts[node].content,"read")==0){
        shafts[node].id=3;
        return;
    }
    if(strcmp(shafts[node].content,"print")==0){
        shafts[node].id=4;
        return;
    }
    if(strcmp(shafts[node].content,"println")==0){
        shafts[node].id=5;
        return;
    }
    if (strcmp(shafts[node].content,"div")==0){
        shafts[node].id=6;
        return;
    }
    if(strcmp(shafts[node].content,"repeat")==0){
        shafts[node].id=7;
        return;
    }
    int len=strlen(shafts[node].content);
    int cnt=0;
    int flag=1;
    int mb_flag=0;
    for(int i=0;i<len;i++){
        if(isdigit(shafts[node].content[i])){
            cnt++;
        }
    }
    if(cnt==len){
        shafts[node].id=9;
        return;
    }
    for(int i=0;i<len;i++){
        if(shafts[node].content[i]=='.'){
            for(int j=0;j<i;j++){
                if(isdigit(shafts[node].content[j])==0){
                    flag=0;
                }
            }
            for(int l=i+1;l<len;l++){
                if(isdigit(shafts[node].content[l])==0){
                    flag=0;
                }
            }
            if(flag==1){
                shafts[node].id=10;
                return;
            }
        }
    }
    for(int i=0;i<len;i++){
        if((mblen(&shafts[node].content[i],1))!=1){
            mb_flag=1;
        }
    }
    if(mb_flag==1){
        shafts[node].id=11;
        return;
    }
    shafts[node].id=1;
    return;
}

void set_mold(SHAFT *shafts,int node){
    for(int i=0;i<node;i++){
        shafts[i].mold=malloc(sizeof(char)*MAX_STRING);
        switch (shafts[i].id){
        case 1:
            strcpy(shafts[i].mold,"TK_IDENTIFIER");
            break;
        case 2:
            strcpy(shafts[i].mold,"TK_VAR");
            break;

        case 3:
            strcpy(shafts[i].mold,"TK_READ");
            break;
        
        case 4:
            strcpy(shafts[i].mold,"TK_PRINT");
            break;

        case 5:
            strcpy(shafts[i].mold,"TK_PRINTLN");
            break;
        
        case 6:
            strcpy(shafts[i].mold,"TK_DIV");
            break;

        case 7:
            strcpy(shafts[i].mold,"TK_REPEAT");
            break;

        case 9:
            strcpy(shafts[i].mold,"TK_INTEGER");
            break;

        case 10:
            strcpy(shafts[i].mold,"TK_REAL_NUMBER");
            break;

        case 11:
            strcpy(shafts[i].mold,"TK_STRING");
            break;
        
        case 12:
            strcpy(shafts[i].mold,"TK_PLUS");
            break;

        case 13:
            strcpy(shafts[i].mold,"TK_MINUS");
            break;

        case 14:
            strcpy(shafts[i].mold,"TK_ASUTA");
            break;

        case 15:
            strcpy(shafts[i].mold,"TK_SURASHU");
            break;

        case 16:
            strcpy(shafts[i].mold,"TK_PASENTO");
            break;

        case 17:
            strcpy(shafts[i].mold,"TK_L_PAR");
            break;

        case 18:
            strcpy(shafts[i].mold,"TK_R_PAR");
            break;

        case 19:
            strcpy(shafts[i].mold,"TK_SEMIKORON");
            break;

        case 20:
            strcpy(shafts[i].mold,"TK_KANMA");
            break;

        case 21:
            strcpy(shafts[i].mold,"TK_ATTOMA-KU");
            break;

        case 22:
            strcpy(shafts[i].mold,"TK_EQUAL");
            break;
        default:
            printf("error\n");
            break;
        }
    }
}

void print_id(SHAFT *shafts,int node){
    for(int i=0;i<node;i++){
        printf("%-2d\n",shafts[i].id);
    }
}

void print_id_mold(SHAFT *shafts,int node){
    for(int i=0;i<node;i++){
        printf("%-2d\t%s\n",shafts[i].id,shafts[i].mold);
    }
}

void print_line_id_mold(SHAFT *shafts,int node){
    for(int i=0;i<node;i++){
        printf("%-2d\t%-2d\t%s\n",shafts[i].line,shafts[i].id,shafts[i].mold);
    }
}

void print_all(SHAFT *shafts,int node){
    for(int i=0;i<node;i++){
        if(shafts[i].id==1 || (shafts[i].id>=9 && shafts[i].id<=11)){
             printf("%-2d\t%-2d\t%s\t%s\n",shafts[i].line,shafts[i].id,shafts[i].mold,shafts[i].content);
        }else {
            printf("%-2d\t%-2d\t%s\n",shafts[i].line,shafts[i].id,shafts[i].mold);
        }
    }
}

void print_to_file(SHAFT *shafts,int node,FILE *resultFile){
    for(int i=0;i<node;i++){
        fprintf(resultFile,"%d\n",shafts[i].id);
    }
}