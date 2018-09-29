//10, 08, 2018, 17:42:02 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef unsigned long long ull;

int b, n;
const int N = int(1e6 + 10);
char s[24];
pii c[N];

bool compar(pii &a, pii &b){
    ll da = a.second - a.first;
    ll db = b.second - b.first;

    return da > db; 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    scanf("%d %d", &b, &n);


    for(int i = 0 ; i < n ; i++){
        scanf("\n%s %s %s %lld %lld", s, s, s, &c[i].first, &c[i].second);
    }

    sort(c, c + n, compar);

    ll score = 0LL;

    for(int i = 0 ; i < n ; i++){
        if(c[i].first <= b){
            score += c[i].second;
            printf("+%lld\n", c[i].second);
            b -= c[i].first;
        }
    }

    printf("%lld\n", score);
    
    return 0;
}