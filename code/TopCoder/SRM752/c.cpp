//06, 03, 2019, 09:30:46 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< string, bool >    psi;

const int N = 2010;
int dp[N][20];
int n;
string s;

psi solve(int digit, int last){
    // cout << digit << " " << last << endl;
    if(digit == n + 1){
        return {"", true};
    }

    int &ans = dp[digit][last];

    if(ans != -1){
        return {"", ans};
    }

    ans = 0;

    for(int d = (digit == 0) ; d <= 9 ; d++){
        if(digit == 0){
            psi r = solve(digit + 1, d);

            if(r.second){
                r.first.push_back(char(d + '0'));
                ans = 1;
                return {r.first, ans};
            }
        }else{
            psi r = {"", false};

            if(s[digit - 1] == '<' && d > last){
                r = solve(digit + 1, d);
            }else if(s[digit - 1] == '>' && d < last){
                r = solve(digit + 1, d);
            }else if(s[digit - 1] == '=' && d == last){
                r = solve(digit + 1, d);
            }else if(s[digit - 1] == '!' && d != last){
                r = solve(digit + 1, d);
            }

            if(r.second){
                r.first.push_back(char(d + '0'));
                ans = 1;
                return {r.first, ans};
            }
        }
    }

    return {"", ans};
}

class ReconstructNumber{
    public:

    string smallest(string comparisons){
        memset(dp, -1, sizeof dp);

        s = comparisons;
        n = comparisons.length();

        psi r = solve(0, 0);

        if(!r.second){
            return "";
        }

        reverse(r.first.begin(), r.first.end());

        return r.first;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ReconstructNumber test;

    cout << test.smallest(">=!<") << endl;
    
    return 0;
}