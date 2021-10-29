#include <bits/stdc++.h>

using namespace std;

typedef pair< int, int >    pii;
set< pii > con[2];

int main(){
    int n;

    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            con[(i + j) & 1].insert({i, j});
        }
    }

    int a;

    while(con[0].size() + con[1].size() != 0){
        scanf("%d", &a);
    
        if(a == 1){
            if(con[1].size() == 0){
                auto u = con[0].begin();

                printf("3 %d %d\n", u->first + 1, u->second + 1);
                con[0].erase(u);
            }else{
                auto u = con[1].begin();

                printf("2 %d %d\n", u->first + 1, u->second + 1);
                con[1].erase(u);
            }
        }else if(a == 2){
            if(con[0].size() == 0){
                auto u = con[1].begin();

                printf("3 %d %d\n", u->first + 1, u->second + 1);
                con[1].erase(u);
            }else{
                auto u = con[0].begin();

                printf("1 %d %d\n", u->first + 1, u->second + 1);
                con[0].erase(u);
            }
        }else{
            if(con[0].size() == 0){
                auto u = con[1].begin();

                printf("2 %d %d\n", u->first + 1, u->second + 1);
                con[1].erase(u);
            }else{
                auto u = con[0].begin();

                printf("1 %d %d\n", u->first + 1, u->second + 1);
                con[0].erase(u);
            }
        }

        fflush(stdout);
    }

    return 0;
}