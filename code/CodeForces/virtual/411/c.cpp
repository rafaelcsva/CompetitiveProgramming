//25, 07, 2018, 16:50:07 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;

    cin >> n;

    if(n == 1){
        cout << 0 << endl;
    }else{
        int q = (n - 2) / 2;

        if(n & 1){
            q += 1;
        }

        cout << q << endl;
    }

    return 0;
}