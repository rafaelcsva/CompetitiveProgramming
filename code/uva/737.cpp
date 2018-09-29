//29, 08, 2018, 11:51:53 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

ll area(pii bt, pii up, pii len){
    ll la = up.first - bt.first, lb = up.second - bt.second, l = len.second - len.first;

    if(la < 0LL || lb < 0LL || l < 0LL){
        return 0LL;
    }

    return la * lb * l;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    while(true){
        int n;

        scanf("%d", &n);

        if(n == 0)
            break;
            
        int a, b, c, l;

        pii bt = {-1, -1}, up = {-1, -1}, len;

        scanf("%d %d %d %d", &a, &b, &c, &l);

        bt = {a, b};
        up = {a + l, b + l};
        len = {c, c + l};

        for(int i = 0 ; i < n - 1 ; i++){
            scanf("%d %d %d %d", &a, &b, &c, &l);

            bt.first = max(bt.first, a);
            bt.second = max(bt.second, b);
            up.first = min(up.first, a + l);
            up.second = min(up.second, b + l);

            len.first = max(len.first, c);
            len.second = min(len.second, c + l);    
        }

        cout << area(bt, up, len) << endl;
    }

    return 0;
}