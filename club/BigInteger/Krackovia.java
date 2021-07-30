import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;
 
public class BigDecimalClass {
 
    /**
     * @param args
     */
     
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Scanner input = new Scanner (System.in);
        int n = input.nextInt();
        int f = input.nextInt();
        int cases = 0;
         
        while ( n != 0 || f != 0 ) {
            BigInteger sum = BigInteger.ZERO;
             
            for ( int i = 0; i < n; i++ ) {
                BigInteger cost = input.nextBigInteger();
                sum = sum.add(cost);
            }
            //Bill #1 costs 16200000000: each friend should pay 5400000000
            System.out.printf("Bill #%d costs ", ++cases);
            System.out.print(sum + ": each friend should pay " + sum.divide(BigInteger.valueOf(f)) + "\n\n");
             
            n = input.nextInt();
            f = input.nextInt();
        }
    }
}
