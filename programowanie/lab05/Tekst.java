import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.File;
import java.text.ParseException;
import java.util.Date;
import java.lang.Object;


public class Tekst
{
  int lznakow;
  int lwierszy;

  Tekst(int znak,int wiersz)
  {
    lznakow=znak;
    lwierszy=wiersz;
  }

  static int CheckChar() throws IOException
  {
    FileReader inputStream = null;
    int numb=0;
    try {
      inputStream = new FileReader("input.txt");

      int c;
      while ((c = inputStream.read()) != -1) {
        numb=numb+1;
      }
    } finally {
      if (inputStream != null) {
        inputStream.close();
      }
    }
    return numb;
  }

  static int CheckLine() throws IOException
  {
    FileReader inputStream = null;
    BufferedReader bufferReader = null;
    int numb=0;
    try {
      inputStream = new FileReader("input.txt");
      bufferReader = new BufferedReader(inputStream);

      String c;
      while ((c = bufferReader.readLine()) != null) {
        numb=numb+1;
      }
    } finally {
      if (bufferReader != null) {
        bufferReader.close();
      }
    }
    return numb;
  }

  static void CheckAge() throws IOException, ParseException
  {
    File file = new File("input.txt");
    System.out.println("Name: " + file.getName());
    System.out.println("Last modified: " + new Date(file.lastModified()));
  }


  public static void main(String[] args) throws IOException, ParseException {
    CheckAge();
    Tekst tk=new Tekst(CheckChar(),CheckLine());
    System.out.println(tk.lznakow+" "+tk.lwierszy);
}
}
