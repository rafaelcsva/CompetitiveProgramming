//10, 06, 2018, 07:50:54 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

const int N = 1010;
int ma[N][N], mb[N][N];
int n, a, b;

void print(){
    cout << "YES" << endl;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cout << ma[i][j] ;
        }

        cout << endl;
    }
}

void pass(){
    for(int i = 0 ; i < n ; i++){
        for(int j = i + 1 ; j < n ; j++){
            if(!mb[i][j]){
                ma[i][j] = ma[j][i] = 1;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> a >> b;

    if(a > 1){
        if(b != 1){
            cout << "NO" << endl;
        }else{
            int comp = n;

            for(int i = 0 ; i < n ; i++){
                for(int j = i + 1 ; j < n ; j++){
                    if(comp == a){
                        break;
                    }

                    ma[i][j] = ma[j][i] = 1;
                    comp--;
                }
            }

            print();
        }
    }else if(a == 1){
        if(b > 1){
            int comp = n;

            for(int i = 0 ; i < n ; i++){
                for(int j = i + 1; j < n ; j++){
                    if(comp == b){
                        break;
                    }

                    mb[i][j] = mb[j][i] = 1;
                    comp--;
                }
            }

            pass();
            print();
        }else{
            if(n == 3 || n == 2){
                cout << "NO" << endl;
            }else{
                for(int i = 0 ; i < n - 1 ; i++){
                    ma[i][i + 1] = 1;
                    ma[i + 1][i] = 1;
                }

                print();
            }
        }
    }
    
    return 0;
}