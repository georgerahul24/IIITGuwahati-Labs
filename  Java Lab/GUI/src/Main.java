import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

class Listener implements ActionListener {


    @Override
    public void actionPerformed(ActionEvent e) {
        new Main();
        
    }
}
public class Main {
    public static void main(String[] args) {
        JFrame jFrame = new JFrame("Hello World");

        JPanel jPanel = new JPanel(new GridLayout(1,3));

        jFrame.setSize(300, 200); // Set size of the frame

        JButton jButton1 = new JButton("Click Me");
        jButton1.addActionListener(new Listener());
        jPanel.add(jButton1);

        JLabel jLabel = new JLabel("Sample Text");
        jPanel.add(jLabel);

        jFrame.add(jPanel);
        jFrame.setVisible(true); // Make the frame visible
    }



}
