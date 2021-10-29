#include <bits/stdc++.h>

using namespace std;

const int N = int(2e5);
int a[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while(t--){
        int n;

        cin >> n;

        vector< pair< int, int > > gans;
        int pos1 = -1;

        // cout << (pos1 != -1) << " " << pos1 << endl;

        cout << "? 2 " << n - 1 << " " << n << " " << 1 << endl;

        int ans;

        cin >> ans;

        if(ans == 1){
            pos1 = n - 1;
        }else if(ans == 2){
            gans.push_back({n - 1, n});
        }
        // cout << "n eh " << n << " " << pos1 << endl;
        // cout << (pos1 != -1) << " " << pos1 << endl;
        for(int i = 1 ; (i < n) && (pos1 == -1) ; i += 2){
            // cout << "aqui!\n";
            cout << "? 2 " << i << " " << i + 1 << " " << 1 << endl;

            cin >> ans;

            if(ans == 1){
                pos1 = i;
            }else if(ans == 2){
                gans.push_back({i, i + 1});
            }
        }

        if(pos1 == -1){
            // cout << "a1ui!\n";
            for(auto u: gans){
                cout << "? 2 " << u.second << " " << u.first << " " << 1 << endl;

                cin >> ans;

                if(ans == 1){
                    pos1 = u.second;
                    break;
                }
            }
        }

        assert(pos1 != -1);

        for(int i = 1 ; i <= n ; i++){
            if(i == pos1){
                continue;
            }

            cout << "? 1 " << pos1 << " " << i << " " << n - 1 << endl;

            cin >> ans;

            a[i] = ans;
        }

        a[pos1] = 1;

        cout << "! ";

        for(int i = 1 ; i <= n ; i++){
            cout << a[i];

            if(i < n){
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}