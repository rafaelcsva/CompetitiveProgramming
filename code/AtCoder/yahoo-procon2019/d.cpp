//09, 02, 2019, 10:42:14 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(2e5 + 10);
ll a[N];
ll pref[N], suf[N];
ll dp_left[N][2], dp_right[N][2];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int l;

    cin >> l;

    for(int i = 1 ; i <= l ; i++){
        cin >> a[i];

        pref[i] = a[i] + pref[i - 1];
    }

    for(int i = l ; i >= 1 ; i--){
        suf[i] = suf[i + 1] + a[i];
    }

    //compute dp_left
    for(int i = 1 ; i <= l ; i++){
        ll cost_go_and_back = 0LL, cost_just_go = 0LL;

        if(a[i] == 0LL){
            cost_go_and_back = 2LL;
            cost_just_go = 1LL;
        }else if(a[i] & 1LL){
            cost_go_and_back = 1LL;
        }else{
            cost_just_go = 1LL;
        }

        dp_left[i][0] = min({dp_left[i - 1][0] + cost_just_go, dp_left[i - 1][1] + cost_just_go,pref[i]});
        dp_left[i][1] = min(dp_left[i - 1][1] + cost_go_and_back, pref[i]);
    }
    
    //compute dp_right
    for(int i = l ; i >= 1 ; i--){
        ll cost_go_and_back = 0LL, cost_just_go = 0LL;

        if(a[i] == 0LL){
            cost_just_go = 1LL;
            cost_go_and_back = 2LL;
        }else if(a[i] & 1LL){
            cost_go_and_back = 1LL;
        }else{
            cost_just_go = 1LL;
        }

        dp_right[i][0] = min({dp_right[i + 1][0] + cost_just_go, dp_right[i + 1][1] + cost_just_go,suf[i]});
        dp_right[i][1] = min(dp_right[i + 1][1] + cost_go_and_back, suf[i]);
    }

    ll best = ll(1e18);

    for(int i = 0 ; i <= l ; i++){
        best = min(best, dp_left[i][0] + dp_right[i + 1][1]);
        best = min(best, dp_left[i][1] + dp_right[i + 1][0]);
        best = min(best, dp_left[i][1] + dp_right[i + 1][1]);
    }

    cout << best << endl;

    return 0;
}