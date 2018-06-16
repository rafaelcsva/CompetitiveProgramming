//24, 05, 2018, 10:19:37 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

const int MOD = 60 * 24;

bool isPalindrome(int x){
    int h = x / 60;
    int m = x % 60;

    if(h == (m % 10) * 10 + m / 10){
        return true;
    }

    return false;
}

int main(){
    int h, m;

    scanf("%d:%d", &h, &m);

    int at = h * 60 + m;
    int mn = 0;
    
    while(!isPalindrome(at)){
        at++;
        mn++;
        at %= MOD;
    }   

    cout << mn << endl;

    return 0;
}