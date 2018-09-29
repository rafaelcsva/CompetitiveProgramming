//01, 07, 2018, 11:26:34 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    int n;
    ll x, y;

    cin >> n >> x >> y;
    cin >> s;
    
    bool chk = false;
    int cnt = 0;
    
    for(int i = 0 ; i < s.length() ; i++){
        if(s[i] == '1'){
            if(chk){
                cnt++;
                chk = false;
            }
            
        }else{
            chk = true;
        }
    }

    ll a = cnt * x + y;

    if(chk){
        cnt++;
    }
    
    ll b = cnt * y;
    
    chk = false;
    cnt = 0;

    reverse(s.begin(), s.end());

    for(int i = 0 ; i < s.length() ; i++){
        if(s[i] == '1'){
            if(chk){
                cnt++;
                chk = false;
            }
            
        }else{
            chk = true;
        }
    }

    ll at = cnt * x + y;

    if(chk){
        cnt++;
    }

    ll bt = cnt * y;

    a = min(a, b);
    at = min(at, bt);

    cout << min(a, at) << endl;

    return 0;
}