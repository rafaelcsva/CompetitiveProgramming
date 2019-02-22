//12, 10, 2018, 18:54:48 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(1e6);
int a[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    cin >> t;

    while(t--){
        int n;

        cin >> n;

        for(int i = 0 ; i < n ; i++){
            cin >> a[i];
        }

        for(int i = 0 ; i < n ; i++){
            int x;

            cin >> x;
            a[i] = x - a[i];
        }

        bool ok = true;

        for(int i = 0 ; i < n - 2 ; i++){
            if(a[i] < 0){
                ok = false;
                break;
            }

            a[i + 1] -= 2 * a[i];
            a[i + 2] -= 3 * a[i];
            a[i] = 0;
        }

        for(int i = 0 ; i < n ;  i++){
            if(a[i] != 0){
                ok = false;
                break;
            }
        }

        if(!ok){
            cout << "NIE" << endl;
        }else{
            cout << "TAK" << endl;
        }
    }

    return 0;
}