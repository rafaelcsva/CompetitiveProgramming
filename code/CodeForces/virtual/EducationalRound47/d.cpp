//15, 07, 2018, 18:13:57 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

const int N = int(1e5 + 10);
bool is_composite[N];
vector<int>primes;
vector<pii>answer;
ll n, m;

void sieve(){
    for(int i = 2 ; i * i < N ; i++){
        if(!is_composite[i]){
            for(int j = i * i ; j < N ; j += i){
                is_composite[j] = true;
            }
        }
    }

    for(int i = 2 ; i < N ; i++){
        if(!is_composite[i]){
            primes.push_back(i);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    ll mx = (n * (n - 1LL)) / 2LL;

    if(m > mx){
        cout << "Impossible" << endl;
        return 0;
    }

    if(n == 1){
        cout << "Possible" << endl;
        return 0;
    }

    for(int i = 1 ; i <= n ; i++ ){
        if(i == 2){
            continue;
        }

        answer.push_back({i, 2});
        m--;
    }

    try_generate(1);
    
    if(answer.size() == m){
        cout << "Possible" << endl;

        for(int i = 0 ; i < answer.size() ; i++){

        }
    }else{
        cout << "Impossible" << endl;
    }

    return 0;
}