import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;

public class Matrix {
    public BufferedReader BR;
    public FileReader f;


    Matrix(String filename) throws FileNotFoundException {
        f = new FileReader(filename);
        BR = new BufferedReader(this.f);
    }

    public int[][] ReadMatrix() {

        

        return;
    }


}
