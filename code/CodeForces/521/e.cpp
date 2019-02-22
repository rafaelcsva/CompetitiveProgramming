//16, 11, 2018, 12:59:47 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

map< int, int >mp;
const int N = int(2e5 + 10);
ll cnt[N];
vector< ll > v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;

    scanf("%d", &n);

    int id = 1;

    for(int i = 0 ; i < n ; i++){
        int xi;

        scanf("%d", &xi);

        if(mp.count(xi) == 0){
            mp[xi] = id++;
        }

        cnt[mp[xi]]++;
    }

    for(int i = 1 ; i < N ; i++){
        if(cnt[i]){
            v.push_back(cnt[i]);
        }
    }

    sort(v.begin(), v.end());

    ll best = 0LL;

    for(int i = 0 ; i < v.size() ; i++){
        for(ll j = 1LL ; j <= v[i] ; j++){
            ll ini = 2LL * j;
            ll add = 0LL;
            int idi = i + 1;

            while(true){
                idi = lower_bound(v.begin() + idi, v.end(), ini) - v.begin();

                if(idi == v.size()){
                    break;
                }    

                add += ini;
                ini *= 2LL;
                idi++;

                if(idi == v.size()){
                    break;
                }
            }  

            best = max(best, j + add);
        }  
    }

    printf("%lld\n", best);

    return 0;
}