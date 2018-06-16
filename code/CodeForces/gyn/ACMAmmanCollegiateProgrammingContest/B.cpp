//02, 06, 2018, 07:04:25 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;

typedef long long ll;

const int N = 2010;
ll qtd[N];

int main(){
    int t;

    cin >> t;

    while(t--){
        ll x, n;

        cin >> x >> n;

        if(n == 1){
            cout << x << endl;
            continue;
        }
        
        ll q = x / (2LL * n - 2LL);
        ll r = x % (2LL * n - 2LL);

        for(int i = 2 ; i < n ; i++){
            qtd[i] = 2LL * q;
        }

        qtd[1] = q, qtd[n] = q;

        for(int i = 1 ; i <= n && r ; i++, r--){
            qtd[i]++;
        }
        for(int i = n - 1 ; i >= 1 && r ; i--, r--){
            qtd[i]++;
        }

        for(int i = 1 ; i <= n ; i++){
            char c = i == n ? '\n' : ' ';
            cout << qtd[i] << c;
        }
    }

    return 0;
}