//28, 02, 2019, 15:28:24 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

class Photo{
    public:
    char type;
    int idx1, idx2;
    set< string > con;

    Photo(){

    }

    Photo(char t, int id1, int id2){
        this->type = t;
        this->idx1 = id1;
        this->idx2 = id2;
    }
};

const int N = int(1e5 + 10), M = int(1e8);
Photo photos[N];
vector< int > idx_v, idx, p_idx_v;
set< string > hash1[N];
vector< Photo > mphotos;
int cur = 1;
int it = 0;
int gbest = -1;
vector< Photo > resp;

set< string > get_string(int id){
    set< string > con;

    for(string s: hash1[mphotos[id].idx1]){
        con.insert(s);
    }
    
    if(mphotos[id].type == 'V'){
        for(string s: hash1[mphotos[id].idx2]){
            con.insert(s);
        }
    }
    // cout << id << " " << con.size() << endl;
    return con;
}

set< string > get_con(int id){
    return mphotos[id].con;
}

void get_resp(){
    // assert(idx[0] >= 0);
    set< string > t1 = get_con(idx[0]);

    int start = 0;
    int best = 0;
    int resp_st = start;
    int resp_en = start;
    int carry = 0;

    for(int i = 1 ; i < mphotos.size() ; i++){
        int ret = 0;
        set< string > tmp = get_con(idx[i]);

        for(string s: tmp){
            if(t1.find(s) != t1.end()){
                ret++;
            }
        }

        if(ret == 0){
            if(carry > best){
                resp_st = start;
                resp_en = i - 1;
                best = carry;
            }

            carry = 0;
            start = i;
        }else{
            carry += min({int(t1.size() - ret), int(tmp.size() - ret), ret});
            
            if(i == mphotos.size() - 1){
                if(carry > best){
                    resp_st = start;
                    resp_en = i;
                    best = carry;
                }
            }
        }

        t1 = tmp;
    }

    if(best > gbest){
        gbest = best;
        resp.clear();

        for(int i = resp_st ; i <= resp_en ; i++){
            resp.push_back(mphotos[idx[i]]);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    
    int n;

    cin >> n;

    for(int i = 0 ; i < n;  i++){
        cin >> photos[i].type;

        if(photos[i].type == 'V'){
            idx_v.push_back(i);
        }else{
            mphotos.push_back({'H', i, -1});
        }

        int sz;

        cin >> sz;

        for(int j = 0 ; j < sz ; j++){
            string s;

            cin >> s;

            hash1[i].insert(s);
        }

        if(photos[i].type == 'H'){
            mphotos[mphotos.size() - 1].con = hash1[i];
        }
    }

    for(int i = 0 ; i < idx_v.size() ; i++){
        p_idx_v.push_back(i);
    }

    int off = mphotos.size();

    for(int i = 0 ; i < (idx_v.size() / 2) + mphotos.size() ; i++){
        idx.push_back(i);
    }
    // assert(idx.size() > 0);

    for(int i = 1 ; i < idx_v.size() ; i += 2){
        mphotos.push_back(Photo('V', idx_v[i], idx_v[i - 1]));
        mphotos[mphotos.size() - 1].con = get_string(mphotos.size() - 1);
    }
    // cout << mphotos.size() << endl;
    // for(int i = 0 ; i < mphotos.size() ; i++){
    //     cout << mphotos[i].idx1 << " " << mphotos[i].idx2 << endl;
    //     cout << idx[i] << endl;
    // }

    int best = 0;

    while(it < 10){
        int mit = 0;

        while(mit < 100){
            get_resp();

            shuffle(idx.begin(), idx.end(), rng);        
            mit++;
        }

        it++;
        shuffle(p_idx_v.begin(), p_idx_v.end(), rng);

        for(int i = 1 ; i < idx_v.size() ; i += 2){
            mphotos[off + i] = Photo('V', idx_v[p_idx_v[i]], idx_v[p_idx_v[i - 1]]);
            mphotos[off + i].con = get_string(off + i);
        }
    }

    cout << "+ " << gbest << endl;
    cout << resp.size() << endl;
    
    for(int i = 0 ; i < resp.size() ; i++){
        if(resp[i].type == 'V'){
            cout << resp[i].idx1 << " " << resp[i].idx2 << endl;
        }else{
            cout << resp[i].idx1 << endl;
        }
    }

    return 0;
}