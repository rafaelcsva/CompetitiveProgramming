//24, 07, 2018, 21:56:16 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

const int N = 100100;
string dictionary[N];
map<string, string>convert;
map<string, int>have;
int SIZE_PLUS = 25;

int change_one_letter(string &s){
    string k = s;
    int n = s.length();
    int r = N;
    
    for(int i = 0 ; i < n ; i++){
        char c = k[i];
        
        for(char letter = 'a' ; letter <= 'z' ; letter++){
            k[i] = letter;

            if(have[k]){
                r = min(r, have[k]);
            }
        }

        k[i] = c;
    }

    return r;
}

int swap_adjacent_letter(string &s){
    string k = s;
    int r = N;

    for(int i = 1 ; i < s.length() ; i++){
        swap(k[i], k[i - 1]);
        if(have[k]){
            r = min(r, have[k]);
        }
        swap(k[i], k[i - 1]);
    }

    return r;
}

int plus_letter(string &s){
    string lf = "";
    string rg = s;
    int n = s.length();
    int r = N;
    int i = 0;

    while(i < n){
        int ti = i;
        string lf = s.substr(0, i + 1);
        
        while(i < n && s[i] == s[ti]){
            i++;
        }
        
        int sz = i - ti - 1;

        string rg = "";

        if(i != n){
            rg = s.substr(i, n - i);
        }

        for(int x = 0 ; x < sz ; x++){
            lf.push_back(s[ti]);

            string t = lf + rg;

            if(have[t]){
                r = min(r, have[t]);
            }
        }
    }

    return r;
}

int missing_letter(string &s){
    int n = s.length();
    int r = N;

    string lf = "", rg = s;

    for(int i = 0 ; i <= n ; i++){
        for(char letter = 'a' ; letter <= 'z' ; letter++){
            string nl = lf;
            
            for(int j = 0 ; j < SIZE_PLUS ; j++){
                string t = nl + rg;

                if(t.length() > SIZE_PLUS){
                    break;
                }
                if(have[t]){
                    r = min(r, have[t]);
                }
                
                nl.push_back(letter);
            }
        }
        
        if(i != n){
            rg.erase(rg.begin());
        }
        
        string t = lf + rg;

        if(have[t]){
            r = min(r, have[t]);
        }
        
        lf.push_back(s[i]);
        
    }

    return r;
}

int process(string &word){
    return min({change_one_letter(word), swap_adjacent_letter(word), missing_letter(word)});
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;

    cin >> n;

    for(int i = 0 ; i < n ; i++){
        cin >> dictionary[i];
        have[dictionary[i]] = i + 1;
    }

    int q;

    cin >> q;

    while(q--){
        string word;

        cin >> word;

        bool is_on_dictionary = false;

        for(int i = 0 ; i < n ; i++){
            if(word == dictionary[i]){
                is_on_dictionary = true;
                break;
            }
        }

        if(is_on_dictionary){
            cout << word << " is correct" << endl;
        }else{
            int r = process(word);

            if(r != N){
                cout << word << " is a misspelling of " << dictionary[r - 1] << endl;
            }else{
                cout << word << " is unknown" << endl;
            }
        }
    }
    
    return 0;
}