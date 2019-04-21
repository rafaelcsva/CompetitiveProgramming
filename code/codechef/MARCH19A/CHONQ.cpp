//02, 03, 2019, 10:49:45 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< ll, ll >  pll;

const ll N = int(1e5 + 10), B = int(1e5), LIM = 100;
int sz_change[N];
pll change_number[N][650];
const int STEPS_NUM = int(1e5 + 10);
ll events[STEPS_NUM];
ll a[N];
ll cur_val[N];
ll sum = 0LL;
ll n, k;

int main(){
    for(ll number = 1 ; number <= B ; number++){
        ll carry = -1;
        ll cur = 0;

        for(ll j = 1 ; j <= min(LIM, number) ; j++){
            ll div = number / j;

            if(div != cur){
                change_number[number][sz_change[number]++] = {div, number / div};
            }

            cur = div;
        }

        // if(number == B){
        //     cout << cur << " eh o cur" << endl;
        // }
        cur = LIM;
        for(ll k = number / LIM ; k >= 1LL ; k--){
            ll div = number / k;

            if(div != cur){
                change_number[number][sz_change[number]++] = {k, div};
            }

            cur = div;
        }
    }

    // for(int i = 0 ; i < sz_change[B] ; i++){
    //     printf("%lld\n", change_number[B][i]);
    // }
    int t;
    
    scanf("%d", &t);
    // t = 5;
    // printf("%d tem ele\n", sz_change[B]);
    
    while(t--){
        scanf("%lld %lld", &n, &k);
        // n = int(1e5), k = int(1e5);
        int events_count = 0;

        for(ll i = 1LL ; i <= n ; i++){
            scanf("%lld", &a[i]);
            // a[i] = B;
            sum += (a[i] / i);
            cur_val[i] = (a[i] / i);
            
            // events_count += sz_change[a[i]];
            
            for(int j = 0 ; j < sz_change[a[i]] ; j++){
                ll div = change_number[a[i]][j].first;
                ll val = change_number[a[i]][j].second;
                
                if(i >= div){
                    events[i - div] += val - cur_val[i];
                    // cout << a[i] / div << " " << div << " " << cur_val[i] << " " << i << endl;
                    // if(events[i - div] < 0LL){
                    //     cout << a[i] / div << " " << div << " " << cur_val[i] << " " << i << endl;
                    //     return 0;
                    // }

                    cur_val[i] = val;
                //     events[i - div].push_back(i);
                //    events[i - div] = 
                //     assert(events[i - div] >= 0LL);
                    
                }
            }
        }

        ll resp = n + 1LL;
        
        // cout << "entrei com " << sum << endl;

        // int events_count = 0;

        for(ll steps = 0 ; steps < n ; steps++){
            sum -= a[steps];
            
            // events_count += events[steps].size();
            sum += events[steps];
            // for(int i = 0 ; i < events[steps].size() ; i++){
                
            //     ll div = events[steps][i] - steps;
            //     //printf("%lld eh divisor de %lld\n", div, a[events[steps][i]]);
            //     sum -= cur_val[events[steps][i]];
            //     cur_val[events[steps][i]] = a[events[steps][i]] / div;
            //     sum += cur_val[events[steps][i]];
            //     // if(sum < 0LL){
            //     //     cout << div << endl;
            //     //     return 0;
            //     // }
            // }
            //printf("tenho soma = %lld no passo %lld\n", sum, steps);
            // assert(sum >= 0LL);
            // if(sum < 0LL){
            //     cout << steps << " " << sum << endl;
            //     return 0;
            // }
            
            if(sum <= k){
                resp = steps + 1;
                break;
            }
        }
        
        // printf("sai com sum = %lld | events_count = %d\n", sum, events_count);
        sum = 0LL;
        printf("%lld\n", resp);
        
       memset(events, 0LL, sizeof events);
    }
    
    return 0;
}