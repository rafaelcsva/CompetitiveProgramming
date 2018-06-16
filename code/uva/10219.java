import java.math.BigInteger;
import java.util.Scanner;

class Main{
    public static final int N = 37000;
    public static BigInteger[] c = new BigInteger[N];
    
    public static void gen(){
        c[0] = BigInteger.valueOf(1);
        
        for(int i = 1 ; i < N ; i++){
            c[i] = c[i - 1].multiply(BigInteger.valueOf(i));
        }
    }

    public static int digits(BigInteger v){
        int d = 0;
        
        while(!v.equals(BigInteger.valueOf(0))){
            v = v.divide(BigInteger.valueOf(10));
            d++;
        }

        return d;
    }

    public static BigInteger comb(int n, int k){
        return (c[n].divide(c[n - k])).divide(c[k]);
    }

    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        gen();
        
        while(sc.hasNext()){
            int a, b;

            a = sc.nextInt();
            b = sc.nextInt();
            
            while(a >= N){

            }
            System.out.println(digits(comb(a, b)));
        }
    }
}