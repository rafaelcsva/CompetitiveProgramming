//16, 07, 2018, 11:37:07 Rafaelcs cpp
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

    int n, k;

    cin >> n >> k;

    for(int i = 0 ; i < n ; i++){
        int x;

        cin >> x;

        v.push_back({x, i});
    }

    sort(v.begin(), v.end());

    int sum = 0;
    vector<int>tmp;

    for(int i = v.size() - 1, j = 0 ; i >= 0 && j != k ; i--, j++){
        sum += v[i].first;
        tmp.push_back(v[i].second);
    }

    sort(tmp.begin(), tmp.end());

    int ini = -1;

    cout << sum << endl;

    for(int i = 0 ; i < k - 1 ; i++){
        cout << tmp[i] - ini << ' ' ;

        ini = tmp[i];
    }

    cout << n - ini - 1 << endl;

    return 0;
}