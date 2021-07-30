import java.util.Scanner;
import java.math.BigInteger;
public class Main{
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		BigInteger[] facts = new BigInteger[1005];
		facts[0] = facts[1] = new BigInteger("1");
		for(int i = 2; i<=1000;i++){
			facts[i] = facts[i-1].multiply(BigInteger.valueOf(i));
		}
		while(in.hasNextInt()){
			int n = in.nextInt();
			System.out.printf("%d!\n%s\n",n,facts[n]);
		}
	}
}
