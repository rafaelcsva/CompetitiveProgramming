#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e6;
int v[N];
set<int>st;
int cnt[N];
int isP[N];
set<int>::iterator it;

int main (){
    int n;

    cin >> n;

    for(int i = 0 ;i  < n ; i++){
        cin >> v[i];
    }

    int ind = 0;

    for(int i = 0 ; i < n ; i++){
        it = lower_bound(st.begin(), st.end(), v[i]);

        if(it == st.end()){
            isP[i] = 1;
        }else if(v[ind] > v[i]){
            cnt[ind]++;
        }

        if(v[ind] < v[i]){
            ind = i;
        }

        st.insert(v[i]);
    }

    int flag = 0;
    int ans = 0;

    for(int i = 0 ; i < n ; i++){
        if(cnt[i] > 1){
            if(cnt[i] + 1 > flag){
                ans -= flag;
                ans += cnt[i] + 1;
            }else{
                if(isP[i]){
                    ans += 1;
                }
            }
        }else if(isP[i]){
            ans += 1;
        }
    }

    cout << ans << '\n';

    return 0;
}