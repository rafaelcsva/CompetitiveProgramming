//15, 11, 2018, 14:42:03 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    cin >> t;

    while(t--){
        int n, x, y;

        cin >> n >> x >> y;

        int fx = n / 2 + 1;
        int fy = n / 2;

        if(x >= fx && y >= fy){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }

    return 0;
}