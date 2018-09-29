//17, 07, 2018, 16:12:04 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

const int N = 5, L = 30;
char key_table[N][N];
int mark[L];
pii location[L];
char tab[N][N];

void extract(string s, int now){
    int t = 0;
    
    for(int i = 0 ; i < s.length() ; i++){
        if(mark[s[i] - 'a'] != now && s[i] != ' '){
            mark[s[i] - 'a'] = now;
            location[s[i] - 'a'] = {t / N, t % N};
            tab[t / N][t % N] = s[i];
            t++;
        }
    }

    for(char c = 'a' ; c <= 'z' ; c++){
        if(c == 'q'){
            continue;
        }
        
        if(mark[c - 'a'] != now){
            location[c - 'a'] = {t / N, t % N};
            tab[t / N][t % N] = c;
            t++;
        }
    }
}

char next(int p, string &s){
    if(p == s.length() - 1){
        return s[p];
    }

    return s[p + 1];
}

char right(int i, int j){
    if(j == N - 1){
        return tab[i][0];
    }

    return tab[i][j + 1];
}

char down(int i, int j){
    if(i == N - 1){
        return tab[0][j];
    }

    return tab[i + 1][j];
}

string trim(string s){
    string r = "";
    for(int i = 0 ; i < s.length() ; i++){
        if(s[i] != ' '){
            r += s[i];
        }
    }

    return r;
}

void print_key_table(){
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cout << tab[i][j];
        }

        cout << endl;
    }
    
}

void encript(int i, char c, string &s){
    if(location[c - 'a'].first == location[s[i] - 'a'].first){
        char d = right(location[s[i] - 'a'].first, location[s[i] - 'a'].second);
        char e = right(location[c - 'a'].first, location[c - 'a'].second);
        
        cout << char(d ^ 32);
        cout << char(e ^ 32);
    }else if(location[c - 'a'].second == location[s[i] - 'a'].second){
        char d = down(location[s[i] - 'a'].first, location[s[i] - 'a'].second);
        char e = down(location[c - 'a'].first, location[c - 'a'].second);

        cout << char(d ^ 32);
        cout << char(e ^ 32);
    }else{
        char d = tab[location[s[i] - 'a'].first][location[c - 'a'].second];
        char e = tab[location[c - 'a'].first][location[s[i] - 'a'].second];
        
        
        cout << char(d ^ 32);
        cout << char(e ^ 32);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    cin >> t;

    cin.ignore();

    for(int test = 1 ; test <= t ;test++){
        string s;

        getline(cin, s);
        extract(s, test);
        // print_key_table();

        getline(cin, s);
        
        s = trim(s);

        int i = 0;
        string build = "";

        while(i < s.length()){
            char c = next(i, s);

            if(c == s[i]){
                encript(i, 'x', s);
                i++;
            }else{
                encript(i, c, s);
                i += 2;
            }
        }
        
        cout << endl;
    }

    return 0;
}