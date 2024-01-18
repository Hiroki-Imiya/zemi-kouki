#include<stdio.h>
#include"shaft.h"

int main(int argc,char *argv[]){
    int node=0;
    int lin=1;
    if(argc!=2){
        fprintf(stderr,"ファイルを1つのみ指定してください\n");
        return 1;
    }
	FILE *p;
    SHAFT shafts[MAX_shafts];
    FILE *resultFile;
    resultFile=fopen("result.txt","w");
    if((p=fopen(argv[1],"r"))==NULL){
        fprintf(stderr,"ファイルのオープンが出来ません\n");
        return 1;
    }
    char tmp;
    char *string=malloc(sizeof(char)*MAX_STRING);
    int n=0;
    while((tmp=fgetc(p))!=EOF){

        if(tmp=='\n'){  
            lin++;                    //改行の場合
            continue;
        }

        if(tmp=='>' || tmp=='<'){           //大なりまたは小なりの場合
            char tmp2;
            tmp2=fgetc(p);
            if(tmp2=='='){                  //大なりまたは小なりの次が＝の場合
                strcpy(&string[n],&tmp);
                n++;
                strcpy(&string[n],&tmp2);   //そうでない場合
                n++;
            }else{
                ungetc(tmp2,p);
                strcpy(&string[n],&tmp);
                n++;
            }
            continue;
        }

        if(tmp==' '){
            if(n!=0){
                create_shaft(shafts,node,string,n,lin);
                //printf("%s\n",string);
                //printf("%s\n",shafts[node].content);
                node++;
                free(string);
                string=malloc(sizeof(char)*MAX_STRING);
                n=0;
            }
            continue;
        }

        if(tmp=='#'){                       //米印の場合
            while((tmp=fgetc(p))!='\n'){
            }
            lin++;
            continue;
        }

        if(tmp=='\"'){                      //ダブルコーテーションの場合
            while((tmp=fgetc(p))!='\"'){    //次のダブルコーテーションまで読み込む
                strcpy(&string[n],&tmp);
                n++;
            }
            create_shaft(shafts,node,string,n,lin);
            shafts[node].id=11;
            //printf("%s\n",string);
            //printf("%s\n",shafts[node].content);
            node++;
            free(string);
            string=malloc(sizeof(char)*MAX_STRING);
            n=0;
            continue;
        }

        if(tmp=='+'||tmp=='-'||tmp=='*'||tmp=='/' || tmp==':' || tmp=='(' || tmp==')' || tmp==',' ||tmp==';' ||tmp=='%' || tmp=='@'){//演算子の場合
            if(n!=0){
                create_shaft(shafts,node,string,n,lin);
                node++;
                free(string);
                string=malloc(sizeof(char)*MAX_STRING);
                n=0;
            }
            if(tmp!=' '){
                strcpy(&string[n],&tmp);
                n++;
            }
            if(tmp==':'){
                if((tmp=fgetc(p))=='='){
                    strcpy(&string[n],&tmp);
                    n++;
                }else{
                    ungetc(tmp,p);
                }
            }
            create_shaft(shafts,node,string,n,lin);
            node++;
            free(string);
            string=malloc(sizeof(char)*MAX_STRING);
            n=0;
            continue;
        }

        strcpy(&string[n],&tmp);                    //上記のいずれでもない場合
        n++;
    }

    for(int i=0;i<node;i++){
        if(shafts[i].id==0){
            set_id(shafts,i);
        }
    }
    
    set_mold(shafts,node);

    print_to_file(shafts,node,resultFile);

    /*
    int m;
    printf("表示の仕方を入力してください:");
    scanf("%d",&m);
    switch(m){
        case 1:
            print_id(shafts,node);
            break;
        case 2:
            print_id_mold(shafts,node);
            break;
        case 3:
            print_line_id_mold(shafts,node);
            break;
        case 4:
            print_all(shafts,node);
            break;
        default:
            printf("1～4で入力してください\n");
    }
    */
    fclose(resultFile);
    
    return 0;
}