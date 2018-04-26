//24, 04, 2018, 19:06:07 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int k;

int solve(int n, int r){
    
    if(r >= k){
        n += r / k;
        r = r % k;
    }else if(n == 0){
        return 0;
    }

    return n + solve(0, r + n);
}

int main(){
    int n;

    while(cin >> n >> k){
        cout << solve(n, 0) << endl;
    }

    return 0;
}