#include <bits/stdc++.h>

using namespace std;

const int N = int(1e6 + 10);
int a[N];
int cnt[N];

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);
        n *= 2;

        for(int i = 0 ; i < n ; i++){
            scanf("%d", &a[i]);
            cnt[a[i]]++;
        }

        sort(a, a + n);
        vector< pair< int, int > > ans;
        bool ok = false;

        for(int i = 0 ; i < n - 1 ; i++){
            int last = a[n - 1];
            ans.push_back({last, a[i]});
            bool frag = true;
            cnt[last]--;
            cnt[a[i]]--;

            for(int j = n - 2 ; j >= 0 ; j--){
                if(cnt[a[j]]){
                    int o = last - a[j];
                    cnt[a[j]]--;

                    if(!cnt[o]){
                        frag = false;
                    }else{
                        cnt[o]--;
                        ans.push_back({a[j], o});
                        last = max(a[j], o);
                    }
                }
            }

            if(frag){
                ok = true;
                break;
            }else{
                for(int i = 0 ; i < n ; i++){
                    cnt[a[i]]++;
                }
                ans.clear();
            }
        }
        if(ok){
            printf("YES\n");
            printf("%d\n", ans[0].first + ans[0].second);
            for(auto u: ans){
                printf("%d %d\n", u.first, u.second);
            }
        }else{
            printf("NO\n");
        }

        for(int i = 0 ; i < n ; i++){
            cnt[a[i]] = 0;
        }
    }

    return 0;
}