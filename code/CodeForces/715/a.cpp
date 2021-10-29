#include <bits/stdc++.h>

using namespace std;

string s[3];

string merge(string &a, string &b){
    int cnt[2][2];
    cnt[0][0] = cnt[0][1] = cnt[1][0] = cnt[1][1] = 0;

    for(int i = 0 ; i < a.length() ; i++){
        cnt[0][a[i] - '0']++;
        cnt[1][b[i] - '0']++;
    }

    int n = a.length() / 2;

    if(cnt[0][0] >= n && cnt[1][0] >= n){
        string t = "";

        int mx = max(cnt[0][0], cnt[1][0]);

        for(int i = 0 ; i < mx ; i++){
            t.push_back('0');
        }
        // cout << "t = " << t << " " << a << " " << b << endl;

        string ts = "";
        int i = 0;
        int j = 0;

        while(i < a.length()){
            while(i < a.length() && a[i] == '1' && (t.length() <= j || t[j] != '1')){
                // cout << i << " " << a[i] << endl;
                ts.push_back('1');
                i++;
            }

            if(j < t.length()){
                ts.push_back(t[j]);
                if(i < a.length() && t[j] == a[i]){
                    i++;
                }
                j++;
            }
        }

        for(int i = j ; i < t.length() ; i++){
            ts.push_back(t[i]);
        }

        t = ts;
        // cout << "sai com " << t << endl;
        ts = "";

        i = 0;
        j = 0;

        while(i < b.length()){
            while(i < b.length() && b[i] == '1' && (t.length() <= j || t[j] != '1')){
                // cout << b[i] << " " << i << endl;
                ts.push_back('1');
                i++;
            }
            if(j < t.length()){
                ts.push_back(t[j]);
                if(i < b.length() && t[j] == b[i]){
                    i++;
                }
                j++;
            }
        }

        for(int i = j ; i < t.length() ; i++){
            ts.push_back(t[i]);
        }

        return ts;
    }else if(cnt[0][1] >= n && cnt[1][1] >= n){
        string t = "";

        int mx = max(cnt[0][1], cnt[1][1]);

        for(int i = 0 ; i < mx ; i++){
            t.push_back('1');
        }
        // cout << "t = " << t << " " << a << " " << b << endl;

        string ts = "";
        int i = 0;
        int j = 0;

        while(i < a.length()){
            while(i < a.length() && a[i] == '0' && (t.length() <= j || t[j] != '0')){
                // cout << i << " " << a[i] << endl;
                ts.push_back('0');
                i++;
            }

            if(j < t.length()){
                ts.push_back(t[j]);
                if(i < a.length() && t[j] == a[i]){
                    i++;
                }
                j++;
            }
        }

        for(int i = j ; i < t.length() ; i++){
            ts.push_back(t[i]);
        }

        t = ts;
        // cout << "sai com " << t << endl;
        ts = "";

        i = 0;
        j = 0;

        while(i < b.length()){
            while(i < b.length() && b[i] == '0' && (t.length() <= j || t[j] != '0')){
                // cout << b[i] << " " << i << endl;
                ts.push_back('0');
                i++;
            }
            if(j < t.length()){
                ts.push_back(t[j]);
                if(i < b.length() && t[j] == b[i]){
                    i++;
                }
                j++;
            }
        }

        for(int i = j ; i < t.length() ; i++){
            ts.push_back(t[i]);
        }

        return ts;
    }

    return "-1";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while(t--){
        int n;

        cin >> n;
    
        for(int i = 0 ; i < 3 ; i++) cin >> s[i];

        string ans ="-1";

        for(int i = 0 ; i < 3 ; i++){
            for(int j = i + 1 ; j < 3 ; j++){
                auto u = merge(s[i], s[j]);

                if(u.length() <= 3 * n && u != "-1"){
                    ans = u;
                    break;
                }
            }

            if(ans != "-1"){
                break;
            }
        }

        cout << ans << endl;
    }

    return 0;
}