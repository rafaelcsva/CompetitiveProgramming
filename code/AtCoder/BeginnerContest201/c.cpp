#include <bits/stdc++.h>

using namespace std;

string s;

int solve(int msk, int d){
    if(d == 4){
        return (msk == 0);
    }

    int ans = 0;

    for(int i = 0 ; i < 10 ; i++){
        int e = 1 << i;

        if(s[i] == 'o' || s[i] == '?'){
            if((msk & e)){
                ans += solve(msk ^ e, d + 1);
            }else{
                ans += solve(msk, d + 1);
            }
        }
    }

    return ans;
}

int main(){
    cin >> s;

    int msk = 0;

    for(int i = 0 ; i < s.length() ; i++){
        if(s[i] == 'o'){
            msk |= (1 << i);
        }
    }

    printf("%d\n", solve(msk, 0));

    return 0;  
}