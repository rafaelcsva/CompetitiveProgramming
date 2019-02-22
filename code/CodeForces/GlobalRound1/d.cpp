//13, 02, 2019, 16:42:35 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(1e6 + 100);
int a[N];
int cnt[N], cnt2[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n >> m;

    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];

        cnt[a[i]]++;
        cnt2[a[i]]++;
        cout << "a[i] = " << a[i] << " " << cnt[a[i]] << endl;
    }

    int triplets1 = 0, triplets2 = 0;

    for(int i = m ; i >= 1 ; i--){
        cout << i << " " << cnt[i] << endl;

        triplets1 += cnt[i] / 3;
        cnt[i] %= 3;

        if(i >= 3){
            int r = min({cnt[i], cnt[i - 1], cnt[i - 2]});
            triplets1 += r;
            cnt[i - 1] -= r;
            cnt[i - 2] -= r;
        }
    }

    cout << triplets1 << endl;

    for(int i = 1 ; i <= m ; i++){
        triplets2 += cnt2[i] / 3;
        cnt2[i] %= 3;

        if(i <= m - 2){
            int r = min({cnt2[i], cnt2[i + 1], cnt2[i + 2]});
            triplets2 += r;
            cnt2[i + 1] -= r;
            cnt2[i + 2] -= r;
        }
    }

    cout << min(triplets1, triplets2) << endl;
    
    return 0;
}