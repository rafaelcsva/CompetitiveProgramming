//21, 09, 2018, 11:53:24 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(2e4);
bool is_composite[N];
vector< int > primes;

void sieve(){
    for(int i = 2 ; i * i < N ; i++){
        if(!is_composite[i]){
            for(int j = i + i ; j < N ; j += i){
                is_composite[j] = true;
            }
        }
    }

    for(int j = 2 ; j < N ; j++){
        if(!is_composite[j]){
            primes.push_back(j);
        }
    }
}

const int M = int(4e5);
const int X = int(2e7);
int mark_p[X], mn_p[X], cnmn_p[X];
int a[M];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    sieve();

    int n;

    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++){
        scanf("%d", &a[i]);
    }

    for(int i = 0 ; i < n ; i++){
        int x = a[i];

        for(int j = 0 ; j < primes.size() ; j++){
            if(primes[j] * primes[j] > x){
                break;
            }

            int cnt = 0;

            while(x % primes[j] == 0){
                x /= primes[j];
                cnt++;
            }

            if(cnt){
                mark_p[primes[j]]++;
            }

            if(mn_p[primes[j]] == 0 || mn_p[primes[j]] == cnt){
                mn_p[primes[j]] = cnt;
                cnmn_p[primes[j]]++;
            }else if(mn_p[primes[j]] > cnt){
                mn_p[primes[j]] = cnt;
                cnmn_p[primes[j]] = 1;
            }
        }

        if(x != 1){
            mark_p[x]++;

            if(mn_p[x] == 0 || mn_p[x] == 1){
                mn_p[x] = 1;
                cnmn_p[x]++;
            }else if(mn_p[x] > 1){
                mn_p[x] = 1;
                cnmn_p[x] = 1;
            }
        }
    }

    int best1 = 1e9;

    for(int i = 2 ; i < X ; i++){
        if(!mark_p[i]){
            continue;
        }
        
        if(mark_p[i] != n){
            best1 = min(best1, n - mark_p[i]);
        }else if(cnmn_p[i] != n){
            best1 = min(best1, cnmn_p[i]);
        }

    }
    // for(map<int, int>::iterator it = mark_p.begin() ; it != mark_p.end() ; it++){
    //     if(it->second != n){
    //         best1 = min(best1, n - it->second);
    //     }else if(cnmn_p[it->first] != n){
    //         best1 = min(best1, cnmn_p[it->first]);
    //         // printf("%d %d %d\n", cnmn_p[it->first], it->first, mn_p[it->first]);
    //     }
    // }

    if(best1 != 1e9){
        printf("%d\n", best1);
    }else{
        printf("-1\n");
    }

    return 0;
}