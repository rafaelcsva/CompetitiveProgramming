#include <bits/stdc++.h>
    
using namespace std;
    
typedef long long ll;
typedef pair<int, int> pii;
    
const int N = 5100;
ll a[N];
const ll mod = (1e9 + 7LL);
ll c[N][N];
ll p[N][N];
ll x, y, d;
ll many[N];
    
ll MOD(ll v, ll mod)
{
    if (v >= 0LL && v < mod)
    {
        return v;
    }
    
    return ((v % mod) + mod) % mod;
}
    
void pascal(){
    for(int i = 0 ; i < N ; i++){
        c[i][0] = c[i][i] = 1LL;
    
        for(int j = 1 ; j < i ; j++){
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
            c[i][j] = MOD(c[i][j], mod - 1LL);
        }
    }
}
    
// store x, y, and d as global variables
void extendedEuclid(ll a, ll b)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        d = a;
        return;
    }
    // base case
    extendedEuclid(b, a % b);
    // similar as the original gcd
    ll x1 = y;
    ll y1 = x - (a / b) * y;
    x = x1;
    y = y1;
}
    
ll inverso(ll v){
    extendedEuclid(v, mod);
    
    return MOD(x, mod);
}
    
ll fast_pow(ll x, int i){
    if(i == 0){
        return 1LL;
    }
    
    if(i == 1){
        return x;
    }
    
    ll a = fast_pow(x, i / 2);
    
    a *= a;
    a %= mod;
    
    if(i & 1){
        a *= x;
    }
    
    return a % mod;
}
    
ll calc(ll where, ll size, ll n){
    size--;
    
    if(where - size >= 0){
        return min(size - 1, n - where - 1);
    }
    
    return min(where, n - size);
}
    
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    pascal();
    
    int t;
    
    scanf("%d", &t);
    
    while(t--){
        int n, k;
    
        scanf("%d %d", &n, &k);
    
        for(int i = 0 ; i < n ; i++){
            scanf("%lld", &a[i]);
        }
    
        sort(a, a + n);
    
        ll r = 1LL;
    
        for(int i = 1 ; i < n - 1 ; i++){
            ll sum = 0LL;
    
            for(int size = k ; size <= n ; size++){
                ll much = calc(i, size, n);
                sum += c[size - 3][k - 3] * much;
                sum = MOD(sum, mod - 1);
            }
    
            many[i] = sum;
        }
    
        for(int i = 1 ; i < n - 1 ; i++){
            r *= fast_pow(a[i], many[i]);
            r = MOD(r, mod);
        }
    
        printf("%lld\n", r);
    }
    
    return 0;
} 