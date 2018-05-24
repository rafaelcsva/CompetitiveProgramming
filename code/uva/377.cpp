//24, 05, 2018, 08:23:36 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
map<char, int>mp;
char pm[] = {'V', 'U', 'C', 'D'};

int to_base_4(int n){
    int pot = 1;
    int r = 0;

    while(n){
        r += (n % 4) * pot;

        pot *= 10;
        n /= 4;
    }

    return r;
}

int sum_base_4(int a, int b){
    int r = 0;
    
    int n1 = a + b % 10;

    if(n1 >= 4){
        int carry = n1 - 3;
        n1 -= 4;
        
        return (b / 10 + carry) * 10 + n1;
    }else{
        return a + b;
    }
}

string sum(string a, string b){
    int i, j;
    int carry = 0;
    string c = "";

    for(i = a.length() - 1, j = b.length() - 1 ; i >= 0 && j >= 0 ; i--, j--){
        int add = to_base_4(mp[a[i]] + mp[b[i]]);
        add = sum_base_4(carry, add);
        
        // cout << to_base_4(mp[a[i]] + mp[b[i]]) << ' ' << carry << ' ' << add << endl;
        
        c += pm[add % 10];
        carry = add / 10;
    }

    if(carry){
        int num = to_base_4(carry);
        c += pm[carry];
    }

    reverse(c.begin(), c.end());

    return c;
}

string adapter_8_digits(string a){
    if(a.length() == 8){
        return a;
    }

    string c = "";

    for(int i = 0 ; i < 8 - int(a.length()) ; i++){
        c += 'V';
    }

    c += a;

    return c;
}

string shift_left(string a){
    string b = a.substr(1, int(a.length()) - 1);
    b += 'V';

    return b;
}

string shift_right(string a){
    string b = "V" + a.substr(0, int(a.length()) - 1);

    return b;
}

int main(){
    int t;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    mp['V'] = 0;
    mp['U'] = 1;
    mp['C'] = 2;
    mp['D'] = 3;

    cout << "COWCULATIONS OUTPUT" << endl;
    
    cin >> t;
    
    while(t--){
        string a, b;

        cin >> a >> b;

        a = adapter_8_digits(a);
        b = adapter_8_digits(b);
        
        for(int i = 0 ; i < 3 ; i++){
            char c;

            cin >> c;

            if(c == 'A'){
                b = sum(a, b);
            }else if(c == 'L'){
                b = shift_left(b);
            }else if(c == 'R'){
                b = shift_right(b);
            }
            // cout << b << endl;
        }

        string c;

        // cout << b << endl;
        cin >> c;
        
        if(c == b){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }

    cout << "END OF OUTPUT" << endl;

    return 0;
}