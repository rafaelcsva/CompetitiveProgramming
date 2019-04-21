//02, 03, 2019, 14:14:16 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const ll N = int(1e5 + 10), B = int(1e5), LIM = 100, M = int(1e8);
int sz_change[N];
ll change_number[N][700];
ll comp[M], pos = 0;
const int STEPS_NUM = int(1e5 + 10);
vector< ll > events[STEPS_NUM];
ll a[N];
ll cur_val[N];
ll sum = 0LL;
ll n, k;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int f = 0;
    for(ll i = 1 ; i <= 63100631LL ; i++){
        comp[pos++] = i;
        f++;

        if(f >= STEPS_NUM){
            f = 0;
        }
    }
    sort(comp, comp + pos);

    return 0;
}