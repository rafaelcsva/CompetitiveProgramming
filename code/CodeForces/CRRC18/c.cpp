#include <bits/stdc++.h>

using namespace std;

typedef vector< string >    vs;
typedef pair< vs, vs >  pvv;

const int N = 1010;
int cl[N];
string s;

pvv multiply(pvv a, pvv b){
    map< string, int > mp;

    for(auto u: a.first){
        mp[u]++;
        // cout << "add " << u << endl;
    }

    for(auto u: a.second){
        mp[u]--;
        // cout << "rem " << u << endl;
    }

    for(auto u: b.first){
        mp[u]++;
        // cout << "add " << u << endl;
    }

    for(auto u: b.second){
        mp[u]--;
        // cout << "rem " << u << endl;
    }

    pvv ans;

    for(auto e: mp){
        // cout << "r: " << e.first << " " << e.second << endl;
        if(e.second < 0){
            for(int i = 0 ; i < abs(e.second) ; i++){
                ans.second.push_back(e.first);
            }
        }else{
            for(int i = 0 ; i < abs(e.second) ; i++){
                ans.first.push_back(e.first);
            }
        }
    }
    // cout << "ret " << ans.first.size() << " " << ans.second.size() << "\n";

    return ans;
}

pvv divide(pvv a, pvv b){
    swap(b.first, b.second);

    return multiply(a, b);
}

pvv solve(int i, int j){
    if(s[i] == '(' && cl[i] == j){
        return solve(i + 1, j - 1);
    }

    int k = i;
    int div = -1;
    int mult = -1;

    while(k <= j){
        if(s[k] == '('){
            k = cl[k] + 1;
            continue;
        }

        if(s[k] == '*'){
            mult = k;
        }else if(s[k] == '/'){
            div = k;
        }

        k++;
    }
    // cout << mult << " and " << div << "\n";

    if(mult != -1){
        auto lf = solve(i, mult - 1);
        auto rg = solve(mult + 1, j);

        return multiply(lf, rg);
    }else if(div != -1){
        auto lf = solve(i, div - 1);
        auto rg = solve(div + 1, j);

        return divide(lf, rg);
    }

    pvv ans;

    ans.first.push_back(s.substr(i, j - i + 1));
    
    return ans;
}

bool mycompar(string a, string b){
    int n = a.length();
    int m = b.length();
    for(int i = 0 ; i < min(n, m) ; i++){
        char ai = a[i] | 32;
        char bi = b[i] | 32;

        if(ai != bi){
            return ai < bi;
        }else{
            if(a[i] > b[i]){
                return false;
            }else if(a[i] < b[i]){
                return true;
            }
        }
    }

    return n < m;
}

int main(){
    cin >> s;

    stack< int > st;

    for(int i = 0 ; i < s.length() ; i++){
        if(s[i] == '('){
            st.push(i);
        }else if(s[i] == ')'){
            cl[st.top()] = i;
            st.pop();
        }
    }

    auto u = solve(0, int(s.length()) - 1);

    bool frag = false;

    sort(u.first.begin(), u.first.end(), mycompar);
    sort(u.second.begin(), u.second.end(), mycompar);

    if(u.first.size() == 0){
        cout << "1\n";
    }else{
        for(auto e: u.first){
            if(frag){
                cout << "*";
            }

            cout << e;

            frag = true;
        }

        cout << "\n";
    }

    frag = false;

    if(u.second.size() == 0){
        cout << "1\n";
    }else{
        for(auto e: u.second){
            if(frag){
                cout << "*";
            }
            cout << e;

            frag = true;
        }

        cout << "\n";
    }

    return 0;
}