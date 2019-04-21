//16, 03, 2019, 09:03:04 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(1e5 + 100);
ll q[N];
const ll mod = ll(1e9) + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    string s;

    cin >> s;

    for(int i = 0 ; i < n ; i++){
        q[s[i] - 'a']++;
    }

    ll tot = 1LL;

    for(char a = 'a' ; a <= 'z' ; a++){
        q[a - 'a']++;

        tot = (tot * q[a - 'a']) % mod; 
    }

    cout << (tot - 1LL + mod) % mod << endl;
    
    return 0;
}