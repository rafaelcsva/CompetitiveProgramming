//04, 06, 2018, 20:05:54 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

const int N = int(2e5 + 100);
int a[N], b[N];
bool bought[N];
vector<pii>v;

int main(){
    int n, k;

    cin >> n >> k;

    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }

    for(int i = 0 ; i < n ; i++){
        cin >> b[i];

        v.push_back({a[i] - b[i], i});
    }

    sort(v.begin(), v.end());

    ll sum = 0LL;

    for(int i = 0 ; i < n ; i++){
        if(v[i].first > 0 && i >= k){
            break;
        }
        
        sum += a[v[i].second];
        bought[v[i].second] = true;
    }

    for(int i = 0 ; i < n ; i++){
        if(!bought[i]){
            sum += b[i];
        }
    }

    cout << sum << endl;

    return 0;
}