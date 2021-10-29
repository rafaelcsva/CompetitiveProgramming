#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n, l, r, s;

        scanf("%d %d %d %d", &n, &l, &r, &s);

        set< int > st;
        for(int i = 1 ; i <= n ; i++){
            st.insert(i);
        }
        vector< int > v;

        int sum = 0;

        for(int i = 1 ; i <= (r - l + 1) ; i++){
            v.push_back(i);
            sum += i;
            st.erase(i);
        }   

        // printf("%d\n", sum);

        if(st.size() && sum != s){
            for(int i = 0 ; i < v.size() ; i++){
                int u = v[i];
                int a = s - sum;
                // for(auto u: st){
                //     printf("el: %d %d\n", u, i);
                // }
                auto fnd = st.upper_bound(u + a);
                
                if(fnd != st.begin()){
                    fnd = prev(fnd);

                    // printf("fnd = %d %d %d %d %d\n", *fnd, u + a, u, a, i);

                    if(*fnd > u){
                        v[i] = *fnd;

                        sum += (*fnd - u);

                        st.insert(u);
                        st.erase(fnd);
                    }
                }
                
            }
        }

        if(sum != s){
            printf("-1\n");
        }else{
            while(--l){
                printf("%d ", *st.begin());
                st.erase(st.begin());
            }

            for(auto u: v){
                printf("%d ", u);
            }

            while(st.size() > 0){
                printf("%d ", *st.begin());
                st.erase(st.begin());
            }

            printf("\n");
        }
    }

    return 0; 
}