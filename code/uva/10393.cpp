//25, 07, 2018, 14:07:10 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

const int N = 300;
char mark[N], finger[N];

bool compar(string &s, string &d){
    return s.length() < d.length();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    mark['q'] = 1;
    mark['a'] = 1;
    mark['z'] = 1;

    mark['w'] = 2;
    mark['s'] = 2;
    mark['x'] = 2;

    mark['e'] = 3;
    mark['d'] = 3;
    mark['c'] = 3;

    mark['r'] = 4;
    mark['f'] = 4;
    mark['v'] = 4;
    mark['t'] = 4;
    mark['g'] = 4;
    mark['b'] = 4;

    mark['y'] = 7;
    mark['h'] = 7;
    mark['n'] = 7;
    mark['u'] = 7;
    mark['j'] = 7;
    mark['m'] = 7;

    mark['i'] = 8;
    mark['k'] = 8;
    mark[','] = 8;

    mark['o'] = 9;
    mark['l'] = 9;
    mark['.'] = 9;

    mark['p'] = 10;
    mark[';'] = 10;
    mark['/'] = 10;
    
    int f, n;

    int test = 1;

    while(cin >> f >> n){
        for(int i = 0 ; i < f;  i++){
            int fing;

            cin >> fing;

            finger[fing] = test;
        }

        vector<string>long_word;

        for(int i = 0 ; i < n ; i++){
            string s;

            cin >> s;
            
            bool ok = true;

            for(int j = 0 ; j < s.length() ; j++){
                char c = s[j];

                if(c == ' ' && (finger[5] == test || finger[6] == test)){
                    ok = false;
                    break;
                }
                if(finger[mark[c]] == test){
                    ok = false;
                    break;
                }
            }

            if(ok){
                bool can_insert = true;

                for(int i = 0 ; i < long_word.size() ; i++){
                    if(long_word[i] == s){
                        can_insert = false;
                        break;
                    }
                }

                if(can_insert)
                    long_word.push_back(s);
            }
        }

        sort(long_word.begin(), long_word.end(), compar);

        vector<string>bests;

        int i = long_word.size() - 1;
        int j = i;

        while(j >= 0 && long_word[i].length() == long_word[j].length()){
            bests.push_back(long_word[j]);
            j--;
        }

        sort(bests.begin(), bests.end());

        cout << bests.size() << endl;
        
        for(int i = 0 ; i < bests.size() ; i++){
            cout << bests[i] << endl;
        }

        test++;
    }

    return 0;
}