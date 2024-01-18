#include<stdio.h>
#include<stdlib.h>
#include"koubun.h"

//ファイルから記号を読み込む関数
int get_token(){
    //ファイルから記号を読み込む
    tmp=ziku[ziku_index];
    ziku_index++;
    return tmp;
}

//記号を一つ戻す関数
void return_token(){
    ziku_index--;
}

//プログラム用のメソッド
void identifier(){

    //解釈単位用のメソッドを呼び出す
    interpretation();
    
    //次の記号を読み込む
    get_token();

    //読み込んだ記号がセミコロンでなければ構文エラー
    if(tmp!=19){
        fprintf(stderr,"プログラム構文エラー\n");
        exit(1);
    }

    return;
}

//解釈単位用のメソッド
void interpretation(){
    
    //読み込んでいる記号が識別子の場合
    if(tmp==1){
        //変数代入のメソッドを呼び出す
        variable_assignment();
    }else if(tmp==2){
        //変数宣言のメソッドを呼び出す
        variable();
    }else if(tmp==3){
        //変数入力のメソッドを呼び出す
        reads();
    }else if (tmp==4 || tmp==5){
        //出力指定のメソッドを呼び出す
        print();
    }else if(tmp==7){
        //repeat文のメソッドを呼び出す
        repeats();
    }else{
        //それ以外の場合は構文エラー
        fprintf(stderr,"解釈単位構文エラー\n");
        exit(1);
    }

}

//変数代入用のメソッド
void variable_assignment(){
    //次の記号を読み込む
    get_token();

    //読み込んだ記号が":="でなければ構文エラー
    if(tmp!=22){
        fprintf(stderr,"変数代入構文エラー\n");
        exit(1);
    }

    //式用のメソッドを呼び出す
    formula();
}

//式用のメソッド
void formula(){

    //次の記号を読み込む
    get_token();

    //読み込んだ記号が"+"か"-"なら次の記号を読み込む
    if(tmp==12 || tmp==13){
        get_token();
    }

    //項用のメソッドを呼び出す
    term();

    while(get_token()==12 || tmp==13){
        get_token();
        term();
    }
    
    return_token();
}

//項のメソッド
void term(){

    //因子用のメソッドを呼び出す
    factor();

    //次の記号を読み込む
    get_token();

    //読み込んだ記号が"*"か"/"か"div"か"%"なら因子用のメソッドを呼び出す
    while(tmp==14 || tmp==15 || tmp==6 || tmp==16){
        get_token();
        factor();
        
        //次の記号を読み込む
        get_token();
    }
    
    //読み込んだ記号を一文字戻す
    return_token();

}

//因子のメソッド
void factor(){

    //読み込んだ記号が"("なら式用のメソッドを呼び出す
    if(tmp==17){
        formula();
        
        //次の記号を読み込む
        get_token();

        //読み込んだ記号が")"でなければ構文エラー
        if(tmp!=18){
            fprintf(stderr,"因子構文エラー\n");
            exit(1);
        }
    }else if(tmp==1){
        //識別子の場合はそのまま次へ
    }else if(tmp==9){
        
    }else if(tmp==10){
        
    }else if(tmp==21){
        //@マークの場合は関数呼び出しのメソッドを呼び出す
        call_fuction();
    }else{
        //それ以外の場合は構文エラー
        fprintf(stderr,"因子構文エラー\n");
        exit(1);
    }

}

//repeat文のメソッド
void repeats(){
    //式用のメソッドを呼び出す
    formula();

    //次の記号を読み込む
    get_token();

    //読み込んだ記号が識別子でなければ構文エラー
    if(tmp!=1){
        fprintf(stderr,"repeat構文エラー\n");
        exit(1);
    }
    //識別子の場合は変数代入のメソッドを呼び出す
    variable_assignment();
}

//変数入力のメソッド
void reads(){
    
        //次の記号を読み込む
        get_token();

        //読み込んだ記号が"("でなければ構文エラー
        if(tmp!=17){
            fprintf(stderr,"変数入力構文エラー\n");
            exit(1);
        }

        //次の記号を読み込む
        get_token();
    
        //読み込んだ記号が識別子でなければ構文エラー
        if(tmp!=1){
            fprintf(stderr,"変数入力構文エラー\n");
            exit(1);
        }
    
        //次の記号を読み込む
        get_token();

        //読み込んだ記号が")"でなければ構文エラー
        if(tmp!=18){
            fprintf(stderr,"変数入力構文エラー\n");
            exit(1);
        }
}

