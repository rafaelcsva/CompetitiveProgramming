//06, 05, 2018, 11:16:49 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
const int N = int(2e5 + 100);
int v[N];

int main(){
    int n, k;

    cin >> n >> k;

    for(int i = 0 ; i < n ; i++){
        cin >> v[i];
    }

    sort(v, v + n);

    if(k == 0){
        if(v[0] == 1){
            cout << "-1" << endl;
        }else{
            cout << "1" << endl;
        }
    }else if(k == n){
        cout << v[n - 1] << endl;
    }else{
        k--;
        
        if(v[k] == v[k + 1]){
            cout << "-1" << endl;
        }else{
            cout << v[k] << endl;
        }
    }

    return 0;
}