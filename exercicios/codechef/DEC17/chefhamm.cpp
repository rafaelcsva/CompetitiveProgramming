#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
vector<int> un;
vector<int> tup;
int first[N], second[N];
int used[N];
int cnt[N];
int a[N];

void swap_tuple(int a, int b, int A[]){
	swap(A[first[a]], A[first[b]]);
	swap(A[second[a]], A[second[b]]);
}

int main (){
	int t;
	

	scanf("%d", &t);

	for(int k = 1 ; k <= t ; k++){
		int n;
		un.clear();
		tup.clear();
		scanf("%d", &n);

		for(int i = 0 ; i < n ; i++){
			scanf("%d", a + i);
			
			if(used[a[i]] != k){
				used[a[i]] = k;
				cnt[a[i]] = 1;
				first[a[i]] = i;
								
			}else{
				cnt[a[i]] = 2;
				second[a[i]] = i;
			}
		}
		
		if(n == 1){
			printf("0\n");
			printf("%d\n", a[0]);

			continue;
		}

		for(int i = 0 ; i < n ; i++){
			if(cnt[a[i]] == 1){
				un.push_back(a[i]);
			}else if(first[a[i]] == i){
				tup.push_back(a[i]);
			}
		}
	
		int ans = 0;
		
		int m = tup.size() - 1;
		int l = un.size() - 1;

		for(int i = 0 ; i < m ; i++){
			swap_tuple(tup[i], tup[i + 1], a);
			ans+=2;
			if(i == 0)
				ans+=2;
		}
		for(int i = 0 ; i < l ; i++){
			swap(a[first[un[i]]], a[first[un[i + 1]]]);
			ans+=1;
			if(i == 0)
				ans++;
		}

		if(un.size() == 1 && tup.size() == 1){
			swap(a[first[un[0]]], a[first[tup[0]]]);
			ans+=2;
		}else if(un.size() == 1 && tup.size() >= 1){
			swap(a[first[un[0]]], a[first[tup[0]]]);
			ans+=1;
		}else if(tup.size() == 1 && un.size() > 1){
			swap(a[first[tup[0]]], a[first[un[0]]]);
			swap(a[second[tup[0]]], a[first[un[1]]]);
			ans+=2;
		}

		printf("%d\n", ans);

		for(int i = 0 ; i < n ; i++){
			char c = i == n - 1 ? '\n' : ' ';
			printf("%d%c", a[i], c);
		}

		
	}

	return 0;
}
