//10, 08, 2018, 15:38:33 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

map<int, int>mp;
const int N = 2010;
int a[N], b[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;

    scanf("%d %d", &n, &m);

    int best = 0;
    int value = 0;

    for(int i = 0 ; i < n ; i++){
        scanf("%d", &a[i]);
    }

    for(int i = 0 ; i < m ; i++){
        scanf("%d", &b[i]);
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            int diff = b[j] - a[i];

            if(diff >= 0){
                mp[diff]++;

                if(mp[diff] > best){
                    best = mp[diff];
                    value = diff;
                }else if(mp[diff] == best){
                    value = min(value, diff);
                }
            }
        }
    }

    printf("%d\n", value);
    
    return 0;
}