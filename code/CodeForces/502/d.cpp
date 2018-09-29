//08, 08, 2018, 11:38:32 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

int n, m, q;
vector< string > all;
map<int, int> cnt;
map<string, int> idx;
map<string, int> masks;
typedef pair<string, int> psi;
vector< pii > v;
const int N = 13;
int w[N];
const int M = 103;
int pre[1 << 12][M];
int vl[1 << 12];

int calc(int mask){
    int sum = 0;
   
    for(int i = 0, j = n - 1 ; i < n ; i++, j--){
        int el = 1 << i;

        if(mask & el){
            // printf("awwuaiefnaqsef\n");
            sum += w[j];
        }
    }

    return sum;
}

// int binary_search(string &s, int k, int id){
    
//     int st = 0, en = vals[id].size() - 1;
//     int r = -1;

//     while(st <= en){
//         int mid = (st + en) / 2;

//         if(vals[id][mid] > k){
//             en = mid - 1;
//         }else{
//             r = mid;
//             st = mid + 1;
//         }
//     }   

//     return r; 
// }

ll tot;

int take(string &s){
    int sum = 0;

    for(int i = 0, j = n - 1 ; i < s.length() ; i++, j--){
        if(s[i] == '1'){
            sum += (1 << j);
        }
    }

    return sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m >> q;
    
     for(int i = 0 ; i < n ; i++){
        cin >> w[i];
        tot += w[i];
    }
    
    for(int i = 0 ; i < (1 << n) ; i++){
        string tmp = "";

        vl[i] = calc(i);
        // cout << i << " is " << vl[i] << endl;
    }
    
   
    for(int i = 0 ; i < m ; i++){
        string s;

        cin >> s;
        
        int x = take(s);
        
        cnt[x]++;
    }

    for(map<int, int>::iterator it = cnt.begin() ; it != cnt.end() ; it++){
        v.push_back({it->first, it->second});
    }
    
    for(int i = 0 ; i < (1 << n) ; i++){
        int id = i;
        
        for(int j = 0 ; j < v.size() ; j++){
            int ida = v[j].first;
        
            int f = tot - vl[ida ^ id];

            // bitset<2>bs1(id), bs2(ida ^ id), bs(ida);

            // cout << bs1 << " perde " << bs2 << " com " << bs << " = " << f << " " << vl[ida ^ id] << endl;
            if(f <= 100)
                pre[id][f] += v[j].second;
        }
        
        for(int j = 0 ; j < M ; j++){
            if(j){
                pre[id][j] += pre[id][j - 1];
            }
        }
    }
    
    while(q--){
        string s;
        int k;

        cin >> s >> k;

        int id = take(s);

        cout << pre[id][k] << endl;
    }

    return 0;
}