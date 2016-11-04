import java.util.Scanner;

class Ulamek{
  int licznik;
  int mianownik;

  Ulamek(int l,int m){
    licznik=l;
    mianownik=m;
  }

  void NotZero(int m){
    if(m==0){
      System.out.println("Mianownik nie moze byc zerem");
      System.exit(0);
    }
  }

  void HowItLooks(int l,int m){
    System.out.println(l);
    System.out.println(m);
  }

  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int licznik = in.nextInt();
    int mianownik = in.nextInt();
    Ulamek ul=new Ulamek(licznik,mianownik);
    ul.NotZero(mianownik);
    ul.HowItLooks(licznik,mianownik);



  }
}
