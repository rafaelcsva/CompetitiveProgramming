//19, 07, 2018, 22:05:30 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

const int N = 1000;
bool ver[N][N];

class SquareCutout{
    public:
        int verify(vector <string> cutout){
            int sz = -1;

            for(int i = 0 ; i < cutout.size() ; i++){    
                for(int j = 0 ; j < cutout.size() ; j++){
                    if(cutout[i][j] == '#'){
                        int sz1 = 0;
                        int sz2 = 0;
                        int kj = j;
                        int ki = i;

                        while(kj < cutout[i].size()){
                            if(cutout[i][kj] != '#'){
                                break;
                            }

                            sz1++;
                            kj++;
                        }

                        while(ki < cutout.size()){
                            if(cutout[ki][j] != '#'){
                                break;
                            }

                            sz2++;
                            ki++;
                        }

                        sz = max(sz1, sz2);

                        for(int d = 0 ; d < sz ; d++){
                            if(d + i >= cutout.size()){
                                break;
                            }
                            
                            for(int m = 0 ; m < sz ; m++){
                                if(m + j >= cutout[d + i].size()){
                                    break;
                                }

                                if(cutout[d + i][m + j] != '#'){
                                    return -1;
                                }

                                ver[d + i][m + j] = true;
                            }
                        }

                        break;
                    }
                }

                if(sz != -1){
                    break;
                }
            }

            for(int i = 0 ; i < cutout.size() ; i++){
                for(int j = 0 ; j < cutout[i].size() ; j++){
                    if(cutout[i][j] == '#' && !ver[i][j]){
                        return 0;
                    }
                }
            }

            return max(sz, 1);
        }
};

SquareCutout test;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cout << test.verify({".....", "..##.", "..##.", ".....", "....."}) << endl;
    return 0;
}