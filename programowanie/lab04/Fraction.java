public class Fraction {

    private int num;
    private int denom;

    Fraction(int n,int d){
        num = n;
        denom = d;
    }

    Fraction sum(Fraction f1,Fraction f2){
        int dtemp = f1.denom*f2.denom;
        int ntemp = f1.num*f2.denom+f1.denom*f2.num;
        return new Fraction(ntemp,dtemp);
    }

    Fraction minus(Fraction f1,Fraction f2){
        int dtemp = f1.denom*f2.denom;
        int ntemp = f1.num*f2.denom-f1.denom*f2.num;
        return new Fraction(ntemp,dtemp);
    }

    Fraction product(Fraction f1,Fraction f2){
        return new Fraction(f1.num*f2.num,f1.denom*f2.denom);
    }

    Fraction divide(Fraction f1,Fraction f2){
        return new Fraction(f1.num*f2.denom,f1.denom*f2.num);
    }

    void printfrac(Fraction fr){
        System.out.println("Numerator:"+fr.num+"\t Denominator:"+fr.denom);
    }

    public static void main(String[] args) {
        Fraction f1 = new Fraction(2, 3);
        Fraction f2 = new Fraction(1, 2);

        System.out.println("Add:\n");
        f1.printfrac(f1.sum(f1,f2));
        System.out.println("Minus:\n");
        f1.printfrac(f1.minus(f1,f2));
        System.out.println("Divide:\n");
        f1.printfrac(f1.divide(f1,f2));

    }

}
