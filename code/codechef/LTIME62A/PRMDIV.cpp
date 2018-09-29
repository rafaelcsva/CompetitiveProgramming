//28, 07, 2018, 13:00:39 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(1e6 + 10);
int a[N];
int s[N];
bool is_composite[N];
vector<int>primes;
vector<int>cnt[N];

void sieve(){
    for(int i = 2 ; i * i < N ; i++){
        if(!is_composite[i]){
            for(int j = i * i ; j < N ; j += i){
                is_composite[j] = true;
            }
        }
    }

    for(int i = 2 ; i < N ; i ++){
        if(!is_composite[i]){
            primes.push_back(i);
        }
    }
}

ll calc(ll n, ll b){
    ll sum = 0LL;

    for(int i = 0 ; i < cnt[b].size() ; i++){
        ll k = cnt[b][i];

        if(n % k == 0LL){
            // cout << n << ' ' << k << endl;
            sum++;
        }
    }

    return sum;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    
    for(int i = 2 ; i < N ; i++){
        int p_sum = 0;
        
        int ti = i;

        for(int p = 0 ; p < primes.size() && primes[p] * primes[p] <= ti ; p++){
            int k = primes[p];

            if(ti % k == 0){
                p_sum += k;
                
                while(ti % k == 0){
                    ti /= k;
                }
            }
        }

        if(ti != 1){
            p_sum += ti;
        }

        s[i] = p_sum;
    }

    int t;

    cin >> t;

    while(t--){
        int n;

        cin >> n;

        for(int i = 0 ; i < n ; i++){
            cin >> a[i];
            int e = a[i];
            cnt[s[e]].push_back(e);
        }

        ll n_pair = 0LL;

        for(int i = 0 ; i < n ; i++){
            int e = a[i];
            // cout << "processing " << a[i] << " with sum " << s[e] << endl;
            for(int j = 1 ; j * j <= s[e] ; j++){
                if(s[e] % j == 0){
                    n_pair += calc(e, j);

                    if(j * j != s[e]){
                        n_pair += calc(e, s[e] / j);
                    }
                }
            }
            n_pair--;
        }

        cout << n_pair << endl;

        for(int i = 0 ; i < n ; i++){
            cnt[a[i]].clear();
        }
    }

    return 0;
}