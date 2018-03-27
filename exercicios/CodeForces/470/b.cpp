#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 100;
vector<int>primes;
bool isPrime[N];
vector<int>composite;

void sieve(){
	for(int i = 2 ; i * i <= N ; i++){
		if(!isPrime[i]){
			primes.push_back(i);
			
			for(int j = i + i ; j < N ; j += i){
				isPrime[j] = true;
			}
		}
	}
}

int main (){
	int x2;
		
	cin >> x2;
	
	sieve();
	
	int t2 = x2;
	
	for(int i = 2 ; i * i < x2 ; i++){
		if(t2 % i == 0){
			composite.push_back(i);
			
			while(t2 % i == 0){
				t2 /= i;
			}
		}
	}
	
	if(t2 != 1)
		composite.push_back(t2);
	
	int r = (int)1e9;
	
	for(int i = 0 ; i < composite.size() ; i++){
		for(int j = 0 ; j < composite[i] ; j++){
			int x1 = x2 - j;
			int t1 = x1;
			
			for(int k = 0 ; k < primes.size() ; k++){
				if(t1 < primes[k]){
					break;
				}
				
				if(t1 % primes[k] == 0){
					if(x1 - primes[k] + 1 >= 3){
						r = min(x1 - primes[k] + 1, r);
					}
				}
				
				while(t1 % primes[k] == 0){
					t1 /= primes[k];
				}
			}
		}
	}
	
	cout << r << '\n';
	
	return 0;
}


