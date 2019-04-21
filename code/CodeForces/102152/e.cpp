//01, 04, 2019, 17:40:02 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 1000;
int cost[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while(t--){
        int n, m;

        cin >> n >> m;

        string s, c, p;

        cin >> s >> c >> p;

        memset(cost, -1, sizeof cost);

        for(int i = 0 ; i < s.length() ; i++){
            int a = s[i] - 'a';

            if(cost[a] == -1){
                cost[a] = c[i] - '0';
            }else{
                cost[a] = min(cost[a], c[i] - '0');
            }
        }

        int tot = 0;
        bool ok = true;

        for(int i = 0 ; i < p.length() ; i++){
            int a = p[i] - 'a';

            if(cost[a] == -1){
                ok = false;
                break;
            }

            tot += cost[a];
        }

        if(ok){
            cout << tot << endl;
        }else{
            cout << "-1" << endl;
        }
    }
    
    return 0;
}