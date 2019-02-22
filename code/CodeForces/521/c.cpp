//16, 11, 2018, 13:27:25 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(1e6 + 10);
vector< int > ind;
int cnt[N];
ll a[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;

    scanf("%d", &n);

    ll sum = 0LL;

    for(int i = 0 ; i < n ;i++){
        scanf("%lld", &a[i]);

        cnt[a[i]]++;

        sum += a[i];
    }

    for(int i = 0 ; i < n ;i++){
        sum -= a[i];
        cnt[a[i]]--;

        if(sum % 2LL == 0){
            if((sum / 2LL) < N && cnt[sum / 2LL]){
                ind.push_back(i + 1);
            }
        }

        sum += a[i];
        cnt[a[i]]++;
    }

    printf("%lu\n", ind.size());

    for(int i = 0 ; i < ind.size() ; i++){
        char c = i == int(ind.size()) - 1 ? '\n' : ' ';

        printf("%d%c", ind[i], c);
    }

    return 0;
}