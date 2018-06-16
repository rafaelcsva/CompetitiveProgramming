import java.math.BigInteger;
import java.util.Scanner;

class Main{
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        int n;
        BigInteger a;

        while(sc.hasNext()){
            n = sc.nextInt();
            a = sc.nextBigInteger();

            BigInteger sum = BigInteger.valueOf(0);
            
            for(int i = 1 ; i <= n ; i++){
                sum = sum.add(a.pow(i).multiply(BigInteger.valueOf(i)));
            }

            System.out.println(sum);
        }

    }
}