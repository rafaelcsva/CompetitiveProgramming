#include <bits/stdc++.h>

using namespace std;

class EllysAndXor{
	public:
	int getMax(vector <int> numbers){
		if(numbers.size() == 1){
			return numbers[0];
		}

		int n = numbers.size();
		int b = (1 << (n - 1));
		int best = 0;

		for(int d = 0 ; d < b ; d++){
			int carry = 0;

			for(int i = 0 ; i < n - 1 ; i++){
				int e = 1 << i;

				if(i == 0){
					if(d & e){
						carry = numbers[0] ^ numbers[1];
					}else{
						carry = numbers[0] & numbers[1];
					}
				}else{
					if(d & e){
						carry = carry ^ numbers[i + 1];
					}else{
						carry = carry & numbers[i + 1];
					}
				}
			}

			best = max(best, carry);
		}

		return best;
	}
};

int main(){

}