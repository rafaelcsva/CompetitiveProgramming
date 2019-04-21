//23, 02, 2019, 11:23:33 Rafaelcs cpp
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
        ll a;

        cin >> a;

        ll st = 1LL;
        ll day = 0;
        ll gain = a, lost = st;

        while(gain >= lost){
            day++;
            st *= 2LL;
            gain += a;
            lost += st;
        }

        cout << day << " ";

        day = 0;
        st = 1LL;

        while(a > st){
            st *= 2LL;
            day++;
        }

        cout << day << endl;
    }

    return 0;
}