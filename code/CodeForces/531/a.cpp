//09, 01, 2019, 12:38:28 Rafaelcs cpp
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

    if((n % 4) == 3 || (n % 4) == 0){
        cout << 0 << endl;
    }else{
        cout << 1 << endl;
    }
    
    return 0;
}