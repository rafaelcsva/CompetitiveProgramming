#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const ll mod = ll(1e9 + 7LL);
const int N = int(1e6 + 10);
char s[N];

ll fast_expo(ll x, int e){
    ll d = 1LL;
    ll r = x;
    
    while(e){
        if(e & 1){
            d = (d * r) % mod;
        }
        
        r = (r * r) % mod;
        e >>= 1;
    }
    
    return d;
}

int main(){
    int t;
    
    scanf("%d", &t);
    
    for(int test = 1 ; test <= t ; test++){
        int n, k;
        
        scanf("%d %d", &n, &k);
        
        scanf("\n%s", s);
        
        int sum = 0;
        ll tot = 0LL;
        
        for(int i = n - 1 ; i >= 0 ; i--){
            if(s[i] == 'A')
                sum--;
            else
                sum++;
                
            sum = max(sum, 0);
            
            if(sum > k){
                sum -= 2;
                tot = (tot + fast_expo(2LL, i + 1)) % mod;
            }
            
            sum = max(sum, 0);
        }
        
        printf("Case #%d: %lld\n", test, tot);
    }
    
    return 0;
}