//30, 12, 2018, 12:36:41 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int y, b,r ;

    cin >> y >> b >> r;

    for(int i = r ; i >= 1 ; i--){
        if(b >= i - 1 && y >= i - 2){
            cout << i + i - 1 + i - 2 << endl;
            return 0;
        }
    }

    return 0;
}