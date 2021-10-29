#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int l;

    cin >> l;

    ll cur = 1LL;
    stack< ll > st;
    ll x = 0LL;
    ll mx = (1LL << 32LL) - 1LL;

    for(int i = 0 ; i < l ; i++){
        string comm;

        cin >> comm;

        if(comm == "end"){
            cur = st.top();
            st.pop();
        }else if(comm == "add"){
            if(cur + x > mx){
                cout << "OVERFLOW!!!\n";
                return 0;
            }

            x += cur;
        }else{
            ll nu;

            cin >> nu;

            st.push(cur);

            cur = min(cur * nu, 10LL * mx);
        }
    }

    cout << x << "\n";

    return 0;
}