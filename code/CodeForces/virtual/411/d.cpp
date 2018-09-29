//25, 07, 2018, 17:03:35 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

const ll mod = ll(1e9 + 7);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;

    cin >> s;

    ll sum = 0LL;
    ll cntb = 0LL;

    for(int i = int(s.length()) - 1 ; i >= 0 ; i--){
        if(s[i] == 'a'){
            sum += cntb;
            cntb *= 2LL;
            cntb %= mod;
            sum %= mod;
        }else{
            cntb++;
            cntb %= mod;
        }
    }

    cout << sum << endl;

    return 0;
}