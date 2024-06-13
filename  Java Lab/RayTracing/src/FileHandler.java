import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class FileHandler {
    public FileWriter f;

    FileHandler(String filename) throws IOException {
        this.f = new FileWriter(filename);
    }

    public void write(String data) throws IOException {
        this.f.write(data);
    }

    public void writeln(String data) throws IOException {
        this.f.write(data);
        this.f.write("\n");
    }

    public void write(Color rgb) throws IOException {
        this.f.write("%d %d %d\n".formatted((int) rgb.r, (int) rgb.g, (int) rgb.b));
    }

    public void write(int a) throws IOException {
        this.f.write("%d\n".formatted(a));
    }


    public void flush() throws IOException {
        this.f.flush();
    }


}
