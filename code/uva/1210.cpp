#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

const int N = 10010, S = 1000;
int dp[N][S][3];
int used[N][S][3];
vector<int>primes;
bool isComposite[N];

void sieve(){
    for(int i = 2 ; i * i < N ; i++){
        if(!isComposite[i]){
            for(int j = i + i ; j < N ; j += i){
                isComposite[j] = true;
            }
        }
    }

    for(int i = 2 ; i < N ; i++){
        if(!isComposite[i]){
            primes.push_back(i);
        }
    }
}

int solve(int s, int p, int started){
    if(s < 0)
        return 0;
    
    if(s == 0)
        return 1;

    if(p >= primes.size() || primes[p] > s){
        return 0;
    }

    int &ans = dp[s][p][started];

    if(used[s][p][started])
        return ans;

    used[s][p][started] = 1;

    if(!started){
        ans = solve(s, p + 1, 0);
    }

    ans += solve(s - primes[p], p + 1, 1);

    return ans;
}

int main(){
    ll n;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    while(cin >> n){
        if(n == 0)
            break;

        cout << solve(n, 0, 0) << endl;
    }

    return 0;
}