//01, 04, 2019, 17:43:49 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(1e5);
int a[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while(t--){
        int n, k;

        cin >> n >> k;

        for(int i = 0 ; i < n ; i++){
            cin >> a[i];
        }

        sort(a, a + n);

        int tot = 0;

        int i = 0;

        while(k && i < n && a[i] < 0){
            a[i] *= -1;
            // cout << a[i] << endl;
            k--;
            i++;
        }

        if(k & 1){
            sort(a, a + n);

            a[0] *= -1;
        }

        for(int i = 0 ; i < n ; i++){
            tot += a[i];
        }

        cout << tot << endl;
    }
    
    return 0;
}