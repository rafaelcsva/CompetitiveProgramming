//14, 05, 2018, 20:27:02 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

vector<ll>v;
const ll MX = ll(1e13);
map<ll, int>mp;
string suf[] = {"th", "st", "nd", "rd", "th", "th", "th", "th", "th", "th"};
    
string getSuf(int i){
    if(i >= 10 && i <= 20){
        return "th";
    }

    return suf[i % 10];
}

int main(){
    for(ll pt7 = 1LL, c7 = 0; c7 != 13 ; pt7 *= 7LL, c7++){
        if(pt7 > MX){
            break;
        }

        for(ll pt5 = 1LL, c5 = 0; c5 != 30 ; pt5 *= 5LL, c5++){
            if(pt7 * pt5 > MX){
                break;
            }

            for(ll pt3 = 1LL, c3 = 0; c3 != 30 ; pt3 *= 3LL, c3++){
                if(pt7 * pt5 * pt3 > MX){
                    break;
                }
                
                for(ll pt2 = 1LL, c2 = 0; c2 != 33 ; pt2 *= 2LL, c2++){
                    if(pt7 * pt5 *pt3 *pt2 > MX){
                        break;
                    }

                    if(mp[pt7 * pt5 *pt3 *pt2])
                        continue;

                    mp[pt7 * pt5 *pt3 *pt2] = 1;
                     
                    v.push_back(pt7 * pt5 * pt3 * pt2);
                }
            }
        }
    }

    sort(v.begin(), v.end());

    int n;

    while(cin >> n){
        if(n == 0){
            break;
        }
        
        cout << "The " << n << getSuf(n % 100) << " humble number is " << v[n - 1] << "." << endl;
    }

    return 0;
}