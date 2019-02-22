//10, 02, 2019, 08:59:49 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

class Rank{
    public:
    int a, b, c;

    bool operator <(Rank &other){
        return this->a < other.a;
    }
};

const int N = int(1e5 + 10);
Rank ranks[N];
int BIT[N];

int LSOne(int x){
    return x & (-x);
}

int query(int x){
    int best = INT32_MAX;

    while(x != 0){
        if(BIT[x] != -1)
            best = min(best, BIT[x]);
            
        x -= LSOne(x);
    }

    return best;
}

void update(int x, int val){
    while(x < N){
        if(BIT[x] == -1){
            BIT[x] = val;
        }

        BIT[x] = min(BIT[x], val);
        x += LSOne(x);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while(t--){
        memset(BIT, -1, sizeof BIT);

        int n;

        cin >> n;

        for(int i = 0 ; i < n ; i++){
            cin >> ranks[i].a >> ranks[i].b >> ranks[i].c;
        }

        sort(ranks, ranks + n);

        int cnt = n;

        for(int i = 0 ; i < n ; i++){
            int q = query(ranks[i].b - 1);
            // cout << "q: " << q << endl;

            if(q < ranks[i].c){
                cnt--;
            }

            update(ranks[i].b, ranks[i].c);
        }

        cout << cnt << endl;
    }
    
    return 0;
}