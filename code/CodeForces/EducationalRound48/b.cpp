//03, 08, 2018, 12:04:57 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

const int N = 1e3 + 10;
int pref[N];
string s, t;
int n, m;

bool preprocess(){
    for(int i = 0; i <= n - m ; i++){
        bool verify = true;

        for(int j = 0 ; j < m ; j++){
            if(s[j + i] != t[j]){
                verify = false;
                break;
            }
        }

        pref[i] = verify;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int q;

    cin >> n >> m >> q;

    cin >> s >> t;

    preprocess();

    for(int i = 0 ; i < n ; i++){
        if(i){
            pref[i] += pref[i - 1];
        }
    }

    while(q--){
        int l, r;

        cin >> l >> r;

        l--, r--;

        r = r - m + 1;
        
        if(l <= r){
            int re = pref[r];

            if(l){
                re -= pref[l - 1];
            }

            printf("%d\n", re);
        }else{
            printf("0\n");
        }
    }    
    
    return 0;
}