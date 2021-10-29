#include <bits/stdc++.h>

using namespace std;

const int N = 52;
vector< int > stacks[N];

int main(){
    int n;

    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++){
        int hi;

        scanf("%d", &hi);

        for(int j = 0 ; j < hi ; j++){
            int xi;

            scanf("%d", &xi);

            if(stacks[i].size() == 0 || stacks[i][int(stacks[i].size()) - 1] != xi){
                stacks[i].push_back(xi);
            }
        }
    }

    return 0;
}