//式の並び用のメソッド
void formula_list(){
    
    //次の記号を読み込む
    get_token();

    //読み込んだ記号が")"ならば呼び出し元に戻る
    if(tmp==18){
        //読み込んだ記号をファイルに戻す
        return_token();
        return;
    }
    //一度読み込んだ記号をファイルに戻す
    return_token();

    //式用のメソッドを呼び出す
    formula();

    //次の記号を読み込む
    get_token();

    //読み込んだ記号が","の間は式用のメソッドを呼び出す
    while(tmp==20){
        formula();
        get_token();
    }

    //読み込んだ記号をファイルに戻す
    return_token();

    return;

}

//関数呼び出しのメソッド
void call_fuction(){    
    //次の記号を読み込む
    get_token();

    //読み込んだ記号が識別子でなければ構文エラー
    if(tmp!=1){
        fprintf(stderr,"関数呼び出し構文エラー\n");
        exit(1);
    }

    //次の記号を読み込む
    get_token();

    //読み込んだ記号が"("でなければ構文エラー
    if(tmp!=17){
        fprintf(stderr,"関数呼び出し構文エラー\n");
        exit(1);
    }

    //式の並び用のメソッドを呼び出す
    formula_list();

    //次の記号を読み込む
    get_token();

    //読み込んだ記号が")"でなければ構文エラー
    if(tmp!=18){
        fprintf(stderr,"関数呼び出し構文エラー\n");
        exit(1);
    }
}

//出力単位の並びのメソッド
void print_list(){

    //次の記号を読み込む
    get_token();

    //読み込んだ記号が")"ならば呼び出し元に戻る
    if(tmp==18){
        //読み込んだ記号をファイルに戻す
        return_token();
        return;
    }
    //一度読み込んだ記号をファイルに戻す
    return_token();

    //出力単位のメソッドを呼び出す
    print_unit();

    //次の記号を読み込む
    get_token();

    //読み込んだ記号が","の間は出力単位のメソッドを呼び出す
    while(tmp==20){
        print_unit();
        get_token();
    }

    //読み込んだ記号をファイルに戻す
    return_token();

    return;

}

//出力単位のメソッド
void print_unit(){

    //次の記号を読み込む
    get_token();

    //読み込んだ記号が文字列の場合は終端なので呼び出し元に戻る
    if(tmp==23){
        return;
    }

    //読み込んだ記号が式のファースト集合に含まれていれば式用のメソッドを呼び出す
    if(tmp==1 || tmp==9 || tmp==10 || tmp==12 || tmp==13 || tmp==17  || tmp==21 ){
        //読み込んだ記号をファイルに戻す
        return_token();
        formula();
    }
}

//関数名のメソッド
void fuction_name(){
    
    //次の記号を読み込む
    get_token();
    
    //読み込んだ記号が識別子でなければ構文エラー
    if(tmp!=1){
        fprintf(stderr,"関数名構文エラー\n");
        exit(1);
    }
}

//出力指定の変数
void print(){
    
    //次の記号を読み込む
    get_token();
    
    //読み込んだ記号が"("でなければ構文エラー
    if(tmp!=17){
        fprintf(stderr,"出力指定構文エラー\n");
        exit(1);
    }

    //出力単位の並びのメソッドを呼び出す
    print_list();

    //次の記号を読み込む
    get_token();

    if(tmp!=18){
        fprintf(stderr,"出力指定構文エラー\n");
        exit(1);
    }


}

//変数宣言を読み取った際に呼び出される関数
void variable(){

    //次の記号を読み込む
    get_token();

    //読み込んだ文字が識別子でなければエラー
    if(tmp!=1){
        fprintf(stderr,"変数宣言構文エラー\n");
        exit(1);
    }

    //次の記号を読み込む
    get_token();

    //読み込んだも記号が":="でない場合
    if(tmp!=22){
        //読み込んだ記号をファイルに戻す
        return_token();
        return;
    }

    //式用のメソッドを呼び出す
    formula();

}


int main(void){
    FILE *fp;
    if((fp=fopen("result.txt","r"))==NULL){
        fprintf(stderr,"result.txtがありません\n");
    }

    //ファイルからすべての記号を読み込む
    while(fscanf(fp,"%d",&tmp)!=EOF){
        ziku[ziku_index]=tmp;
        ziku_index++;
    }

    ziku[ziku_index]=EOF;

    ziku_index=0;


    while((get_token())!=EOF){
        //読み込んだ記号をプログラムのFirst集合でなければ構文エラー
        if(tmp!=1 && tmp!=2 && tmp!=3 && tmp!=4 && tmp!=5 && tmp!=7){
            printf("%d\n",tmp);
            fprintf(stderr,"構文エラー\n");
            exit(1);
        }
        identifier();
    }

    fclose(fp);

    printf("構文は正しい\n");

    return 0;

}
