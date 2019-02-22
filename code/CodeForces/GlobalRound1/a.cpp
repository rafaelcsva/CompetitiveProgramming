//13, 02, 2019, 16:15:22 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(1e5 + 10);
int mpow[N];
const int mod = 2;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int b, k;

    cin >> b >> k;

    int ac = 1;

    for(int i = 0 ; i <= k ; i++){
        mpow[i] = ac;
        ac *= b;
        ac %= mod;
    }

    int res = 0;

    for(int i = k - 1 ; i >= 0 ; i--){
        int ai;

        cin >> ai;
        
        res += ai * mpow[i];
        res %= mod;
    }

    if(res){
        cout << "odd" << endl;
    }else{
        cout << "even" << endl;
    }

    return 0;
}