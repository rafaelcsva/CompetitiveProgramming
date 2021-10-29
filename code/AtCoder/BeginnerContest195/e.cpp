#include <bits/stdc++.h>

using namespace std;

const int N = int(2e5) + 10;
int dp[N][10];
string st, x;
int n;

int solve(int i, int s){
    int &ans = dp[i][s];

    if(ans){
        return ans;
    }

    if(i == n){
        // printf("%d\n", s);
        return (s % 7 == 0) ? 'T' : 'A'; 
    }

    if(x[i] == 'A'){
        // printf("%d \n", (s * 10) % 7);
        if(solve(i + 1, (s * 10) % 7) == 'A'){
            return ans = 'A';
        }else if(solve(i + 1, (s * 10 + st[i] - '0') % 7) == 'A'){
            return ans = 'A';
        }

        return ans = 'T';
    }else{
       if(solve(i + 1, (s * 10) % 7) == 'T'){
            return ans = 'T';
        }else if(solve(i + 1, (s * 10 + st[i] - '0') % 7) == 'T'){
            return ans = 'T';
        }

        return ans = 'A'; 
    }
}

int main(){
    cin >> n;
    cin >> st;
    cin >> x;

    int c = solve(0, 0);

    if(c == 'A'){
        cout << "Aoki\n";
    }else{
        cout << "Takahashi\n";
    }

    return 0;
}