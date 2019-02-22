//05, 10, 2018, 11:31:21 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

vector<pii>v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, l, a;

    cin >> n >> l >> a;

    for(int i = 0 ; i < n ; i++){
        int a, b;

        cin >> a >> b;

        v.push_back({a, b});
    }

    v.push_back({l, 0});

    int tot = 0;
    
    int tim = 0;

    for(int i = 0 ; i < v.size() ; i++){
        tot += (v[i].first - tim) / a;
        tim = v[i].first + v[i].second;
    }

    cout << tot << endl;

    return 0;
}