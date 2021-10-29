#include <bits/stdc++.h>

using namespace std;

typedef pair< int, int >    pii;

const int N = int(4e5) + 10;
queue< int > cil[N];
int mark[N];

int main(){
    memset(mark, -1, sizeof mark);

    int n, m;

    scanf("%d %d", &n, &m);

    queue< pii > con;

    for(int i = 0 ; i < m ; i++){
        int ki;

        scanf("%d", &ki);

        for(int j = 0 ; j < ki ; j++){
            int ai;

            scanf("%d", &ai);

            if(j == 0){
                if(mark[ai] != -1){
                    con.push({mark[ai], i});
                }else{
                    mark[ai] = i;
                }
            }

            cil[i].push(ai);
        }
    }

    while(!con.empty()){
        auto u = con.front();
        // printf("%d, %d\n", u.first, u.second);
        con.pop();

        // printf("(%d) %d\n", cil[u.first].front(), u.first);

        while(cil[u.first].empty() || cil[u.second].empty());
        
        cil[u.first].pop();
        cil[u.second].pop();

        if(!cil[u.first].empty()){
            // printf("%d %d\n", cil[u.first].front(), )
            if(mark[cil[u.first].front()] != -1){
                con.push({mark[cil[u.first].front()], u.first});
            }else{
                mark[cil[u.first].front()] = u.first;
            }
        }

        if(!cil[u.second].empty()){
            if(mark[cil[u.second].front()] != -1){
                con.push({mark[cil[u.second].front()], u.second});
            }else{
                mark[cil[u.second].front()] = u.second;
            }
        }
    }

    bool frag = false;

    for(int i = 0 ; i < m ; i++){
        frag |= !cil[i].empty();
    }

    if(frag){
        printf("No\n");
    }else{
        printf("Yes\n");
    }

    return 0;
}
