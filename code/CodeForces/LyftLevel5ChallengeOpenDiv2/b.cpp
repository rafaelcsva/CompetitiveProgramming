//04, 11, 2018, 16:21:23 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(1e6);
int l[N], r[N];
int x[N];
const int inf = 1e9 + 10;
int t[N];
int cnt[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;

    cin >> n >> m;

    x[0] = inf;

    for(int i = 1 ; i <= (n + m) ; i++){
        cin >> x[i];
    }

    for(int i = 1 ; i <= (n + m); i++){
        cin >> t[i];
    }

    int cur = 0;

    for(int i = 1 ; i <= (n + m) ; i++){
        if(t[i]){
            cur = i;
        }

        l[i] = cur;
    }

    for(int i = (n + m) ; i >= 1 ; i--){
        if(t[i]){
            cur = i;
        }
        
        r[i] = cur;
    }

    for(int i = 1 ; i <= (n + m) ; i++){
        if(!t[i]){
            int mnl = abs(x[i] - x[l[i]]);
            int mnr = abs(x[r[i]] - x[i]);

            if(mnr < mnl){
                cnt[r[i]]++;
            }else{
                cnt[l[i]]++;
            }
        }
    }

    for(int i = 1 ; i <= (n + m) ; i++){
        if(t[i]){
            cout << cnt[i] << " " ;
        }
    }

    cout << endl;

    return 0;
}