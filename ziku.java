import java.io.File;
import java.io.FileReader;
import java.io.IOException;
public class ziku {
    public static void main(String[] args) {
        String content="";
        int tmp="";
        int line=1;
        try {
            File file=new File("sample-utf-8.m");
            if(file.exists()){
                FileReader fr= new FileReader(file);
                while((tmp=fr.read())!=-1){
                    if(tmp=='\n'){
                        line++;
                        continue;
                    }

                    if(tmp=='>' || tmp=='<'){

                    }
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    
}