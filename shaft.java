public class shaft {
    int id;
    String mold;
    int line;
    String content;

    public shaft(int line,String content){
        this.line=line;
        this.content=content;
        this.id=Check_id(content);
        this.mold=Check_mold(this.id);
    }

    private int Check_id(String content){
        int i=0;
        return i;
    }

    private String Check_mold(int i){
        String mol="";
        return mol;
    }
}