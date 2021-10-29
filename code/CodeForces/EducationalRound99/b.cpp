#include <bits/stdc++.h>

using namespace std;

const int N = int(2e6) + 10;
int main(){
    vector< int > sums;

    int sum = 1;
    int k = 2;

    while(sum < N){
        sums.push_back(sum);
        sum += k;
        k++;
    }

    int t;

    scanf("%d", &t);

    while(t--){
        int s;

        scanf("%d", &s);

        int u = lower_bound(sums.begin(), sums.end(), s) - sums.begin();

        if(sums[u] == s || (sums[u] - s <= u + 1 && sums[u] - s > 1)){
            printf("%d\n", u + 1);
        }else{
            printf("%d\n", u + 2);
        }
    }
}