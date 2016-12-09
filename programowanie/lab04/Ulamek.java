import java.util.Scanner;

class Ulamek{
  int licznik;
  int mianownik;

  Ulamek(int l,int m)
  {
    licznik=l;
    mianownik=m;
  }

  static void NotZero(int m)
  {
    if(m==0){
      System.out.println("Mianownik nie moze byc zerem");
      System.exit(0);
    }
  }

  void print(Ulamek ul,int choice)
  {
    if(choice==1)
      System.out.println(ul.licznik+"/"+ul.mianownik);
    if(choice==2)
      System.out.println((double)(ul.licznik)/(double)(ul.mianownik));
    if(choice!=1 && choice!=2)
      System.out.println("Miales wybrac miedzy jeden a dwa ... I caly misterny plan w piiiii");
  }

  Ulamek add(Ulamek ul1,Ulamek ul2)
  {
    int dtemp = ul1.mianownik*ul2.mianownik;
    int ntemp = ul1.mianownik*ul2.licznik+ul1.licznik*ul2.mianownik;
    return new Ulamek(ntemp,dtemp);
  }

  Ulamek minus(Ulamek ul1,Ulamek ul2){
    int dtemp = ul1.mianownik*ul2.mianownik;
    int ntemp = ul1.licznik*ul2.mianownik-ul1.mianownik*ul2.licznik;
    return new Ulamek(ntemp,dtemp);
  }

  Ulamek divide(Ulamek ul1,Ulamek ul2){
    return new Ulamek(ul1.licznik*ul2.mianownik,ul1.mianownik*ul2.licznik);
  }

  Ulamek multiply(Ulamek ul1,Ulamek ul2)
  {
    return new Ulamek(ul1.licznik*ul2.licznik,ul1.mianownik*ul2.mianownik);
  }

  static int AskForLicz()
  {
    Scanner in = new Scanner(System.in);
    System.out.println("Podaj licznik ulamka");
    int licznik = in.nextInt();
    return licznik;
  }

  static int AskForMian()
  {
    Scanner in = new Scanner(System.in);
    System.out.println("Podaj mianownik ulamka");
    int mianownik = in.nextInt();
    NotZero(mianownik);
    return mianownik;
  }

  static void ToPick()
  {
    System.out.println("Wybierz jak chcesz wyswietlać ułamki:");
    System.out.println("( 1 ) Ułamki zwykle ( 1/2 )");
    System.out.println("( 2 ) Ułamki dziesiętne ( 0.5 )");
  }

  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    Ulamek ul1=new Ulamek(AskForLicz(),AskForMian());
    Ulamek ul2=new Ulamek(AskForLicz(),AskForMian());
    ToPick();
    int choice = in.nextInt();
    ul1.print(ul1.add(ul1,ul2),choice);
    ul1.print(ul1.minus(ul1,ul2),choice);
    ul1.print(ul1.multiply(ul1,ul2),choice);
    ul1.print(ul1.divide(ul1,ul2),choice);
  }
}
