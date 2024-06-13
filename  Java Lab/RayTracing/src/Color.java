public class Color extends ColorInterface {
    Color(double r, double g, double b) {
        super(r, g, b);
    }
}

class ColorInterface {
    public double r, g, b;

    ColorInterface(double r, double g, double b) {
        this.r = r;
        this.g = g;
        this.b = b;
    }


}