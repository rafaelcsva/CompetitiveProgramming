#include <bits/stdc++.h>

using namespace std;

int main (){
	int D;

	cin>>D;

	int dias = D/720;
	int sobra = D%720;

	int hora;
	int min;
	int NPr = 0;
	
	for(hora = 1 ; hora <= 12; hora++){
		for(min = 0 ; min <=59 ; min++){
			int d1 = min%10;
			int d2 = (min/10);
			int d3 = hora%10;
			int d4 = hora/10;
			
			if(d2-d1 == d3-d2 && (d4==0|| d3-d2 == d4-d3)){
				//printf("%d%d%d%d\n", d4, d3, d2, d1);
				NPr++;		
			}
		}
	}
	
	int r = dias*NPr;
	
	for(hora = 1 ; hora <= 12; hora++){
		for(min = 0 ; min <=59 ; min++){
			if((hora)*60+min > sobra)
				break;
				
			int d1 = min%10;
			int d2 = (min/10);
			int d3 = hora%10;
			int d4 = hora/10;
			
			if(d2-d1 == d3-d2 && (d4==0|| d3-d2 == d4-d3)){
				r++;		
			}
		}
	}
	
	if(sobra >= 34)
		r++;
		
	printf("%d\n", r);

	return 0;
}
