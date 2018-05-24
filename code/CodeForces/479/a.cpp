//06, 05, 2018, 11:06:17 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

int main(){
    int n, k;

    cin >> n >> k;

    while(k){
        if(n % 10 == 0){
            n /= 10;
        }else{
            n--;
        }

        k--;
    }

    cout << n << endl;
    
    return 0;
}