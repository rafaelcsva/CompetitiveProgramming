//16, 11, 2018, 12:42:48 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 3e5;
int cnt[N];

bool can(int mid, int k){
    int tot = 0;

    for(int i = 1 ; i < N ; i++){
        tot += cnt[i] / mid;
    }

    return tot >= k;
}

vector< int > resp;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;

    scanf("%d %d", &n, &k);

    for(int i = 0 ; i < n ; i++){
        int xi;

        scanf("%d", &xi);

        cnt[xi]++;
    }

    int lo = 1, hi = 1e6;
    int r = -1;

    while(lo <= hi){
        int mid = (lo + hi) / 2;

        if(can(mid, k)){
            r = mid;
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }
    }

    for(int i = 1 ; i < N ; i++){
        int el = cnt[i] / r;

        while(resp.size() != k && el){
            resp.push_back(i);
            el--;
        }

        if(resp.size() == k){
            break;
        }
    }

    for(int i = 0 ; i < resp.size() ; i++){
        char c = i == int(resp.size()) - 1 ? '\n' : ' ';

        printf("%d%c", resp[i], c);
    }

    return 0;
}