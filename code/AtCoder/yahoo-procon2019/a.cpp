//09, 02, 2019, 10:01:29 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;

    cin >> n >> k;

    if((n + 1) / 2 >= k){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}