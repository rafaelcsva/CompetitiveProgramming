//18, 08, 2018, 10:10:44 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int q;

    scanf("%d", &q);

    while(q--){
        int n;

        scanf("%d", &n);

        ll carry = 0LL;

        for(int i = 0 ; i < n ; i++){
            ll a, b;

            scanf("%lld %lld", &a, &b);

            b += carry;
            carry = 0LL;

            if(a < b){
                carry = b - a;
            }
        }

        if(carry){
            printf("1\n");
        }else{
            printf("0\n");
        }
    }

    return 0;
}