//06, 04, 2019, 09:56:33 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< ll, ll >  pll;

const int N = int(2e5);
ll n, q;
ll a[N];
vector< ll > diffs;
ll have;
vector< pll > queries;
ll resp[N];
ll ac = 0LL;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }    

    sort(a, a + n);

    for(int i = 1 ; i < n ; i++){
        diffs.push_back(a[i] - a[i - 1]);
    }

    sort(diffs.begin(), diffs.end());

    cin >> q;

    for(int i = 0 ; i < q;  i++){
        ll li, ri;

        cin >> li >> ri;

        queries.push_back({ri - li, i});
    }

    sort(queries.begin(), queries.end());

    int j = 0;
    ll have = n;

    for(int i = 0 ; i < q ; i++){
        while(j < diffs.size() && diffs[j] <= queries[i].first){
            ac += diffs[j];
            have--;
            j++;
        }

        resp[queries[i].second] = have * (queries[i].first + 1LL) + ac;
    }

    for(int i = 0 ; i < q ; i++){
        cout << resp[i] << ' ';
    }

    cout << '\n';

    return 0;
}