import java.util.Scanner;

class Ulamek{
  int licznik;
  int mianownik;

  Ulamek(int l,int m){
    licznik=l;
    mianownik=m;
  }

  static void NotZero(int m){
    if(m==0){
      System.out.println("Mianownik nie moze byc zerem");
      System.exit(0);
    }
  }

  /*static void HowItLooks(int l,int m){
    System.out.println(l);
    System.out.println(m);
  }*/

  static void ToPick(){
    System.out.println("Wybierz jak chcesz wyswietlać ułamki:");
    System.out.println("( 1 ) Ułamki zwykle ( 1/2 )");
    System.out.println("( 2 ) Ułamki dziesiętne ( 0.5 )");
  }

  void AfterPick(int choice){
    if(choice==1)
      System.out.println(licznik+"/"+mianownik);
    if(choice==2)
      System.out.println((double)(licznik)/(double)(mianownik));
    if(choice!=1 && choice!=2)
      System.out.println("Miales wybrac miedzy jeden a dwa ... I caly misterny plan w piiiii");
  }

  static void add(Ulamek mianownik){
    if(ul1.mianownik==ul2.mianownik)
    System.out.println("ok");
  }

  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    System.out.println("Podaj OSOBNO licznik i mianownik pierwszego ulamka");
    int licznik1 = in.nextInt();
    int mianownik1 = in.nextInt();
    NotZero(mianownik1);
    System.out.println("Podaj OSOBNO licznik i mianownik drugiego ulamka");
    int licznik2 = in.nextInt();
    int mianownik2 = in.nextInt();
    NotZero(mianownik2);
    Ulamek ul1=new Ulamek(licznik1,mianownik1);
    Ulamek ul2=new Ulamek(licznik2,mianownik2);
    //HowItLooks(licznik,mianownik);
    ToPick();
    int choice = in.nextInt();
    ul1.AfterPick(choice);
    ul2.AfterPick(choice);
    add(ul1,ul2);
  }
}
