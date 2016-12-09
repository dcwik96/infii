
class MagicznaCyfra{

  int suma;
  String nazwa;

  MagicznaCyfra(){
    nazwa="Dawid Cwik";
  }

  public static void main(String[] args) {
    MagicznaCyfra mc=new MagicznaCyfra();
    String tocheck=mc.nazwa.replace(" ","");
    tocheck=tocheck.toUpperCase();
    for (int i=0;i<tocheck.length() ;i++ ) {
      char letter = tocheck.charAt(i);
      int ascii = (int) letter;

      if (ascii==65||ascii==69||ascii==73||ascii==79||ascii==85||ascii==89) {
        mc.suma+=3;
      }
      else if(ascii%2==1)
        mc.suma+=1;
      else
        mc.suma+=2;
    }
    System.out.println("Napis:"+mc.nazwa);
    System.out.println("Liczba:"+mc.suma);

  }
}
