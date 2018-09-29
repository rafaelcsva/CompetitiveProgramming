//30, 06, 2018, 09:30:40 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

const int N = 3;
ll m[] = {5LL, 6LL, 6LL};
ll mark[N][2];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, idx;

    cin >> n >> idx;    

    while(n){
        if(mark[idx][n & 1LL]){
            ll q = mark[idx][n & 1LL] - n;
            n = n - (n / q) * q;
        }else{
            mark[idx][n & 1LL] = n;
        }

        if(!n)
            break;

        if((n & 1LL) == 0LL){
            if(idx == 2LL){
                idx = 1LL;
            }else if(idx == 1LL){
                idx = 2LL;
            }
        }else{
            if(idx == 0LL){
                idx = 1LL;
            }else if(idx == 1LL){
                idx = 0LL;
            }
        }

        n--;
    }

    cout << idx << endl;

    return 0;
}