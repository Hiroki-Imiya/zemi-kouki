//ファイルから読み込んだ記号
int tmp;

//ファイルから読み込んだ記号を保存する変数
int ziku[1000];

//配列の添字
int ziku_index=0;

//次の記号を読み込む関数
int get_token();

//記号を一つ戻す関数
void return_token();

//プログラム用のメソッド
void identifier();

//解釈単位用のメソッド
void interpretation();

//変数代入用のメソッド
void variable_assignment();

//出力指定用のメソッド
void print();

//変数宣言用のメソッド
void variable();

//関数名のメソッド
void fuction_name();

//出力単位の並びのメソッド
void print_list();

//出力単位のメソッド
void print_unit();

//関数呼び出しのメソッド
void call_fuction();

//式の並び用のメソッド
void formula_list();

//変数入力のメソッド
void reads();

//repeat文のメソッド
void repeats();

//因子のメソッド
void factor();

//項のメソッド
void term();

//式のメソッド
void formula();