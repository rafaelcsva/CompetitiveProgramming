//15, 12, 2018, 12:36:39 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while(t--){
        int xi;

        cin >> xi;

        if(xi >= 2 && xi <= 7){
            cout << 1 << endl;
        }else{
            if(xi & 1){
                cout << 1 + (xi - 5) / 2 << endl;
            }else{
                cout << xi / 2 << endl;
            }
        }
    }
    
    return 0;
}