//05, 05, 2018, 09:15:28 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
const int N = 3e5;
bool NotPrime[N + 10];
int sum[N];
bool Taked[N];
int primeCount;
vector<int>primes, sequence, candidates;

void sieve(){
    for(int i = 2 ; i * i <= N ; i++){
        if(!NotPrime[i]){
            for(int j = i + i ; j <= N ; j += i){
                NotPrime[j] = true;
            }
        }
    }

    for(int i = 2 ; i <= N ; i++){
        if(!NotPrime[i]){
            primes.push_back(i);


            if(i <= 55555){
                candidates.push_back(i);   
            }
        }

    }
}


bool canPut(int p,int c){

    if(c < 5){
        return true;
    }

    for(int i = 0 ; i < primes.size() ; i++){
        int pr = primes[i];

        if(pr > p){
            if(sum[pr - p]){
                return false;
            }
        }
    }

    return true;
}

bool can(int el, int c){
    if(c == n){
        return true;
    }

    if(el == candidates.size()){
        return false;
    }

    if(canPut(candidates[el])){
        taked[el] = true;
    }
}

int main(){
    sieve();
    int n;
    cout << primes.size() << endl;
    
    cin >> n;
    
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < candidates.size() ; j++){
            int p = candidates[j];

            if(canPut(p)){
                if(sequence.size() >= 3){
                    for(int a = 0 ; a < sequence.size() ; a++){
                        for(int b = a + 1 ; b < sequence.size() ; b++){
                            
                            for(int c = b + 1 ; c < sequence.size() ; c++){
                                int f = sequence[a], s = sequence[b], l = sequence[c];

                                sum[f + s + l + p] = 1;
                            }
                        }
                    }
                }

                sequence.push_back(p);           
                Taked[p] = true;
                
                break;
            }
        }
        cout << sequence.size() << endl;
    }
    
    for(int i = 0 ; i < sequence.size() ; i++){
        char c = i == sequence.size() - 1 ? '\n' : ' ';

        cout << sequence[i] << c;
    }

    return 0;
}