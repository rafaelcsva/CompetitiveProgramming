import java.math.BigInteger;
import java.util.*;

class Main{
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while(t != 0){
            t--;
            
            String a = sc.next();
            String b = sc.next();

            StringBuilder a1 = new StringBuilder(), b1 = new StringBuilder();

            a1.append(a);
            a1 = a1.reverse();

            b1.append(b);
            b1 = b1.reverse();

            BigInteger n1 = new BigInteger(a1.toString());
            BigInteger n2 = new BigInteger(b1.toString());

            StringBuilder c = new StringBuilder();

            n1 = n1.add(n2);

            c.append(n1.toString());

            c = c.reverse();

            System.out.println(new BigInteger(c.toString()));
        }
    }
}