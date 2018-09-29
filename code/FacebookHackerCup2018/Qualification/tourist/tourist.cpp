//06, 07, 2018, 20:11:05 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

typedef pair<string, int>   psi;

const int N = 100;
psi attraction[N];
psi resp[N];

bool compar(psi a, psi b){
    return a.second < b.second;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    for(int test = 1 ; test <= t ; test++){
        ll n, k;
        ll v;

        cin >> n >> k >> v;

        for(int i = 0 ; i < n ; i++){
            cin >> attraction[i].first;

            attraction[i].second = i;
        }

        ll start = (k * (v - 1LL)) % n; 
        int i = 0;

        while(i < k){
            resp[i] = attraction[start];
            start = (start + 1) % n;
            i++;
        }

        sort(resp, resp + k, compar);

        cout << "Case #" << test << ": ";

        for(int i = 0 ; i < k ; i++){
            char c = i == k - 1 ? '\n' : ' ';
            cout << resp[i].first << c;
        }
    }

    return 0;
}