#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;

    scanf("%d", &t);

    for(int test = 1 ; test <= t ; test++){
        int n;

        cin >> n;

        string li = "";

        int ans = 0;

        for(int i = 1 ; i <= n ; i++){
            string si;

            cin >> si;

            if(i > 1 && si.length() <= li.length()){
                int is_greater = 0;

                for(int i = 0 ; i < si.length() ; i++){
                    if(si[i] > li[i]){
                        is_greater = 1;
                        break;
                    }else if(si[i] < li[i]){
                        is_greater = -1;
                        break;
                    }
                }

                int ver = -1;

                for(int i = int(si.length()) ; i < li.length() ; i++){
                    if(li[i] != '9'){
                        ver = i;
                    }
                }

                for(int i = int(si.length()) ; i < li.length() && !is_greater && ver != -1; i++){
                    if(i == ver){
                        si.push_back(li[i] + 1);
                        ans++;
                        is_greater = 1;
                    }else{
                        ans++;
                        si.push_back(li[i]);
                    }
                }

                while(si.length() != li.length()){
                    ans++;
                    si.push_back('0');
                }

                if(!is_greater || is_greater == -1){
                    ans++;
                    si.push_back('0');
                }
            }

            // cout << si << endl;
            li = si;
        }

        cout << "Case #" << test << ": " << ans << endl;
    }

    return 0;
}