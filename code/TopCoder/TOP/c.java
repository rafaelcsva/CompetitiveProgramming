import java.math.BigInteger;

public class EllysTicketPrices{
	public double getPrice(int N, int[] C, int target){
		BigInteger den = BigInteger.valueOf(1);
		BigInteger num = den;
		BigInteger cem = BigInteger.valueOf(100);

		for(int i = 0 ; i < N ; i++){
			den = den.multiply(cem);
			num = num.multiply(100 + C[i]);
		}

		BigInteger number = 
	}
}