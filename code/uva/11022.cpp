//07, 08, 2018, 11:00:33 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

string s;
const int N = 100;
int b[N];
int dp[N][N];
int used[N][N];
int test = 1;

void KMP_preprocess(string &s){
    int i = 0, j = -1;
    b[0] = -1;
    int m = s.length();

    while(i < m){
        while(j >= 0 && s[i] != s[j]){
            j = b[j];
        }

        j++, i++;

        b[i] = j;
    }
}

int KMP_search(string &s, string &f){
    int i = 0, j = 0;
    int r = -1;

    int n = f.length();
    int m = s.length();

    while(i < n){
        while(j >= 0 && s[j] != f[i]){
            j = b[j];
        }

        j++, i++;

        if(j == m){
            if(r != -1){
                return i - j - r;
            }

            r = i - j;
            j = b[j];
        }
    }

}

int solve(int i, int j){
    if(i == j){
        return 1;
    }

    int &ans = dp[i][j];

    if(used[i][j] == test){
        return ans;
    }

    used[i][j] = test;
    ans = 1e9;

    int len = j - i + 1;

    string tmp = s.substr(i, len);
    string f = tmp + tmp;

    KMP_preprocess(tmp);

    int sz = KMP_search(tmp, f);
    
    if(sz != len){
        ans = solve(i, i + sz - 1);
    }
    
    for(int k = i ; k < j ; k++){
        ans = min(ans, solve(i, k) + solve(k + 1, j));
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin >> s){
        if(s == "*")
            break;

        int n = s.length();

        cout << solve(0, n - 1) << endl;
        test++;
    }    

    return 0;
}