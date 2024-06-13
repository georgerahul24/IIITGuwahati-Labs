import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {

        FileHandler f = new FileHandler("output.ppm");
        int image_width = 256, image_height = 256;
        Color c = new Color(43, 25, 46);
        f.writeln("P3");
        f.write("%d %d\n".formatted(image_width, image_height));
        f.write(255);
        for (int j = image_width - 1; j >= 0; --j) {
            for (int i = image_height - 1; i >= 0; --i) {
                f.write(new Color((double) i / (image_width - 1) * 255.99, (double) j / (image_height - 1) * 255.99, 0.25 * 255.99));
            }
        }
        f.write(c);
        f.flush();





    }
}