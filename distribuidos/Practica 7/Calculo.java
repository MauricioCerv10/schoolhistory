public class Calculo{
	public static void main(String[] args){
		double i = 0;
		int max = 10000000;
		double seno = 0, cose = 0,tang = 0, loga = 0, raiz = 0;
		while(i<max){
			seno += Math.sin(i);
			cose += Math.cos(i);
			tang += Math.tan(i);
			loga += Math.log(i);
			raiz += Math.sqrt(i);
			i++;
		}
		System.out.println(seno);
		System.out.println(cose);
		System.out.println(tang);
		System.out.println(loga);
		System.out.println(raiz);
		
	}
}
