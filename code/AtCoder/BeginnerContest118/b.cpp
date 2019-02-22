//16, 02, 2019, 10:02:02 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 100;
int cnt[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n >> m;

    for(int i = 0 ; i < n ; i++){
        int ki;

        cin >> ki;

        for(int j = 0 ; j < ki ; j++){
            int ai;

            cin >> ai;
            cnt[ai]++;
        }
    }

    int tot = 0;

    for(int i = 1 ; i <= m ; i++){
        tot += (cnt[i] == n);
    }

    cout << tot << endl;
    
    return 0;
}