#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long   ll;

const int N = 21;
ll fat[N];
ll cnt[N];
ll cnt0[N];

vector< int > get_vector(ll number){
    vector< int > v;
    ll d = 2LL;

    while(number){
        v.push_back(number % d);
        number /= d;
        d++;
    }

    return v;
}

bool is_equals(vector< int > a, vector< int > b){
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for(int i = 0 ; i < a.size() ; i++){
        if(a[i] != b[i]){
            return false;
        }
    }

    return true;
}

int main(){
    fat[0] = 1LL;

    for(ll i = 1LL ; i < N ; i++){
        fat[i] = i * fat[i - 1];
    }

    int t;

    scanf("%d", &t);

    while(t--){
        ll ki;

        scanf("%llu", &ki);

        ll d = 2LL;
        vector< int > v = get_vector(ki);

        ll ti = ki - 1;
        int ans = 0;

        while(ti){
            auto ve = get_vector(ti);

            if(ve.size() != v.size()){
                break;
            }

            if(is_equals(ve, v)){
                // printf("+%lld\n", ti);
                ans++;
            }
            ti--;
        }

        ti = ki + 1;

        while(true){
            auto ve = get_vector(ti);

            if(ve.size() != v.size()){
                break;
            }

            if(is_equals(ve, v)){
                // printf("+%lld\n", ti);
                ans++;
            }
            ti++;
        }

        printf("%d\n", ans);
    }

    return 0;
}