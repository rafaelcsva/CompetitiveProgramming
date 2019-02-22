//30, 11, 2018, 15:24:54 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;

    cin >> n >> m;

    ll x1, y1, x2, y2;

    cin >> x1 >> y1 >> x2 >> y2;

    bool has_fountain = false;  
    ll brokes = 0LL;
    ll breaked = 0LL;

    for(ll i = 1LL ; i <= n ; i++){
        if(i == x1){
            has_fountain = true;
        }

        if(has_fountain){
            ll len1 = y1 - 1LL;
            ll len2 = m - y2;

            if((len1 & 1LL) != (len2 & 1LL)){
                brokes++;
            }else if(len1 & 1LL){
                breaked++;
            }
        }else{
            if(m & 1LL){
                brokes++;
            }
        }

        if(i == x2){
            has_fountain = false;
        }
    }

    cout << breaked + (brokes + 1LL) / 2LL << endl;
    
    return 0;
}