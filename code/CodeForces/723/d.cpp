#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long   ll;
 
const int N = int(2e5) + 10;
int cnt[N];
const int D = 4;
int letters[D] = {'A', 'N', 'O', 'T'};
vector< int > v[256];
int bit[N];
 
int LSOne(int x){
    return x & (-x);
}
 
void update(int x, int updt){
    while(x < N){
        bit[x]++;
        x += LSOne(x);
    }
}
 
int query(int x){
    int sum = 0;
 
    while(x > 0){
        sum += bit[x];
        x -= LSOne(x);
    }
 
    return sum;
}
 
int rmq(int l, int r){
    return query(r) - query(l - 1);
}
 
string build_str(){
    string t = "";
 
    for(int i = 0 ; i < D ; i++){
        for(int j = 0 ; j < cnt[letters[i]] ; j++){
            t.push_back(letters[i]);
        }
    }
 
    return t;
}
 
ll get_ans(string &d, string &s){
    memset(bit, 0, sizeof(int) * (s.length() + 2));
 
    for(int i = 0 ; i < s.length() ; i++){
        v[s[i]].push_back(i + 1);
    }
 
    long long ans = 0LL;
 
    for(int i = int(d.length()) - 1 ; i >= 0 ; i--){
        char c = d[i];
 
        auto bg = *v[c].rbegin();
 
        bg -= rmq(1, bg);
    
        bg--;
  
        ans += ll(i - bg);
 
        update(*v[c].rbegin(), 1);
        v[c].pop_back();
    }
 
    return ans;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    
    cin >> t;
    int tmtt = t;

    while(t--){
        string s;
 
        cin >> s;
 
        for(int i = 0 ; i < s.length() ; i++){
            cnt[s[i]]++;
        }
 
        sort(letters, letters + 4);
 
        ll ans = -1;
        string sans = "";
        int perm = 0;
    
        do{
            perm++;
            string d = build_str();
 
            assert(d.length() == s.length());
            auto tans = get_ans(d, s);
 
            // cout << "test " << d << " gives " << tans << endl;
 
            if(tans >= ans){
                ans = tans;
                sans = d;
            }
        }while(next_permutation(letters, letters + D));

        cout << sans << endl;

        for(int i = 0 ; i < D ; i++){
            cnt[letters[i]] = 0;
        }
    }
 
    return 0;
}