#include <bits/stdc++.h>

using namespace std;

int main(){
    int a, b;

    scanf("%d %d", &a, &b);

    vector< int > ca, cb;

    if(a > b){
        int sum = 0;

        for(int i = 1 ; i <= a ; i++){
            ca.push_back(i);
            sum += i;
        }

        int sumb = 0;

        for(int i = 1 ; i < b ; i++){
            sumb += i;
            cb.push_back(i);
        }

        cb.push_back(sum - sumb);
    }else{
        int sum = 0;

        for(int i = 1 ; i <= b ; i++){
            cb.push_back(i);
            sum += i;
        }

        int sumb = 0;
        // printf("%d\n", sum);

        for(int i = 1 ; i < a ; i++){
            sumb += i;
            ca.push_back(i);
        }

        ca.push_back(sum - sumb);
    }

    for(auto u: ca){
        printf("%d ", u);
    }
    for(auto u: cb){
        printf("-%d ", u);
    }
    printf("\n");

    return 0;
}