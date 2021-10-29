#include <bits/stdc++.h>

using namespace std;

int ans[3];
int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n, m;

        scanf("%d %d", &n, &m);
    
        bool frag = false;

        memset(ans, 0, sizeof ans);

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                char cij;

                scanf("\n%c", &cij);

                if(cij == '.') continue;

                if(ans[(i + j) & 1] && ans[(i + j) & 1] != cij){
                    assert(ans[(i + j) & 1] == 'W' || ans[(i + j) & 1] == 'R');
                    frag = true;
                }else{
                    ans[(i + j) & 1] = cij;
                }
            }
        }

        if(!ans[0] && !ans[1]){
            ans[0] = 'R';
            ans[1] = 'W';
        }else if(!ans[0] && ans[1]){
            ans[0] = (ans[1] == 'W') ? 'R' : 'W';
        }else if(!ans[1] && ans[0]){
            ans[1] = (ans[0] == 'W') ? 'R' : 'W';
        }
    
        frag |= (ans[0] == ans[1]);

        if(frag){
            printf("NO\n");
        }else{
            assert(ans[0] && ans[1]);
            printf("YES\n");

            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < m ; j++){
                    printf("%c", ans[(i + j) & 1]);
                }
                printf("\n");
            } 
        }
    }

    return 0;
}