import java.math.BigInteger;
import java.util.Scanner;
import java.util.Map;
import java.util.HashMap;

class Main{
    static Map<Character, BigInteger>mp = new HashMap<Character, BigInteger>();
    static Map<BigInteger, Character>pm = new HashMap<BigInteger, Character>();

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

    public static StringBuffer toBase(BigInteger value, BigInteger base){
        StringBuffer r = new StringBuffer();

        while(!value.equals(BigInteger.valueOf(0))){
            r.append(pm.get(value.mod(base)));
            value = value.divide(base);
        }
        
        r = r.reverse();
        
        if(r.length() == 0){
            r.append('0');
        }
        
        return r;
    }

    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        
        int x = 0;
        
        for(char c = '0' ; c <= '9' ; c++){
            mp.put(c, BigInteger.valueOf(x));
            pm.put(BigInteger.valueOf(x), c);
            x++;
        }

        for(char c = 'A' ; c <= 'Z' ; c++){
            mp.put(c, BigInteger.valueOf(x));
            pm.put(BigInteger.valueOf(x), c);
            x++;
        }

        while(sc.hasNext()){
            String num = sc.next();
            int from = sc.nextInt();
            int to = sc.nextInt();

            BigInteger value = getValue(num, from);
            StringBuffer resp = toBase(value, BigInteger.valueOf(to));

            if(resp.length() <= 7){
                System.out.format("%7s\n", resp);
            }else{
                System.out.format("%7s\n", "ERROR");
            }
        }
    }
}