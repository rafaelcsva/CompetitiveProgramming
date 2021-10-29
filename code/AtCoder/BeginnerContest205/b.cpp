#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;

    scanf("%d", &n);
    vector< int > v;

    for(int i = 0 ; i < n ; i++){
        int ai;
        scanf("%d", &ai);
        v.push_back(ai);
    }

    sort(v.begin(), v.end());

    for(int i = 0 ; i < n ; i++){
        if(v[i] != i + 1){
            printf("No\n");
            return 0;
        }
    }

    printf("Yes\n");

    return 0;
}