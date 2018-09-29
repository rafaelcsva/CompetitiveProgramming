//01, 07, 2018, 10:48:05 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

int a[100];
bool c[100];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int sum = 0;

    int n;

    cin >> n;

    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];

        sum += a[i];
    }

    if(n == 1){
        cout << "-1" << endl;
        return 0;
    }

    bool ok = false;
    
    for(int i = 1 ; i <= n ; i++){
        if(sum - a[i] != a[i]){
            ok = true;
            c[i] = true;
            break;
        }
    }

    if(ok){
        cout << n - 1 << endl;

        for(int i = 1 ; i <= n ; i++){
            if(!c[i]){
                cout << i << ' ';
            }
        }

        cout << endl;
    }else{
        cout << "-1" << endl;
    }
    

    return 0;
}