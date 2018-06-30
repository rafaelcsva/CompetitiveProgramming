//16, 06, 2018, 09:14:11 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

int main(){
    int n;

    cin >> n;

    ll cnt = 0LL;

    for(int i = 0 ; i < n ; i++){
        int x;

        cin >> x;

        while(x % 2LL == 0LL){
            cnt++;
            x /= 2LL;
        }
    }

    cout << cnt << endl;

    return 0;
}