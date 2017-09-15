#include <bits/stdc++.h>

using namespace std;

int main (){
	int c, a;
	int p;
	
	scanf("%d%d", &c, &a);
	
	p = a/(c-1);
	
	if(a%(c-1) > 0)
		p++;
		
	printf("%d\n", p);
	
}
