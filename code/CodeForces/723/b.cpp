#include <bits/stdc++.h>

using namespace std;

int numb[8] = {11, 111, 1111, 11111, 111111, 1111111, 11111111, 111111111};
map< pair< int, int >, bool > mp;

bool solve(int num, int p){
    if(mp.count({num, p})){
        return mp[{num, p}];
    }

    if(p == 0){
        return (num % numb[p]) == 0;
    }

    if(solve(num, p - 1)){
        return mp[{num, p}] = true;
    }


    int nnum = num;

    while(nnum >= numb[p]){
        nnum -= numb[p];

        if(solve(nnum, p - 1)){
            return mp[{num, p}] = true;
        }
    }

    return mp[{num, p}] = false;
}

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int x;

        scanf("%d", &x);

        if(solve(x, 7)){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }

    return 0;
}