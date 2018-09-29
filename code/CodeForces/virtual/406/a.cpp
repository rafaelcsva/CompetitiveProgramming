//23, 07, 2018, 16:47:48 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll a, b;

    cin >> a >> b;

    int year = 0;

    while(true){
        a *= 3;
        b *= 2;
        year++;

        if(a > b){
            break;
        }
    }

    cout << year << endl;

    return 0;
}