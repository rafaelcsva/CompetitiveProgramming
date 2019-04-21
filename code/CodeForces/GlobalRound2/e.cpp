//06, 04, 2019, 10:06:13 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 3e5 + 100;
int n;
ll a[N];
ll ac = 0LL;
set< int > one, two;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 0 ; i < n ; i++){
        cin >> a[i];

        ac += a[i] / 3LL;
        a[i] %= 3LL;
    }

    for(int i = n - 1 ; i >= 0 ; i--){
        if(a[i] == 1LL){
            one.insert(i);
        }

        if(a[i] == 2LL){
            two.insert(i);
        }
    }

    for(int i = n - 1 ; i >= 0 ; i--){
        one.erase(i);
        two.erase(i);

        if(a[i] <= 1LL){
            continue;
        }

        if(one.size()){
            auto u = one.lower_bound(i);

            u = prev(u);
            a[*u] = 0LL;

            ac++;
            one.erase(u);
        }else if(two.size()){
            auto u = two.begin();

            // u = prev(u);
            a[*u] = 1LL;

            ac++;
            
            two.erase(u);
            one.insert(*u);
        }
    }

    cout << ac << endl;

    return 0;
}