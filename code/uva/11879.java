import java.math.BigInteger;
import java.util.Scanner;

class Main{
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        BigInteger n;

        while(sc.hasNext()){
            n = sc.nextBigInteger();
            
            if(n.equals(BigInteger.valueOf(0))){
                break;
            }
        
            if(n.remainder(BigInteger.valueOf(17)).equals(BigInteger.valueOf(0))){
                System.out.println(1);
            }else{
                System.out.println(0);
            }
        }

    }
}