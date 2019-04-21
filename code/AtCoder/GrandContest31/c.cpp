//16, 03, 2019, 09:51:50 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(3e5);
bool choosed[N];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vector< int > resp;
int a, b, n;
const int B = 100, T = 30;

bool can(int number, int rest){
    choosed[number] = true;

    if(rest == 0){
        if(__builtin_popcount(number ^ b) == 1){
            resp.push_back(number);
            return true;
        }else{
            choosed[number] = false;
            return false;
        }
    }

    int tent = 0;
    int tmp = number;
    int find = -1;

    for(int i = 0 ; i < n ; i++){
        if(!choosed[number ^ (1 << i)]){
            find = i;
            break;
        }
    }

    if(find == -1){
        choosed[number] = false;
        return false;
    }

    while(choosed[tmp] && tent <= T){
        // cout << tmp << endl;
        int choosed_bit = rng() % n;
        tmp = number ^ (1 << choosed_bit);
        tent++;
    }
    
    if(!choosed[tmp]){
        // cout << tmp << endl;
        if(can(tmp, rest - 1)){
            resp.push_back(number);
            return true;
        }
    }else{
        tmp = number ^ (1 << find);

        if(can(tmp, rest - 1)){
            resp.push_back(number);
            return true;
        }
    }

    choosed[number] = false;

    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> a >> b;

    choosed[a] = choosed[b] = true;

    if(n == 1){
        cout << a << " " << b << endl;
        return 0;
    }else{
        bool ok  = false;

        for(int tested = 0 ; tested < B ; tested++){
            int choosed_bit = rng() % n;

            if(!choosed[a ^ (1 << choosed_bit)]){
                // cout << "tentando com " << (a ^ (1 << choosed_bit)) << endl;
                if(can(a ^ (1 << choosed_bit), (1 << n) - 3)){
                    ok = true;
                    break;
                }
            }
        }

        if(!ok){
            cout << "NO" << endl;
            return 0;
        }else{
            cout << "YES" << endl;

            reverse(resp.begin(), resp.end());
            cout << a << ' ';
            for(int i = 0 ; i < resp.size() ; i++){
                cout << resp[i] << ' ';
            }
            cout << b << endl;
        }
    }   
    
    return 0;
}