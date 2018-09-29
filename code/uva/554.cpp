//17, 07, 2018, 09:19:48 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

const int mod = 27;
map<string, bool>have_word;
const int LINE_MAX_SIZE = 60;

int MOD(int v){
    return ((v % mod) + mod) % mod;
}

int get_number(char c){
    if(c == ' '){
        return 0;
    }

    return c - 'A' + 1;
}

char get_char(int d){
    if(d == 0){
        return ' ';
    }

    return char('A' + d - 1);
}

int count_words(string s){
    int cnt = 0;

    string word = "";

    for(int i = 0 ; i < s.length() ; i++){
        if(s[i] == ' '){
            if(have_word[word]){
                cnt++;
            }

            word = "";
        }else{
            word += s[i];
        }
    }

    return cnt;
}

vector<string> break_in_words(string &best){
    vector<string>words;

    string word = "";

    for(int i = 0 ; i < best.length() ; i++){
        if(best[i] == ' '){
            if(word.length())
                words.push_back(word);

            word = "";
        }else{
            word += best[i];
        }
    }

    return words;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;

    while(true){
        cin >> s;

        if(s == "#"){
            break;
        }

        have_word[s] = true;
    }

    cin.ignore();

    getline(cin, s);

    string best = s;
    int ans = 0;

    for(int k = 0 ; k < mod ; k++){
        string tmp = "";

        for(int i = 0 ; i < s.length() ; i++){
            int d = get_number(s[i]);

            tmp += get_char(MOD(d - k));
        }

        int f = count_words(tmp);

        if(f > ans){
            best = tmp;
            ans = f;
        }
    }

    vector<string>words = break_in_words(best);

    int line_size = 0;
    int space_bar = 0;

    for(int i = 0 ; i < words.size() ; i++){
        if(words[i].length() + space_bar + line_size > LINE_MAX_SIZE){
            cout << endl;
            space_bar = 0;
            line_size = 0;
        }    

        if(space_bar){
            cout << ' ';
        }

        cout << words[i];
        line_size += words[i].length() + space_bar;
        space_bar = 1;
    }

    cout << endl;

    return 0;
}