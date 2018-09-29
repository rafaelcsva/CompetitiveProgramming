//19, 07, 2018, 21:39:26 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

class ChromosomalCrossover{
  	public:
    	int count_prefix(string A, string B){
            int best = 0;

    		for(int i = 0 ; i < A.length() ; i++){
                for(int j = 0 ; j < B.length() ; j++){
                    int k = j, t = i;
                    int cnt = 0;

                    while(k < B.length() && t < A.length()){
                        if(B[k] != A[t]){
                            break;
                        }

                        cnt++, k++, t++;
                    }
                }
            }

            return best;
        }
    
        int maximalLength(string A, string B){
            int have = count_prefix(A, B);
        }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}