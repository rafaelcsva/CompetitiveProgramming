//08, 03, 2019, 17:41:08 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair< int, int > pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

ll current_time;
const int N = int(1e6 + 10);
int n;
ll a[N], b[N];
ll k;

class LapTop{
    public:
    ll mtime, a, b;

    LapTop(ll aa, ll bb){
        this->a = aa;
        this->b = bb;
        this->mtime = 0LL;
    }    

    LapTop(){

    }
    
    ll get_m_time() const{
        ll num = (this->a - this->b * (current_time - this->mtime));

        if(num < 0LL){
            return -1LL;
        }

        return (num) / this->b;
    }
};

LapTop laps[N];

class Comparator{
    public:
    bool operator()(const LapTop &lhs, const LapTop &rhs) const{
        ll rest1 = lhs.get_m_time();
        ll rest2 = rhs.get_m_time();
    
        return rest1 > rest2; 
    }
};

priority_queue< LapTop, vector< LapTop >, Comparator > pq;

bool can(ll power){
    current_time = 0LL;

    while(!pq.empty()){
        pq.pop();
    }

    for(int i = 0 ; i < n ; i++){
        // cout << " colocando " << a[i] << " " << b[i] << endl;
        pq.push(laps[i]);
    }

    // cout << laps[0].get_m_time << " " << laps[1].get_m_time << endl;
    // cout << "meu top eh " << pq.top().a << endl;
    // exit(0);

    // cout << "size = " << pq.size() << endl;
    // cout << "power = " << power << endl;

    while(current_time < k){
        // cout << current_time << " " << k << endl;
        assert(!pq.empty());
        LapTop u = pq.top();
        // cout << "aqui" << endl;
        // cout << u.a << " " << u.b << " sao os dados" << endl;
        // current_time++;

        pq.pop();
        // cout << "dei pop!" << endl;
        // cout << "u = " << u.get_m_time() << endl;

        if(u.get_m_time() < 0LL){
            return false;
        }

        u.a += power;
        // u.mtime = current_time;
        // if(current_time != k - 1)
        pq.push(u);

        current_time++;
    }

    // current_time--;

    // // current_time = k;
    // // cout << "cheguei aqui! tenho " << power << endl; 

    // while(!pq.empty()){
    //     LapTop u = pq.top();
    //     pq.pop();

    //     if(u.get_m_time() <= 0LL){
    //         // cout << u.a << " " << u.b << " falhou!!" << endl;
    //         return false;
    //     }
    // }

    return true;
}

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    scanf("%d %lld", &n, &k);

    for(int i = 0 ; i < n ; i++){
        scanf("%lld", &laps[i].a);
    }

    for(int i = 0 ; i < n ; i++){
        scanf("%lld", &laps[i].b);
    }

    ll lo = 0LL, hi = ll(1e12);
    ll r = -1LL;

    while(lo <= hi){
        ll mid = (lo + hi) >> 1LL;

        if(can(mid)){
            r = mid;
            hi = mid - 1LL;
        }else{
            lo = mid + 1LL;
        }
    }

    printf("%lld\n", r);
    
    return 0;
}