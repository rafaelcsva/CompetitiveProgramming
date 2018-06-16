//24, 05, 2018, 10:31:26 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

const int N = int(2e5 + 100);
int a[N];
int pref[N];

int main(){
    int n, k, q;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k >> q;

    for(int i = 0 ; i < n ; i++){
        int l, r;

        cin >> l >> r;
        a[l]++;
        a[r + 1]--;
    }

    for(int i = 1; i < N ; i++){
        a[i] += a[i - 1];
    }

    for(int i = 0 ; i < N ; i++){
        if(a[i] < k){
            a[i] = 0;
        }else{
            a[i] = 1;
        }
    }

    for(int i = 1 ; i < N ; i++){
        a[i] += a[i - 1];
    }

    for(int i = 0 ; i < q ; i++){
        int l, r;

        cin >> l >> r;

        cout << a[r] - a[l - 1] << endl;
    }

    return 0;
}