//23, 07, 2018, 09:20:09 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;
map<set<ll>, int>mp;

ll pow(int t, int p, int i){
    ll j = 1;

    while(t){
        j = i * j;
        j %= p;
        t--;
    }

    return j;
}

bool ver[100000];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll p, l;

    scanf("%lld %lld", &p, &l);

    for(ll d = 1 ; d < p ; d++){

        int t = 1;

        for(int i = 1 ; i < p ; i++){
            t *= d;
            t %= p;

            printf("%3d ", t);
        }
        printf("\n");
    }

    return 0;
}