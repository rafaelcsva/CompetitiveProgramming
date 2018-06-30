//15, 06, 2018, 21:47:32 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long  ull;

const int N = 23;
ull fat[N];
int cnt[N + 10];

void gen(){
    fat[0] = 1LL;

    for(int i = 1 ; i < N ; i++){
        fat[i] = i * fat[i - 1];
    }
}

ll solve(string s){
    ll r = fat[s.length()];

    for(int i = 0 ; i < s.length() ; i++){
        cnt[s[i] - 'A']++;
    }

    for(int i = 0 ; i < N + 10 ; i++){
        r /= fat[cnt[i]];
    }

    return r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    gen();

    int t;
    int test = 1;

    cin >> t;

    while(t--){
        string s;

        cin >> s;

        cout << "Data set " << test++ << ": " << solve(s) << endl;

        memset(cnt, 0, sizeof cnt);
    }

    return 0;
}