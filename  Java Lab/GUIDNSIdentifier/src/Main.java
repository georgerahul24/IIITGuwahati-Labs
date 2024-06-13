import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.net.InetAddress;
import java.net.InetSocketAddress;
import java.net.UnknownHostException;
import java.net.spi.InetAddressResolver;






class Listener implements ActionListener{

    @Override
    public void actionPerformed(ActionEvent e) {
        String s = GUI.jTextField.getText();

        try {
            System.out.println(InetAddress.getByName(s));
            GUI.jLabel.setText(String.valueOf(InetAddress.getByName(s)));

        } catch (UnknownHostException ex) {
            throw new RuntimeException(ex);
        }


    }
}

class GUI {
    static JFrame jFrame;
    static JPanel jPanel;
    static JTextField jTextField;
    static JButton jButton;
    static JLabel jLabel;

    GUI() {
        jFrame = new JFrame("DNS Address");
        jFrame.setSize(300, 300);
        jPanel = new JPanel(new GridLayout(3,1));
        jPanel.setSize(300, 300);

        jTextField = new JTextField();
        jButton = new JButton("Get IP Address");
        jButton.addActionListener(new Listener());

        jLabel = new JLabel();
        jPanel.add(jTextField);
        jPanel.add(jButton);
        jPanel.add(jLabel);
        jFrame.add(jPanel);
        jFrame.setVisible(true);

    }
}


public class Main {
    public static void main(String[] args) {
        System.out.println("Hello world!");
        GUI gui = new GUI();
    }
}