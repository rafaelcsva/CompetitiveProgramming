//15, 11, 2018, 15:32:36 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int D = 30;
bool has[D][D];
ll cnt[D];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    cin >> t;

    while(t--){
        int n, m, k;

        cin >> n >> m >> k;

        string a, b;

        cin >> a >> b;

        for(int i = 0 ; i <= n - k ; i++){
            int u = a[i] - 'a';
            int v = a[i + k - 1] - 'a';

            has[u][v] = true;
        }

        for(int i = 0 ; i < m ; i++){
            b[i] -= 'a';

            cnt[b[i]]++;
        }

        ll tot = 0;

        for(int i = 0 ; i < m ; i++){
            for(int c = 0 ; c <= 'z' - 'a' ; c++){
                if(has[b[i]][c]){
                    tot += cnt[c];
                }
            }

            cnt[b[i]]--;
        }

        cout << tot << endl;

        memset(has, false, sizeof has);
    }

    return 0;
}