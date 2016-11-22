using System;

namespace ConsoleApplication2
{
  class Fraction
  {
    private int numerator;
    private int denominator;

    public Fraction(int numerator, int denominator)
    {
      this.numerator = numerator;
      this.denominator = denominator;
    }

    public int getNumerator()
    {
      return this.numerator;
    }

    public int getDenominator()
    {
      return this.denominator;
    }

    public Fraction Add(Fraction input)
    {
      var denominator = input.getDenominator();
      var numerator = input.getNumerator();
      return new Fraction(this.numerator*denominator + numerator*this.denominator, this.denominator*denominator);
    }

    public Fraction Multiply(Fraction input)
    {
      var denominator = input.getDenominator();
      var numerator = input.getNumerator();
      return new Fraction(this.numerator*numerator, this.denominator*denominator);
    }

    public void Show()
    {
      Console.WriteLine($"{this.numerator}/{this.denominator}");
    }

  }
}
