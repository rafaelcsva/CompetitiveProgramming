//13, 04, 2018, 23:11:40 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int N = int(1e3 + 100);
const ll MX = ll(2e18);
ll r, b, c;
int mark[N];

typedef struct{
    ll m, s, p;
}Cashier;

Cashier ca[N];

bool compar(Cashier a, Cashier b){
    if(a.m > b.m){
        return true;
    }else if(a.m < b.m){
        return false;
    }

    if(a.s < b.s){
        return true;
    }else if(a.s > b.s){
        return false;
    }

    return a.p <= b.p;
}

vector<ll>qtd;

bool can(ll time, ll tot, int robot){
    for(int i = 0 ; i < c ; i++){
        if(ca[i].p < time){
            qtd.push_back(min((time - ca[i].p) / ca[i].s, ca[i].m));
        }
    }

    sort(qtd.begin(), qtd.end());

    ll sum = 0LL;
    int tam = min(r, ll(qtd.size()));
    
    for(int i = qtd.size() - 1, j = 0 ; i >= 0 && j < tam ; i--, j++){
        sum += qtd[i];
    }
    qtd.clear();

    return sum >= tot;
}

int main(){
    int t;
    int test = 1;
    
    cin >> t;

    while(t--){
        cin >> r >> b >> c;

        for(int i = 0 ; i < c ; i++){
            cin >> ca[i].m >> ca[i].s >> ca[i].p;
        }

        sort(ca, ca + c, compar);

        ll start = 1LL, end = MX;
        ll r;

        while(start <= end){
            ll mid = (start + end) / 2;
            ll tot = b;

            if(can(mid, b, 0)){
                end = mid - 1;
                r = mid;
            }else{
                start = mid + 1;
            }
        }

        cout << "CASE #" << test++ << ": " << r << endl;
    }

    return 0;
}