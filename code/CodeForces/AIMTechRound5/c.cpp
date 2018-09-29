//27, 08, 2018, 14:11:41 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 4e5;

map<int, int>compx, compy;
set<int>stx, sty;
int bax[N], bay[N];
vector< int > slots_in[N], slots_out[N];
multiset<int>carry_in, carry_out;
multiset<int>::iterator mit;

typedef struct{
    pii lo, hi;
}Rectangle;

Rectangle p[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;

    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++){
        scanf("%d %d %d %d", &p[i].lo.first, &p[i].lo.second, &p[i].hi.first, &p[i].hi.second);
        stx.insert(p[i].lo.first);
        stx.insert(p[i].hi.first);
        sty.insert(p[i].lo.second);
        sty.insert(p[i].hi.second);
    }
    
    int id1 = 1;

    int id2 = 1;

    for(set<int>::iterator it = sty.begin() ; it != sty.end() ; it++){
        bay[id2] = *it;
        compy[*it] = id2++;
    }

    for(int i = 0 ; i < n ; i++){
        int w = compy[p[i].lo.second];
        slots_in[w].push_back(i);

        int f = compy[p[i].hi.second];

        slots_out[f].push_back(i);
    }

    for(int i = 1 ; i < id2 ; i++){
        if(slots_in[i].size() > 0){
            for(int k = 0 ; k < slots_in[i].size() ; k++){
                int pos = slots_in[i][k];

                carry_in.insert(p[pos].lo.first);
                carry_out.insert(p[pos].hi.first);
            }

            if(carry_in.size() >= n - 1){
                int cnt = 0;

                for(set<int>::iterator it = stx.begin() ; it != stx.end() ; it++){
                    cnt += carry_in.count(*it);

                    if(cnt >= n - 1){
                        cout << *it << " " << bay[i] << endl;
                        return 0;
                    }

                    cnt -= carry_out.count(*it);
                }
            }
        }

        if(slots_out[i].size() > 0){
            for(int k = 0 ; k < slots_out[i].size() ; k++){
                int pos = slots_out[i][k];

                mit = carry_in.find(p[pos].lo.first);
                carry_in.erase(mit);
                
                mit = carry_out.find(p[pos].hi.first);
                carry_out.erase(mit);
            }
        }
    }

    return 0;
}