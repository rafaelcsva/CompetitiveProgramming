#include <bits/stdc++.h>
 
using namespace std;
 
typedef pair< long long, int >	pli;
const int N = 4010;
int u[N][N];
int n, k;
const int INF = int(1e9);
vector< int > dp_before(N), dp_cur(N);
int comp[N][N];
int pref[N][N];

bool read( int &n ) { 
    n = 0; 
    register bool neg = false; 
    register char c = getchar(); 
    if( c == EOF) { n = -1; return false; } 
    while (!('0' <= c && c <= '9')) { 
        if( c == '-' ) neg = true; 
        c = getchar(); 
    } 
    while ('0' <= c && c <= '9') { 
        n = n * 10 + c - '0'; 
        c = getchar(); 
    } 
    n = (neg ? (-n) : (n)); 
    return true; 
} 
 
inline void writeInt(int n){ 
    register int idx = 20; 
    if( n < 0 ) putchar('-'); 
    n = abs(n); 
    char out[21]; 
    out[20] = ' '; 
    do{ 
        idx--; 
        out[idx] = n % 10 + '0'; 
        n/= 10; 
    }while(n); 
    do{ putchar(out[idx++]); } while (out[idx] != ' '); 
} 
 
int C(int k, int mid){
	if(k > mid){
		return 0;
	}
 
	if(comp[k][mid] != -1){
		return comp[k][mid];
	}else{
		int sum = 0;
 
		sum = pref[k][mid] - pref[k][k];
 
		comp[k][mid] = sum + C(k + 1, mid);
 
		// printf("%d-%d = %d\n", k, mid, comp[k][mid]);
		return comp[k][mid];
	}
}
 
void compute(int l, int r, int optl, int optr, vector< int > &dp_before, vector< int > &dp_cur){
	if(l > r){
		return;
	}
 
	int mid = (l + r) >> 1;
	pli best = {INF, -1};
 
	int sum = 0;
 
	int ee = max(mid, optr);
 
	for(int k = ee ; k >= optl ; k--){
		// printf("%d-%d = %d\n", k + 1, ee, sum);
		best = min(best, {dp_before[k] +  C(k + 1, mid), k});
	}
	
	dp_cur[mid] = best.first;
	int opt = best.second;
 
	compute(l, mid - 1, optl, opt, dp_before, dp_cur);
	compute(mid + 1, r, opt, optr, dp_before, dp_cur);
}

int main(){
	memset(comp, -1, sizeof comp);
 	
 	read(n);
 	read(k);

	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			read(u[i][j]);
		}
	}
 
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			pref[i][j] = u[i][j];
 
			if(j){
				pref[i][j] += pref[i][j - 1];
			}
		}
	}
 
	for(int i = 0 ; i < n ; i++){
		if(i){
			dp_before[i] = dp_before[i - 1];
		}
 
		for(int j = 0 ; j < i ; j++){
			dp_before[i] += u[i][j];
		}
 
		// printf("%d: %d\n", i, dp_before[i]);
	}
 
	int tmp = k;
	tmp--;
	int d = 0;
 
	while(tmp){
		if((d & 1) == 0){
			compute(0, n - 1, 0, n - 1, dp_before, dp_cur);
			// printf("r1 = %d\n", dp_cur[n - 1]);
		}else{
			compute(0, n - 1, 0, n - 1, dp_cur, dp_before);
			// printf("r2 = %d\n", dp_before[n - 1]);
		}
 
		d++;
		tmp--;
	}
 
	if(k & 1){
		writeInt(dp_before[n - 1]);
	}else{
		writeInt(dp_cur[n - 1]);
	}
 
	return 0;
}