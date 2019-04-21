//05, 03, 2019, 12:08:34 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll cnt1, cnt2, cnt3, cnt4;

    cin >> cnt1 >> cnt2 >> cnt3 >> cnt4;

    if(cnt3 != 0LL && cnt1 == 0LL){
        cout << 0 << endl;
    }else{
        if(2LL * cnt1 == 2LL * cnt4){
            cout << 1 << endl;
        }else{
            cout << 0 << endl;
        }
    }
    
    return 0;
}