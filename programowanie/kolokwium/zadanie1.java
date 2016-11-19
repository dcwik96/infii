class Dane{

  int liczba;
  String napis;
  double wynik;

  Dane(int liczba,String napis,double wynik){
    this.liczba=liczba;
    this.napis=napis;
    this.wynik=wynik;
  }

  void print(){
    System.out.println("Liczba: "+liczba);
    System.out.println("Napis: "+napis);
    System.out.println("Wynik: "+wynik);
  }
  public static void main(String[] args) {
    Dane dn=new Dane(23,"Ćwik",4.0);
    dn.print();

  }
}
