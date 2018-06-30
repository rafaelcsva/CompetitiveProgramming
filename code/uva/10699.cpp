//21, 06, 2018, 21:58:45 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

const int N = int(1e6 + 100);
int cnt[N];

void sieve(){
    for(int i = 2 ; i < N ; i++){
        if(!cnt[i]){
            for(int j = i ; j < N ; j += i){
                cnt[j]++;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    sieve();
    int n;

    while(cin >> n){
        if(!n)
            break;
            
        cout << n << " : " << max(1, cnt[n]) << endl;
    }

    return 0;
}