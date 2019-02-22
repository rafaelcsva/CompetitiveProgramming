//12, 10, 2018, 18:38:17 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(1e5 + 100);
ll pre[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    cin >> t;

    while(t--){
        int n;

        cin >> n;

        for(int i = 1 ; i <= n ; i++){
            cin >> pre[i];

            pre[i] += pre[i - 1];
        }

        ll st = 1;
        int day = 0;

        while(st < n){
            st += pre[st];
            day++;    
        }

        cout << day << endl;
    }

    return 0;
}