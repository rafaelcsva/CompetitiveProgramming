#include <bits/stdc++.h>
 
using namespace std;
 
const int N = int(1e3) + 10;
int x[N];
 
void change(char &c){
    c = (c == '0') ? '1' : '0';
}
 
string gen(int st, string &s){
    string t = "";
 
    // t.push_back('0' + st);
 
    for(int i = 0 ; i < s.length() ; i++){
        int d = s[i] - '0';
        // printf("d: %d %d\n", d, x[i]);
        d = (d + x[i] + st) & 1;
 
        t.push_back(d + '0'); 
    }
 
    return t;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

string gen(int n){
    string t;

    for(int i = 0 ; i < n ; i++){
        t.push_back('0' + (rng() & 1));
    }

    return t;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n;
 
    cin >> n;
 
    string s;
 
    int lt = n - 1;
 
    while(true){
        s = gen(n);

        cout << s << endl;
 
        int x;
 
        cin >> x;
 
        if(x == n){
            return 0;
        }
        if(x == n / 2){
            break;
        }
    }
 
    for(int j = n - 1 ; j >= 1 ; j--){
        change(s[j]);
        change(s[0]);
 
        cout << s << endl;
 
        int ans;
 
        cin >> ans;
 
        if(ans == n){
            return 0;
        }
 
        if(ans == n / 2){
            x[j] = 1;
        }
 
        change(s[j]);
        change(s[0]);
    }
 
    string s1 = gen(0, s);
 
    cout << s1 << endl;
 
    int ans;
    cin >> ans;
 
    if(ans == n) return 0;
 
    string s2 = gen(1, s);
 
    cout << s2 << endl;
    cin >> ans;
 
    if(ans == n) return 0;
 
    return 0;
}