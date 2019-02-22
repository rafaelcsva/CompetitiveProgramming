//15, 12, 2018, 12:51:04 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(2e5 + 100);
int n;
ll a[N], b[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 0 ; i < n / 2 ; i++){
        cin >> b[i];
    }

    int i = 1, j = n - 2;
    ll rg = b[0];
    a[n - 1] = b[0];
    ll lf = 0;

    for(int k = 1 ; k < n / 2 ; k++){
        if(b[k] < rg){
            a[i] = lf;
            a[j] = b[k] - lf;
            lf = a[i];
            rg = a[j];
        }else{
            ll nl = b[k] - rg;

            if(nl >= lf){
                a[i] = nl;
                a[j] = rg;
                lf = a[i];
                rg = a[j];
            }else{
                ll nr = b[k] - lf;

                a[j] = nr;
                a[i] = lf;

                lf = a[i];
                rg = a[j];
            }
        }

        i++, j--;
    }

    for(int i = 0 ; i < n ; i++){
        cout << a[i] << " ";
    }

    cout << endl;
    
    return 0;
}