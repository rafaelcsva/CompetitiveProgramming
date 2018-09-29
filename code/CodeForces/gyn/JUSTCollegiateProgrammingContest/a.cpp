//28, 07, 2018, 09:05:57 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

set<pii>st;
set<pii>::iterator it;
const int N = 1e5 + 10;
int v[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    scanf("%d", &t);

    while(t--){
        int n, q;

        scanf("%d%d", &n, &q);

        for(int i = 0 ; i < n ; i++){
            int a;

            scanf("%d", &a);
            v[i] = a;

            if(a == 0)
                continue;

            it = st.lower_bound({a, -1});
            
            if(it == st.end() || it->first != a){
                st.insert({a, 1});
            }else{
                pii u = *it;
                
                st.erase(it);
                u.second++;

                st.insert(u);
            }
        }
        
        while(q--){
            int t;

            scanf("%d", &t);

            if(t == 1){
                int p, val;

                scanf("%d %d", &p, &val);

                p--;

                if(v[p] != val){
                    if(v[p]){
                        it = st.lower_bound({v[p], -1});

                        pii u = *it;
                        st.erase(it);
                        u.second--;

                        if(u.second){
                            st.insert(u);
                        }
                    }

                    if(val){
                        it = st.lower_bound({val, -1});

                        if(it == st.end() || it->first != val){
                            st.insert({val, 1});
                        }else{
                            pii u = *it;
                            st.erase(it);
                            u.second++;

                            st.insert(u);
                        }
                    }

                    v[p] = val;
                }
            }else{
                printf("%lu\n", st.size());
            }
        }
        st.clear();
    }

    return 0;
}