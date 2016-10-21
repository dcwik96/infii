import java.io.*;

class Pesel{
  String pesel;

  Pesel(String pes){
      pesel = pes;
  }

  int at(int n){
    return Character.getNumericValue(pesel.charAt(n));
  }

  boolean valid(){
    int sum = 1*at(0) + 3*at(1) + 7*at(2) + 9*at(3) + 1*at(4) + 3*at(5) + 7*at(6) + 9*at(7) + 1*at(8) + 3*at(9);
    int z = at(10);
    int c = 10 - sum % 10;
    //System.out.println(sum);
    return z==c;
  }

  public static void main(String[] args) {
    Pesel p = new Pesel(args[0]);
    if(p.valid())
      System.out.println("Jest ok");
    else
      System.out.println("Zle");
  }
}
