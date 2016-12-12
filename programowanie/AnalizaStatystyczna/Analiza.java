import java.io.*;
import java.util.*;
import java.math.*;

class Analiza
{
  public static Scanner sc;
  public static double[] arr;

/*UTWORZENIE SCANNER DO WEDROWANIA PO PLIKU*/
  void createScanner(){
    File file = new File("dane.txt");
    try{
      sc = new Scanner(file);
    }
    catch (FileNotFoundException ex){
      System.out.println("File Not Found");
      System.exit(0);
    }
  }

/*UTWORZENIE PLIKU Z DANYMI*/
  static void CreateFile() throws FileNotFoundException
  {
    PrintWriter zapis = new PrintWriter("dane.txt");           //zapisywanie do pliku
    Random generator = new Random();                           //generowanie liczb pseudolosowych

    int i=0;
    for (i=0;i<15;i++)
    {
      zapis.println(generator.nextInt(256));                   //wypisywanie liczb z zakresu 0-256 do pliku
    }
    zapis.close();
  }

/*WCZYTANIE DANYCH Z PLIKU DO TABLICY arr*/
  void ReadFile() throws FileNotFoundException
  {
    int i = 0;
    while (sc.hasNextLine()){
      String line = sc.nextLine();
      arr[i] = Double.parseDouble(line);
      i++;
    }
  }

/*OBLICZANIE SREDNIEJ*/
  public static double average(double[] nums){
    double wyn = 0;
    for (int i=0; i<nums.length; i++)
      wyn += nums[i];
    wyn /= nums.length;
    return wyn;
  }

  /*OBLICZENIE WARIANCJII*/
  public static double variance(double[] nums){
    double wyn = 0;
    double wynAvg = average(nums);
    for (int i=0; i<nums.length; i++){
      wyn += (nums[i] - wynAvg) * (nums[i] - wynAvg);
    }
    wyn /= (nums.length-1);
    return wyn;
  }

  /*OBLICZENIE ODCHYLENIA*/
  public static double standardDev(double[] nums){
    double wyn = 0;
    for (int i=0; i<nums.length; i++){
      double r = (nums[i] - average(nums));
      wyn += (r*r);
    }
    wyn /= nums.length;
    wyn = Math.sqrt(wyn);
    return wyn;
  }

  /*USTALENIE PRECYZJI, ILOSC ZNAKOW WYSWIETLANYCH PO PRZECINKU*/
  public static String precision(double str){
    java.text.DecimalFormat df = new java.text.DecimalFormat();
    df.setMinimumFractionDigits(2);
    df.setMaximumFractionDigits(4);
    return df.format(str);
  }

  /*WYWOLANIE DZIALAN I WYSWIETLENIE ICH WYNIKOW W KONSOLI*/
  void count(){
    double[] temparr = new double[10];
    for ( int i=0; i<=15; i++ ){
      if ( i >= 10 ){
        for ( int j = i-10, k = 0; k < 10; j++, k++)
          temparr[k] = arr[j];
        System.out.println( ( i-9 ) + ") AVG " + precision( average(temparr) ) + "\t\t VAR " +
                          precision( variance(temparr) ) + "\t\t SDEV " + precision( standardDev(temparr) ) );
      }
    }
  }

/*GLOWNA FUNKCJA MAIN*/
  public static void main(String[] args) throws FileNotFoundException {
    CreateFile();
    Analiza anal = new Analiza();
    anal.createScanner();
    arr = new double[15];
    anal.ReadFile();
    anal.count();
  }
}
