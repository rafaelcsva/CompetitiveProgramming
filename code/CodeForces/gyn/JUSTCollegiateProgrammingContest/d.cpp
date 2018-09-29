//28, 07, 2018, 09:01:53 Rafaelcs cpp
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
        int n;

        cin >> n;

        int cnt = 0;

        for(int i = 0 ; i < n ; i++){
            int p;

            cin >> p;

            cnt += (p > 0);
        }

        cout << cnt << endl;
    }
    
    return 0;
}