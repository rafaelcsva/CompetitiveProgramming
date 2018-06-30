//23, 06, 2018, 09:22:12 Rafaelcs cpp
#include <bits/stdc++.h>
    
using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
    
typedef unsigned long long ull;
    
const int N = 1000;

void add(ll &s, ll go){
    while(go){
        s = 9LL + s * 10LL;
        go /= 10LL;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int k;
    
    cin >> k;
    
    ll s = 0LL;
    
    while(k){
        for(int j = 1 ; j <= 9 && k ; j++){
            k--;
    
            cout << j ;
    
            if(s){
                cout << s;
            }
    
            cout << endl;
        }
    
       s = 9LL + s * 10LL; 
    
        if(s == 999){
            break;
        }
    }
    
    s /= 10LL;
    
    for(ll go = 1 ; k ; go++){
        ll x = 1LL;
    
        while(x <= go && k){
            for(int j = 0 ; j <= 9 && k ; j++){
                cout << x << j << s << endl;
                k--;
            }
            x++;
        }

        add(s, go);
    
        while(x <= 9 && k){
            k--;
            cout << x << s << endl;
            x++;
        }
    }
    
    return 0;
}