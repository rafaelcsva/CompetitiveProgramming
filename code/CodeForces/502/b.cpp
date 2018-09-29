//08, 08, 2018, 11:13:08 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll cnt1 = 0, cnt0 = 0;

    int n;

    cin >> n;

    string a, b;

    cin >> a >> b;
    
    ll tot = 0LL;
    ll qtd0 = 0, qtd1 = 0;
    
    for(int i = 0 ; i < n ; i++){
        if(a[i] == '0'){
            cnt0++;
        }else{
            cnt1++;
        }
        
        if(a[i] == '0' && b[i] == '0'){
            qtd0++;
        }else if(a[i] == '1' && b[i] == '0'){
            qtd1++;
        }
    }

    cout << qtd0 * cnt1 + qtd1 * cnt0 - qtd1 * qtd0 << endl;

    return 0;
}