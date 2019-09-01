#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;

	cin >> s;

	int num1 = (s[0] - '0') * 10 + s[1] - '0';
	int num2 = (s[2] - '0') * 10 + s[3] - '0';
	bool can1 = false, can2 = false;

	if(num1 >= 1 && num1 <= 12){
		can1 = true;
	}

	if(num2 >= 1 && num2 <= 12){
		can2 = true;
	}

	if(can1 && can2){
		cout << "AMBIGUOUS" << endl;
	}else if(can1){
		cout << "MMYY" << endl;
	}else if(can2){
		cout << "YYMM" << endl;
	}else{
		cout << "NA" << endl;
	}

	return 0;
}