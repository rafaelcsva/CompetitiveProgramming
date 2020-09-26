#include <bits/stdc++.h>
using namespace std;
#define spc " "
#define ll long long
#define ft first
#define sd second
#define pi pair<int,int>
const int N=210;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ofstream fout("digits.out");
    ifstream fin("digits.in");
    ll n;
    fin>>n;
    if(n==1)
      fout<<"1\n";
    else
    {
      n--;
      fout<<((n*(n+1))/2)*11LL<<"\n";
    }
    
    return 0;
}