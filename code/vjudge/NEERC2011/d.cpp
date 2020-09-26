#include<bits/stdc++.h>
using namespace std;
const int N=100100;
const int M=400;
typedef long long ll;
int c[N];
int main()
{
    int n,a,b;
    int first = 1;
    while(cin>>n)
    {
    	if(!first){
    		cout << endl;
    	}
    	
    	first = 0;
        for (int i = 0; i < n-1; ++i)
        {
            cin>>a>>b;
            c[a]++;
            c[b]++;
        }
        vector<int> bad;
        for (int i = 1; i <= n; ++i)
        {
            if(c[i]==1)
            {
                bad.push_back(i);
            }
            c[i]=0;
        }
        assert(bad.size()>=2);
        vector<pair<int,int>> rs;
        int ini=0;
        if(bad.size()%2==1)
        {
            ini=1;
            rs.push_back({bad[0],bad[1]});
        }
        for (int i = ini; i < bad.size() ; i+=2)
        {
            rs.push_back({bad[i],bad[i+1]});
        }
        cout<<rs.size();
        if(rs.size() != 0){
        	cout << endl;
        }

        for(int i = 0 ; i < rs.size() ; i++)
        {	
        	auto c = rs[i];

            cout << c.first << " " << c.second;
        	
        	if(i != rs.size() - 1){
        		cout << endl;
        	}
        }

    }
    return 0;
} 