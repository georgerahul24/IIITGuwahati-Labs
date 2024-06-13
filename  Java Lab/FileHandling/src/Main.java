import java.io.*;
import java.util.ArrayList;


public class Main implements Serializable {
    public static void main(String[] args) throws IOException, ClassNotFoundException {
        FileReader f = new FileReader("src/test.txt");
        BufferedReader br = new BufferedReader(f);

        String line ="";

        while ((line=br.readLine())!=null){
            if(!line.matches("^[a-zA-Z]+ [a-zA-z]+, [0-9]+, [0-9]+$")){
                System.out.println(line);
            }
        }




    }
}