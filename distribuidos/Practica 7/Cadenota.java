public class Cadenota{
	public static void main(String[] args){
		String cadenota = "";
		for(int i = 0; i<26*26*26;i++){
			int c1 = (int) (Math.random()*26)+65;
			int c2 = (int) (Math.random()*26)+65;
			int c3 = (int) (Math.random()*26)+65;
			cadenota += " "+(char)c1+(char)c2+(char)c3+" ";
		}
		int counter = 0;
		int n = cadenota.length();
		for(int i = 0; i<n;i++){
			if(cadenota.charAt(i) == 'I')
				if(i+1 < n && cadenota.charAt(i+1) == 'P')
					if(i+2 < n && cadenota.charAt(i+2) == 'N'){ counter++; i += 3;}
				
			
		}
		//System.out.println(cadenota);
		System.out.println(counter);
	}
}
