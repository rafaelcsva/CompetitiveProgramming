#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = 50;
ll c[N][N];
ll box[N];

int main(){
    int n, k;
    ll a, b;

    for(int i = 0 ; i < N ; i++){
        c[i][0] = 1LL;
        c[i][i] = 1LL;
        
        for(int j = 1 ; j < i ; j++){
            c[i][j] = c[i][j - 1] + c[i - 1][j - 1];

            assert(c[i][j] > 0LL);
        }
    }

    scanf("%d %d", &n, &k);

    for(int i = 0 ; i < n ; i++){
        scanf("%lld", &box[i]);
    }

    scanf("%lld %lld", &a, &b);    

    vector< ll > fbox;

    for(int i = 0 ; i < n ; i++){
        if(box[i] < b){
            fbox.push_back(box[i]);
        }
    }

    sort(fbox.begin(), fbox.end());

    if(k == 1){
        int tot = 0;

        for(int i = 0 ; i < n ; i++){
            if(fbox[i] >= a && fbox[i] <= b){
                tot++;
            }
        }

        printf("%d\n", tot);
        return 0;
    }

    ll ans = 0LL;

    if(a * 2LL > b){
        for(int i = 0 ; i < n ; i++){
            if(fbox[i] >= a && fbox[i] <= b){
                int last = 0;

                for(int j = 0 ; j < i ; j++){
                    if(fbox[i] + fbox[j] > b){
                        break;
                    }

                    last++;
                }

                ans += c[last][k - 1];
            }
        }
    }else{
        vector< ll > s0, s1, s2, s3;

        for(int i = 0 ; i < n ; i++){
            if(fbox[i] <= a / 2LL){
                s0.push_back(fbox[i]);
            }else if(fbox[i] > a / 2LL && fbox[i] < a){
                s1.push_back(fbox[i]);
            }else if(fbox[i] >= a && fbox[i] <= b / 2LL){
                s2.push_back(fbox[i]);
            }else{
                s3.push_back(fbox[i]);
            }
        }

        for(auto d: s1){
            int e = 0;

            for(auto v: fbox){
                if(v >= d){
                    break;
                }

                if(v + d >= a){
                    ans += c[e][k - 2];
                    printf("add %lld\n", c[e][k - 2]);
                }

                e++;
            }
        }

        for(int i = 0 ; i < s2.size() ; i++){
            int tot = s0.size() + s1.size() + i;

            ans += c[tot][k - 1];
            printf("%lld %d\n",c[tot][k - 1], tot );
        }

        for(int i = 0 ; i < s3.size() ; i++){
            auto u = s3[i];

            int last = 0;
            for(auto v: fbox){
                if(u + v > b){
                    break;
                }

                last++;
            }

            ans += c[last][k - 1];
        }
    }

    printf("%lld\n", ans);

    return 0;
}