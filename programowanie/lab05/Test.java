import java.io.IOException;
import java.nio.file.*;
import java.nio.file.attribute.*;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Reader;

public class Test {
    public static void main(String[] args) throws IOException {

    LineNumbarReader reader = null;
    try {
      reader = new LineNumberReader("input.txt");
       while ((reader.readLine()) != null);
       return reader.getLineNumber();
   } finally {
       if(reader != null)
           reader.close();
   }
  }
}
