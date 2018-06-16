//03, 06, 2018, 09:01:09 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

int digits(int n){
    int s = 0;

    while(n){
        s += n % 10;
        n /= 10;
    }

    return s;
}

int main(){
    int n;

    cin >> n;

    int best = int(1e9);

    for(int a = 1 ; a < n ; a++){
        int sa = digits(a);
        int sb = digits(n - a);
        
        best = min(best, sa + sb);
    }

    cout << best << endl;

    return 0;
}