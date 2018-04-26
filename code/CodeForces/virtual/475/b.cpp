//22, 04, 2018, 10:07:15 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int cnt[5000];

int main(){
    int n, a, b, c, t;

    cin >> n >> a >> b >> c >> t;

    for(int i = 0 ; i < n ; i++){
        int x;

        cin >> x;

        cnt[x]++;
    }

    ll rmv = 0LL;
    ll tot = 0LL;
    ll r = 0LL;
    ll add = 0LL;

    for(int i = 1 ; i <= t ; i++){
        if(c > b){ 
            rmv = rmv + tot * b;

            add += tot * c;  
            tot += cnt[i];
        }else{
            r += cnt[i] * a;        
        }
    }

    if(c > b){
        cout << a * n - rmv + add << endl;
    }else{
        cout << r << endl;
    }

    return 0;
}