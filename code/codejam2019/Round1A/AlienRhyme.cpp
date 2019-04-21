//12, 04, 2019, 22:07:34 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

typedef pair< string, int >     psi;

const int N = 1010;
map< string, int > mp;
bool taked[N];
string w[N];
vector< psi > v;

bool compar(psi &aa, psi &bb){
    string a = aa.first;
    string b = bb.first;

    if(a.length() > b.length()){
        return true;
    }else if(a.length() < b.length()){
        return false;
    }else{
        if(a > b){
            return true;
        }else if(a < b){
            return false;
        }else{
            return aa.second < bb.second;
        }
    }
}

string intersection(string &a, string &b){
    string tmp = "";
    int d = int(a.length()) - 1;
    int e = int(b.length()) - 1;

    while(d >= 0 && e >= 0){
        if(a[d] != b[e]){
            break;
        }

        tmp.push_back(a[d]);
        d--, e--;
    }

    return tmp;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    int ts = 1;

    cin >> t;

    while(t--){
        int n;

        cin >> n;

        for(int i = 0 ; i < n ;i++){
            cin >> w[i];

            string tmp = "";

            for(int j = int(w[i].length()) - 1 ; j >= 0 ; j--){
                tmp.insert(tmp.begin(), w[i][j]);
                // cout << tmp << endl;
                v.push_back({tmp, i});
            }
        }

        sort(v.begin(), v.end(), compar);

        int cnt = 0;

        for(int i = 0 ; i < int(v.size()) - 1 ; i++){
            if(!taked[v[i].second] && !mp[v[i].first]){
                int j = i + 1;

                while(j < v.size() && v[j].first == v[i].first && taked[v[j].second]){
                    j++;
                }

                if(j < v.size() && v[j].first == v[i].first && !taked[v[j].second]){
                    cnt += 2;
                    taked[v[i].second] = taked[v[j].second] = true;
                    mp[v[i].first]++;
                }

                j = i - 1;
            }
        }

        // for(map< string, int >::iterator it = mp.begin() ; it != mp.end() ; it++){
        //     string t = it->first;
        //     // cout << t << " is choosed" << endl;
        //     cnt += min(it->second, int(t.length())) * 2;
        // }

        cout << "Case #" << ts++ << ": " << cnt << endl;

        memset(taked, false, sizeof taked);
        v.clear();
        mp.clear();
    }   

    return 0;
}