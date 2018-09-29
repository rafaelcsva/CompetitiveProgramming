//30, 07, 2018, 05:40:42 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;
const int N = 200100;
ll a[N];
map<ll, ll>cnt;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;

    cin >> n;

    bool ver = false;

    for(int i = 0 ; i < 2 * n ; i++){
        cin >> a[i];

        cnt[a[i]]++;

        if(cnt[a[i]] >= n){
            ver = true;
        }
    }

    if(ver){
        cout << "0" << endl;
        return 0;
    }
    n *= 2;

    sort(a, a + n);
    
    ull l = a[n / 2];
    ull best = 1e18 + 10;
    int k = n / 2;

    for(int i = 0 ; i < n - 1 ; i++){
        if(k + i - 1 >= n - 1)
            break;
            
        best = min(best, (a[k + i - 1] - a[i]) * (a[n - 1] - l));
        l = a[0];
    }

    cout << best << endl;

    return 0;
}