//30, 10, 2018, 22:01:35 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

class DigitStringDiv2{
    public:
        int count(string S, int X){
            int n = S.length();
            int cnt = 0;

            for(int i = 0 ; i < n ; i++){
                if(S[i] == '0'){
                    continue;
                }

                int num = 0;

                for(int j = i ; j < n ; j++){
                    num = num * 10 + (S[j] - '0');

                    if(num > X){
                        cnt++;
                    }
                }
            }

            return cnt;
        }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}