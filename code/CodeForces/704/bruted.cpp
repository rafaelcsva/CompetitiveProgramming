#include <bits/stdc++.h>

using namespace std;

vector< int > v1, v2;

int get_num(vector< int > &v){
    int b = 1;
    int sum = 0;

    for(int i = int(v.size()) - 1 ; i >= 0 ; i--){
        if(v[i]){
            sum += b;
        }

        b <<= 1;
    }

    return sum;
}

void print(vector< int > &v){
    for(auto u: v){
        printf("%d ", u);
    }

    printf("\n");
}

int main(){
    int a, b;

    scanf("%d %d", &a, &b);

    for(int i = 0 ; i < a ; i++){
        v1.push_back(0);
        v2.push_back(0);
    }
    for(int i = 0 ; i < b ; i++){
        v1.push_back(1);
        v2.push_back(1);
    }

    int ans = 0;

    do{
        int num1 = get_num(v1);

        do{
            int num2 = get_num(v2);

            if(num2 < num1){
                ans = max(ans, __builtin_popcount(num1 - num2));
            }
        }while(next_permutation(v2.begin(), v2.end()));

        sort(v2.begin(), v2.end());
    }while(next_permutation(v1.begin(), v1.end()));

    sort(v1.begin(), v1.end());

    printf("max: %d\n", ans);
    do{
        int num1 = get_num(v1);

        do{
            int num2 = get_num(v2);

            if(num2 < num1){
                if(__builtin_popcount(num1 - num2) == ans){
                    print(v1);
                    print(v2);
                    printf("\n");
                }
            }
        }while(next_permutation(v2.begin(), v2.end()));

        sort(v2.begin(), v2.end());
    }while(next_permutation(v1.begin(), v1.end()));

    return 0;
}