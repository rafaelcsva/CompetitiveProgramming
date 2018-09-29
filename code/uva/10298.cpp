//27, 07, 2018, 09:59:52 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

const int N = 2e6 + 10;
string s;
string t;
int b[N];
int m;
int f = -1;

void KMP_preprocess(){
    int i = 0, j = -1;
    b[0] = -1;

    while(i < m){
        while(j >= 0 && s[i] != s[j]){
            j = b[j];
        }

        j++, i++;
        b[i] = j;
    }
}

int KMP_search(){
    int i = 0, j = 0;
    int n = 2 * m;

    while(i < n){
        while(j >= 0 && s[j] != t[i]){
            j = b[j];
        }

        j++, i++;

        if(j == m){
            int pos = i - j;

            if(f != -1){
                return pos - f;
            }

            j = b[j];
            f = pos;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    while(cin >> s){
        if(s == "."){
            break;
        }

        t = s + s;

        m = s.length();

        KMP_preprocess();

        cout << m / KMP_search() << endl;
        
        f = -1;
    }

    return 0;
}