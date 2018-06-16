//02, 06, 2018, 07:40:19 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

const int N = 2000;
int d[N];

int main(){
    int t;

    cin >> t;

    while(t--){
        int x, n;

        cin >> x >> n;

        if(x < n){
            cout << -1 << endl;
            continue;
        }

        int q = x / n;
        int r = x % n;

        for(int i = 0 ; i < n ; i++){
            d[i] = q;
        }

        for(int i = n - 1 ; r ; r--, i--){
            d[i]++;
        }

        for(int i = 0 ; i < n ; i++){
            cout << d[i];

            if(i != n - 1){
                cout << ' ';
            }else{
                cout << endl;
            }
        }
    }
    return 0;
}