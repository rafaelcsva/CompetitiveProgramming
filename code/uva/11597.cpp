//11, 06, 2018, 21:05:40 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

int main(){
    int n;
    int test = 1;

    while(cin >> n){
        if(n == 0)
            break;

        cout << "Case " << test++ << ": ";
        cout << n / 2 << endl;
    }
    
    return 0;
}