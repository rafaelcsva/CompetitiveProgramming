//23, 06, 2018, 09:04:58 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;

    cin >> n >> k;

    int ax = 0;
    int cnt = 1;

    for(int i = 0 ; i < n ; i++){
        int x;

        cin >> x;

        if(ax == k){
            cnt++;
            ax = 1;
        }

        ax = ax + 1;
    }

    cout << cnt << endl;
    
    return 0;
}