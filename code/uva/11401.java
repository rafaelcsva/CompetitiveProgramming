import java.math.BigInteger;
import java.util.Scanner;

class Main{
    public static int N = 1000001;
    public static BigInteger[] dp = new BigInteger[N];
    
    public static long sum(long i, long o){
        long r = 0;
        long n = i - 1;
        r = (((1 + n) * n) / 2);
        i++;
        n = o - 1 - i;
        
        if(n > 0){
            r += ((o - i) * n) / 2;
        }
        
        return r;
    }
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);

        int n;

        
        dp[0] = dp[1] = dp[2] = dp[3] = BigInteger.valueOf(0);

        for(int i = 4 ; i < N ; i++){
            dp[i] = dp[i - 1].add(BigInteger.valueOf(sum(i / 2, i)));
        }

        while(sc.hasNext()){
            n = sc.nextInt();

            if(n < 3)
                break;
            
            System.out.println(dp[n]);
        }
        
    }

}