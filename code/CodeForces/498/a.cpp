//16, 07, 2018, 11:37:07 Rafaelcs cpp
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

    for(int i = 0 ; i < n ; i++){
        int x;

        cin >> x;

        if((x & 1) == 0){
            x--;
        }

        cout << x << ' ';
    }

    cout << endl;
    
    return 0;
}