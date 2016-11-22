using System;

namespace ConsoleApplication2
{
  class Program
  {
    static void Main(string[] args)
    {
      var ulamek1 = new Fraction(1,2);
      var ulamek2 = new Fraction(3,4);
      var ulamek3 = ulamek1.Add(ulamek2);
      var ulamek4 = ulamek3.Multiply(ulamek2);
      ulamek3.Show();
      ulamek4.Show();
      Console.ReadKey();

    }
  }
}
