class Gra{
  public String nazwa;
  public String gatunek;
  public String platforma;

  public Gra(){
    nazwa = "Policja";
    gatunek = "Przygodowy";
    platforma = "Zycie";
  }

  void graj(){
    System.out.println("Teraz grasz w " + nazwa);
  }
}


class Laborki{
  public static void main(String args[]){
    System.out.println("Biblioteczka");

    Gra gra0 = new Gra();
    gra0.nazwa = "Crash Bandicoot";
    gra0.gatunek = "Platformer";
    gra0.platforma = "PlayStation";

    Gra graWPolicje = new Gra();
    System.out.println(graWPolicje.toString());

    System.out.println(graWPolicje.nazwa);
    System.out.println(graWPolicje.gatunek);

    String napis = new String("Jakis napis");
    System.out.println(napis.length());       //(napis.toUpperCase()) <-- Capital
    String dnapis = napis.toUpperCase();
    System.out.println(dnapis);

    gra0.graj();
    graWPolicje.graj();
  }
}
