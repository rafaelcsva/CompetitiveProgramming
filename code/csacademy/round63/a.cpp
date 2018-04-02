#include <iostream>

using namespace std;

const int N = 1010;
int A[N], B[N];

int main() {
    int n, m;
    
    cin >> n >> m;
    
    for(int i = 0 ; i < n ; i++){
        cin >> A[i];
    }
    
    for(int j = 0 ; j < m ; j++){
        cin >> B[j];
    }
    
    int cnt = 0;
    
    for(int i = 0 ; i < m ; i++){
            bool ver = true;
            
            for(int j = i, k = 0 ; j < m && k < n ; j++, k++){
		
                if(A[k] + B[j] != 1){
			
                    ver = false;
                    break;
                }    
            }
            if(ver){
                cnt++;
            }
    }
    
    cout<< cnt << '\n';
    
    return 0;
}
