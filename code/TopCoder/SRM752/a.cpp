//06, 03, 2019, 09:02:18 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

class PokerRound{
    public:
    int amount(int T){
        const int B = int(1e4);
        for(int x = 0 ; x <= B ; x++){
            int y = B - x;

            y -= x;
            x = x + x;
            y -= x;
            x = x + x;
            y -= x;

            if(y == T){
                return B - x;
            }
        }

        return -1;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}