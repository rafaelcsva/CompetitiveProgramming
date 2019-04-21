//13, 04, 2019, 00:23:09 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int prime[6] = {2, 3, 5, 7, 11, 13};
int res[6];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    cin >> t;

    while(t--){
        int n, m;

        cin >> n >> m;

        for(int j = 0 ; j < 6 ; j++){
            for(int i = 1 ; i <= n ; i++){
                cout << prime[j] << " ";
            }

            cout << endl;

            int ac = 0;

            for(int i = 0 ; i < n ; i++){
                int x;

                cin >> x;

                assert(x != -1);

                ac += x;
            }

            res[j] = ac;
        }

        int resp = -1;

        for(int i = 1 ; i <= m ; i++){
            int ok = 0;

            for(int j = 0 ; j < 6 ; j++){
                if(j % prime[j] == res[j]){
                    ok++;
                }
            }

            if(ok == 6){
                resp = i;
                break;
            }
        }

        assert(resp != -1);

        cout << resp << endl;

        int x ;
    
        cin >> x;

        assert(x != -1);
    }

    return 0;
}