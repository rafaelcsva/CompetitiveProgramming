import java.math.BigInteger;
import java.util.Scanner;
import java.util.Map;
import java.util.HashMap;

class Main{
    static Map<Character, BigInteger>mp = new HashMap<Character, BigInteger>();

    public static BigInteger getValue(String s, int b){
        BigInteger r = BigInteger.valueOf(0);
        
        for(int i = s.length() - 1, j = 0 ; i >= 0 ; i--, j++){
            if(mp.get(s.charAt(i)).compareTo(BigInteger.valueOf(b)) >= 0){
                return BigInteger.valueOf(-1000);
            }
            r = r.add(mp.get(s.charAt(i)).multiply(BigInteger.valueOf(b).pow(j)));
        }

        return r;
    }

    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        
        int x = 0;
        
        for(char c = '0' ; c <= '9' ; c++){
            mp.put(c, BigInteger.valueOf(x));
            x++;
        }

        for(char c = 'A' ; c <= 'Z' ; c++){
            mp.put(c, BigInteger.valueOf(x));
            x++;
        }

        while(sc.hasNext()){
            String sa, sb;

            sa = sc.next();
            sb = sc.next();
            boolean find = false;

            for(int b1 = 2 ; b1 <= 36 ; b1++){
                BigInteger a = getValue(sa, b1);
                
                if(a.equals(BigInteger.valueOf(-1000))){
                    continue;
                }
                
                for(int b2 = 2 ; b2 <= 36 ; b2++){
                    BigInteger b = getValue(sb, b2);
                    
                    if(a.equals(b)){
                        find = true;
                        System.out.println(sa + " (base " + b1 + ") = " + sb + " (base " + b2 + ")");
                        break;
                    }
                }

                if(find)
                    break;
            }

            if(!find){
                System.out.println(sa + " is not equal to " + sb + " in any base 2..36");
            }
        }
    }
}