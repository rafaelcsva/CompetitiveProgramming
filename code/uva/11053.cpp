//02, 07, 2018, 14:41:17 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef unsigned long long ll;

// typedef unsigned long long ull;
ll n, a, b;
map<ll, int>pos;
map<ll, int>mark;
int test = 1;

ll f(ll x){
    return ((((a * x) % n) * x) % n + b) % n;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);    

    while(cin >> n){
        if(n == 0)
            break;
        
        cin >> a >> b;
        
        int lambda = 1;

        int k = 0;
        ll l = 0;

        int h = 0, t = 0;

        while(!k || h != t){
            h = f(f(h));
            t = f(t);
            
            k++;
        }

        while(h != t){
            h = f(h);
            t = f(t);
        }

        h = f(t);

        while(h != t){
            h = f(h);
            lambda++;
        }

        cout << n - lambda << endl;
        
        test++;
    }

    return 0;
}