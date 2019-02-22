//04, 11, 2018, 16:14:36 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    ll x, y;

    cin >> n;
    cin >> x >> y;

    ll disw = 0LL, disb = 0LL;

    ll mn = min(x - 1LL, y - 1LL);
    disw = x - 1LL - mn + y - 1LL - mn + mn;

    mn = min(n - x, n - y);
    disb = (n - x - mn) + (n - y - mn) + mn;
    // cout << disb << " " << disw << endl;

    if(disb >= disw){
        cout << "White" << endl;
    }else{
        cout << "Black" << endl;
    }

    return 0;
}