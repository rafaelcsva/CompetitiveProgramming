//19, 07, 2018, 22:41:26 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 50, T = 9;
ld pre[N][T];
ld sum[N][T];

class TestProctoring{
    public:
        double expectedTime(vector <int> p, vector <int> q){
            ld expected_time = 1.0L;
            
            for(int i = 0 ; i < p.size() ; i++){
                ld leave = ld(p[i]) / ld(q[i]);
                ld stay = ld(q[i] - p[i]) / ld(q[i]);
                ld past = 1.0L;

                for(int t = 1 ; t < T ; t++){
                    pre[i][t] = past * leave;
                    
                    if(t == 1){
                        expected_time *= leave;
                    }

                    past *= stay;
                }
            }

            for(int i = 0 ; i < p.size() ; i++){
                for(int t = 1 ; t < T ; t++){
                    sum[i][t] = sum[i][t - 1] + pre[i][t];
                }
            }

            int n = p.size();

            for(int t = 2 ; t < T ; t++){
                for(int mask = 1 ; mask < (1 << n) ; mask++){
                    ld prob = 1.0L;

                    for(int j = 0 ; j < n ; j++){
                        int el = 1 << j;

                        if(mask & el){
                            prob *= pre[j][t];
                        }else{
                            prob *= sum[j][t - 1];
                        }
                    }
                    expected_time += t * prob;
                }
            }

            return expected_time;
        }
};

TestProctoring test;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cout << test.expectedTime(  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, {1000000000,1000000000,1000000000,1000000000,1000000000, 1000000000,1000000000,1000000000,1000000000,1000000000, 1000000000,1000000000,1000000000,1000000000,1000000000, 1000000000,1000000000,1000000000,1000000000,1000000000}) << endl;
    return 0;
}