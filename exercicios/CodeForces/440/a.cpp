#include <bits/stdc++.h>

using namespace std;

int verif1[10];
int verif2[10];

int main (){
	int n, m;

	int l1[20];
	int l2[20];

	cin>>n>>m;

	for(int i = 0 ; i < n ; i++){
		cin>>l1[i];
		verif1[l1[i]] = 1;

	}

	for(int i = 0 ; i < m ; i++){
		cin>>l2[i];
		verif2[l2[i]] = 1;
	}

	sort(l1, l1+n);
	sort(l2, l2+m);

	int me = -1;
	
	for(int i = 0 ; i < 10; i++){
		if(verif1[i] && verif2[i]){
			me = i;
			break;
		}
	}

	if(me != -1){
		cout<<me<<endl;
	}else if(l1[0] < l2[0]){
		cout<<l1[0]<<l2[0]<<endl;
	}else{
		cout<<l2[0]<<l1[0]<<endl;
	}

	return 0;
}
