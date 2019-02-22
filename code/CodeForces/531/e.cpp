//09, 01, 2019, 13:29:24 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(3e5);
int a[N];
map< int, int > beg, en;
const ll mod = 998244353LL;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];

        if(beg.count(a[i]) == 0){
            beg[a[i]] = i;
        }

        en[a[i]] = i;
    }

    ll start = 1LL;
    ll tot = 1LL;
    
    int pointer = 1;

    while(pointer <= n){
        int bound = en[a[pointer]];

        while(pointer < bound){
            pointer++;
            bound = max(bound, en[a[pointer]]);
        }

        tot *= start;
        tot %= mod;

        start = 2LL;
        pointer++;
    }

    cout << tot << endl;

    return 0;
}