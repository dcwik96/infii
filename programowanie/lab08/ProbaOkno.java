import java.awt.EventQueue;
import javax.swing.JFrame;
import javax.swing.JButton;
import java.awt.event.*;
import javax.swing.JLabel;
import java.awt.Color;
import java.awt.Font;

class Okno extends JFrame implements ActionListener
{
  JButton guzikOff, guzikData;
  JLabel data;
  JButton zrobGuzik(int x, int y, int w, int h, String t){
    JButton b = new JButton(t);
    b.setBounds(x,y,w,h);
    b.addActionListener(this);
    return b;
  }
  Okno(){
    super("Okno");
    //setTitle("Tytul"); nie potrzeba bo mamy juz w super
    setLocation(40,40);
    setSize(500,400);
    setVisible(true);
    //setBounds(40,40,500,400); zamiast size i location
    setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    setLayout(null);
    //guzikOff = new JButton("Zakończ");
    //guzikOff.setBounds(10,10,150,30);
    //guzikOff.addActionListener(this);
    guzikOff = zrobGuzik(10,10,150,30,"Zakończ");
    add(guzikOff);
    guzikData = zrobGuzik(10,50,150,30,"Pokaż Date");
    add(guzikData);
    data = new JLabel("<--ciśnij");
    data.setBounds(170,50,200,30);
    add(data);
  }
  public void actionPerformed(ActionEvent e){
    Object source = e.getSource();
    if( source == guzikOff ){ this.dispose(); }
    else if( source == guzikData ) {
      //System.out.println("Gdzie data");
      data.setText( new java.util.Date().toString() );
      data.setForeground( Color.BLUE );
      data.setFont( new Font("Monospace",Font.BOLD,12) );
    }
  }
}

public class ProbaOkno
{
  public static void main(String[] args) {
    EventQueue.invokeLater( new Runnable(){
      public void run(){
        new Okno();
      }
    });
  }
}
