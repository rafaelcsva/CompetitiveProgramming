#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = int(1e4) + 10;
ll mn[N], mx[N];
int a[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while(t--){
        int n;

        cin >> n;

        for(int i = 1 ; i <= n ; i++){
            mn[i] = mx[i] = -1;
        }

        int pos1 = -1, posn = -1;

        cout << "? 2 " << n << " " << n - 1 << " " << 1 << endl;

        int ans;

        cin >> ans;

        if(ans == 1){
            pos1 = n;
            a[n] = 1;
        } 

        cout << "? 1 " << 2 << " " << 1 << " " << n - 1 << endl;

        cin >> ans;

        if(ans == n){
            posn = 1;
            a[1] = n;
        }

        if(pos1 == -1 && posn == -1){
            for(int i = 1 ; i < n ; i++){
                int ans;
                cout << "? 2 " << i << " " << i + 1 << " " << 1 << endl; 

                cin >> ans;

                if(ans == 1){
                    pos1 = i;
                    break;
                }

                mn[i] = ans;

                cout << "? 1 " << i + 1 << " " << i << " " << n - 1 << endl;

                cin >> ans;

                if(ans == n - 1){
                    posn = i;
                    break;
                }
            }
        }

        if(pos1 != -1){
            for(int k = pos1 + 1 ; k <= n ; k++){
                int ans;
                cout << "? 1 " << pos1 << " " << k << " " << n - 1 << endl;
                cin >> ans;

                a[k] = ans;
            }
        }else if(posn != -1){
            for(int k = posn + 1 ; k <= n ; k++){
                int ans;
                cout << "? 2 " << k << " " << pos1 << " " << 1 << endl;
                cin >> ans;

                a[k] = ans;
            }
        }
    }

    return 0;
}