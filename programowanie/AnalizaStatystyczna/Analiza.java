import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.io.PrintWriter;
import java.util.Random;
import java.io.*;
import java.util.*;
import java.math.*;

class Analiza
{

  public static  int[] arr;

  class Wyniki extends Analiza{

    double srednia;
    double odchylenie;
    double wariancja;
  }


/*UTWORZENIE PLIKU Z DANYMI*/
  static void CreateFile() throws FileNotFoundException
  {
    //File plik = new File("dane.txt");                        //utworzenie pliku CZY KONIECZNE ???                                      !!!
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
  static void Read() throws FileNotFoundException
  {

  }
/*GLOWNA FUNKCJA MAIN*/
  public static void main(String[] args) throws FileNotFoundException {
    CreateFile();
    Analiza anal = new Analiza();
    arr = new int[15];
    Read();
  }
}
