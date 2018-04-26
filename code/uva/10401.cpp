#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;
const int N = int(1000);
ll dp[N][N];
int used[N][N];
string s;
int test = 1;
map<char, int>mp;

ll solve(int c, int last){
    ll &ans = dp[c][last];

    if(used[c][last] == test){
        return ans;
    }
    if(c == s.length() + 1){
        return 1LL;
    }

    ans = 0LL;
    used[c][last] = test;

    if(s[c - 1] != '?'){
        int row = mp[s[c - 1]];
       // cout << "row = " << s[c - 1] << endl;
        if(abs(row - last) <= 1 && last != 0){
            return 0LL;
        }
        
        ans = solve(c + 1, row);

    }else{
        for(int row = 1 ; row <= s.length() ; row++){
            if(abs(row - last) > 1 || last == 0){
                ans += solve(c + 1, row);
            }
        }
    }

    return ans;
}

int main (){
    char v[] = {'A', 'B', 'C', 'D', 'E', 'F'};

    for(int i = 1 ; i <= 9; i++){
        mp[char(i + '0')] = i;
    }

    for(int i = 10 ; i <= 15 ; i++){
        mp[v[i - 10]] = i;
    }

    while(cin >> s){
        cout << solve(1, 0) << endl;

        test++;
    }    

    return 0;
}