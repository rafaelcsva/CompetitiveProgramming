    #include <bits/stdc++.h>
    using namespace std;
     
    typedef struct{
    	int p, s;
    }Cook;
     
    typedef struct{
    	int d, m;
    }Dish;
     
    const int N = 60;
     
    int main() {
    	int t;
    	Cook cooks[N];
    	Dish dishes[N];
    	scanf("%d", &t);
    	
    	while(t--){
    		int k;
    		
    		scanf("%d", &k);
    		
    		for(int i = 0 ; i < k ; i++){
    			scanf("%d %d", &cooks[i].p, &cooks[i].s);
    		}
    		
    		int n;
    		
    		scanf("%d", &n);
    		
    		for(int i = 0 ; i < n ; i++){
    			scanf("%d %d", &dishes[i].d, &dishes[i].m);
    		}
     
    		int minCost = -1;
    		
    		for(int i = 0 ; i < k ; i++){
    			if(dishes[0].m * cooks[i].p >= dishes[0].d){
    				if(minCost == -1 || cooks[i].s < minCost){
    					minCost = cooks[i].s;
    				}
    				
    			}
    		}
    		
    		printf("%d\n", minCost);
    	}
    	
    	return 0;
    } 
