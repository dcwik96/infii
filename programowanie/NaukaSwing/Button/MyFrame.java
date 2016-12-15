import javax.swing.JFrame;
import javax.swing.JButton;
import java.awt.FlowLayout;

public class MyFrame extends JFrame {
  public MyFrame(){
    super("Not Hello World");
    setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    setSize(300,100);
    setLocation(50,50);
    setLayout(new FlowLayout(FlowLayout.LEFT,100,100));

    add(new JButton("Przycisk 1"));
    add(new JButton("Przycisk 2"));
    add(new JButton("Przycisk 3"));

    setVisible(true);
  }
}
