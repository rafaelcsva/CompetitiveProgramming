#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 1e6;
int pref[N];
vector< int > indices[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, c;

    cin >> n >> c;

    for(int i = 1 ; i <= n ; i++){
        int ai;
        
        pref[i] = pref[i - 1];

        cin >> ai;

        if(ai != c){
            indices[ai].push_back(i);
        }else{
            pref[i]++;
        }
    }

    int best = pref[n];

    for(int val = 1 ; val < N ; val++){
        if(indices[val].size() == 1){
            best = max(best, 1 + pref[n]);
        }
        else if(indices[val].size() > 1){
            best = max(best, 1 + pref[n]);
            int st = indices[val][0];
            int en = st;
            int taked = 1;

            for(int j = 1 ; j < indices[val].size() ; j++){
                int v = indices[val][j];
                int tot = pref[v] - pref[st - 1];

                if(tot > taked){
                    st = en = v;
                    taked = 1;
                }else{
                    en = v;
                    taked++;
                }

                best = max(best, taked + pref[n] - (pref[en] - pref[st - 1]));
            }
        }
    }

    cout << best << endl;

    return 0;
}