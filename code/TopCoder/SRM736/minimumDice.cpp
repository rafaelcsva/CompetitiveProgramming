//15, 08, 2018, 12:26:10 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 121;
int test = 1;
bool dp[N][30];
int used[N][30];

class Reroll{
    public:
        
        bool solve(int sum, int el){
            if(sum == 0){
                return el == 0;
            }

            if(sum < 0 || el <= 0){
                // cout << "entrei aqui" << endl;
                return false;
            }

            bool &ans = dp[sum][el];
            
            if(used[sum][el] == test){
                return ans;
            }

            used[sum][el] = test;
            
            for(int k = 1 ; k <= 6 ; k++){
                ans |= solve(sum - k, el - 1);
            }

            return ans;
        }

        bool check(int mid, vector< int > &v, vector< int > &dice, int target){
            for(int i = 0 ; i < v.size() ; i++){
                v[i] = 0;
            }

            for(int i = v.size() - 1, j = mid ; i >= 0 ; i--, j--){
                if(j){
                    v[i] = 1;
                }else{
                    break;
                }
            }

            do{
                int sum = 0;

                for(int i = 0 ; i < v.size() ; i++){
                    if(v[i] != 1){
                        sum += dice[i];
                    }    
                }
				
                test++;
                // cout << "tentando " << target-sum << " com " << mid << endl;
                if(solve(target - sum, mid)){
                    // cout << "deu certo" << endl;
                    return true;
                }
            }while(next_permutation(v.begin(), v.end()));

            return false;
        }

        int minimumDice(int target, vector< int > dice){
            vector< int > v;
            v.resize(dice.size());

            int st = 0, en = dice.size();
            int r = -1;
            
            while(st <= en){
                int mid = (st + en) / 2;
                
                if(check(mid, v, dice, target)){
                    r = mid;
                    en = mid - 1;
                }else{
                    st = mid + 1;
                }
            }

            return r;
        }
};

Reroll ct;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cout << ct.minimumDice(120, {6,6,6,6,6,6,3,6,6,6,1,6,6,6,6,6,1,6,6,6}) << endl;

    return 0;
}