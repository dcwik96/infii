import java.awt.Color;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextArea;

public class Test
{
  public static void main(String[] args)
  {
    new Testowe();
  }
}
class Testowe extends JFrame implements ActionListener
//dziedziczymy po iframe, dzięki temu możemy przesłaniać wszystkie jej metody
//implementujemy interfejs actionlistener, ktory da nam niezbedna metode
{
  JButton[] numer = new JButton[10]; // 10 klawiszy od 0 do 9
  JButton[] operatory = new JButton[6];

  JPanel panel_numerow = new JPanel(new GridLayout(4,3)); //jpanel to kontener na kontrolki a gridlayout to sposob w jaki maja byc wyswietlone
  JPanel panel_operatorow = new JPanel(new GridLayout(5,1));

  JTextArea wynik = new JTextArea();
  String[] bufor = {"","",""}; //pierwsza liczba,potem operator,potem liczba

  public Testowe()
  {
    this.setSize(200,350); //domyślny rozmiar to 200x200, można rozszerzać, odwołuję się po referencji this po to by wyświetliła mi się pomocna lista komend
    this.setResizable(false); //blokujemy rozszerzanie się
    this.TworzOperatory();
    this.TworzPanelNumerow();
    this.TworzWszystko();
    this.setVisible(true); //wyświetlamy okno
    this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); //domyślna operacja zamknięcia
  }
  private void TworzPanelNumerow()
  {
    for(int i = 0;i < numer.length;++i)
    {
      numer[i] = new JButton(String.valueOf(i)); //String.valueOf(i) konwersja int na klase String
      numer[i].addActionListener(this); //ustawiamy actionlistener, czyli reakcje na akcje zwizana z tym przyciskiem
      panel_numerow.add(numer[i]); //wrzucamy referencje do przycisk numer[i]
    }
  }
  private void TworzOperatory()
  {
    operatory[0] = new JButton("+");
    operatory[1] = new JButton("-");
    operatory[2] = new JButton("*");
    operatory[3] = new JButton("/");
    operatory[4] = new JButton("=");
    operatory[5] = new JButton("C");
    for(JButton operator : operatory) //przyklad petli foreach w javie
    {
      operator.addActionListener(this); //dodajemy do referencji actionlistener
      this.panel_operatorow.add(operator);
    }
  }
  private void TworzWszystko()
  {
    this.setLayout(null); //ustawiamy wartosc panelu na null, poniewaz z wlaczonym panelem nie mozemy korzystac z bounds kontrolek

    this.panel_numerow.setBounds(30, 80, 130, 130);
    this.panel_operatorow.setBounds(30,220,130,130);

    this.wynik.setBorder(BorderFactory.createLineBorder(Color.black)); //tworzymy obramowanie dla pola tekstowego
    this.wynik.setBounds(0, 0, this.getWidth(), 35);//ustawiamy boundsy dla pola tekstowego

    this.add(this.wynik);
    this.add(this.panel_operatorow);
    this.add(this.panel_numerow);
  }
  private double PrzeliczBufor(String operator) //wylicza wyrazenie z 2 argumentow
  {
    if(!bufor[0].equals("") && !bufor[2].equals(""))
    {
      if(operator.equals("+"))
      {
        return Double.valueOf(bufor[0])+Double.valueOf(bufor[2]);
      }else if(operator.equals("-"))
      {
        return Double.valueOf(bufor[0])-Double.valueOf(bufor[2]);
      }else if(operator.equals("*"))
      {
        return Double.valueOf(bufor[0])*Double.valueOf(bufor[2]);
      }else if(operator.equals("/"))
      {
        return Double.valueOf(bufor[0])/Double.valueOf(bufor[2]);
      }else return -1;
    }else return -1;
  }
  private void Czysc()
  {
    bufor[0] = bufor[1] = bufor[2] = ""; //tak tez mozna :-)
    this.wynik.setText("");
  }
    //interfejsy to inaczej klasy abstrackcyjne i nie maja definicji metod, tak wiec musimy obowiazkowo umiescic je w kodzie i przeslonic
  public void ObliczIWyswietl()
  {
    this.wynik.setText(String.valueOf(this.PrzeliczBufor(bufor[1])));
    this.bufor[0] = this.wynik.getText();
    this.bufor[1] = "";
    this.bufor[2] = "";
  }
  @Override
  public void actionPerformed(ActionEvent e)
  {
    for(JButton przycisk : this.operatory)
    {
      if(e.getSource().equals(przycisk))
      {
        if(!przycisk.getText().equals("=") && !przycisk.getText().equals("C"))
        {
          this.wynik.setText("");
          bufor[1] = przycisk.getText();
        }else if(przycisk.getText().equals("="))
        {
          this.ObliczIWyswietl();
        }else
        {
          this.Czysc();
        }
      break;
      }
    }
    for(JButton przycisk : this.numer)
    {
      if(e.getSource().equals(przycisk))
      {
        if(bufor[1].equals(""))
        {
          bufor[0] = bufor[0]+przycisk.getText();
          this.wynik.setText(bufor[0]);
          break;
        }else
        {
          bufor[2] = bufor[2]+przycisk.getText();
          this.wynik.setText(bufor[2]);
        }
      }
    }
  }
}
