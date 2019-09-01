#include <bits/stdc++.h>
using namespace std;

bool readChar(char &c) {
    c = getchar();
    return c != EOF;
}

inline void writeChar(char c) {
    putchar(c);
}

template<typename T>
bool read( T &n ) { 
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
 
template<typename T>
inline void write(T n){ 
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

#define N 1005 


long long a[N][N],b[N][N];
long long r[N],br[N],cr[N],axbr[N];

bool freivald(long long a[][N], long long b[][N], long long c[][N], int n) 
{ 
    memset(r,0,sizeof(r));
    for (int i = 0; i < n; i++) 
        r[i] = rand() % 2; 

    memset(br,0,sizeof(br)); 
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            br[i] = br[i] + b[i][j] * r[j]; 
  
  
    memset(cr,0,sizeof(cr)); 
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            cr[i] = cr[i] + c[i][j] * r[j]; 

    memset(axbr,0,sizeof(axbr)); 
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            axbr[i] = axbr[i] + a[i][j] * br[j]; 

    for (int i = 0; i < n; i++){
        if (axbr[i] - cr[i] != 0) 
            return false; 
    }
  
    return true; 
} 
  
bool isProduct( int k, int n) 
{ 
    for (int i=0; i<k; i++) 
        if (freivald(a, a, b, n) == false) 
            return false; 
    return true; 
} 
  
int main() 
{ 
		srand(time(NULL));
		int n;
    while(read(n))
    {
        if(n == 0)
            break;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0; j < n; j++)
            {
                read(a[i][j]);
            }
        }

        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0; j < n; j++)
            {
                read(b[i][j]);
            }
        }
        if (isProduct(30,n)) 
            printf("YES\n"); 
        else
            printf("NO\n"); 
    }
    return 0; 
} 
