#include <bits/stdc++.h>

using namespace std;

typedef pair< int, int >    pii;

int main(){
    int n, m, k;

    scanf("%d %d %d", &n, &m, &k);

    for(int i = 0 ; i < k ; i++){
        int xi, yi;

        scanf("%d %d", &xi, &yi);
    }

    vector< pii > tg;

    for(int i = 0 ; i < k ; i++){
        int xi, yi;

        scanf("%d %d", &xi, &yi);
        tg.push_back({xi, yi});
    }

    sort(tg.begin(), tg.end());

    vector< char > comm;

    for(int i = 0 ; i < m - 1 ; i++){
        comm.push_back('L');
    }
    for(int i = 0 ; i < n - 1 ; i++){
        comm.push_back('U');
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m - 1 ; j++){
            if(i & 1){
                comm.push_back('L');
            }else{
                comm.push_back('R');
            }
        }
        comm.push_back('D');
    }

    printf("%lu\n", comm.size());

    for(auto u: comm){
        printf("%c", u);
    }
    printf("\n");

    return 0;
}