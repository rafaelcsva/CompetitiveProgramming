#include <bits/stdc++.h>

using namespace std;

const int N = 60;
string pages[N];

string generate_blank_line(int n){
	string line = ".";

	for(int i = 1 ; i < n ; i++){
		line += ".";
	}

	return line;
}

void init(){
	string s = generate_blank_line(60);

	for(int i = 0 ; i < 60 ; i++){
		pages[i] = s;
	}
}

int main (){
	init();

	string command, f, s;
	int r, c;

	while(cin >> command){
		if(command == ".EOP"){
			break;
		}

		cin >> f;
		cin >> r;

		if(command == ".P"){
			cin >> c;
			cin >> s;	
			
		}else if(command == ".L"){
			
			cin >> s;
			
		}else if(command == ".R"){
			cin >> s;
		}else if(command == ".C"){
			cin >> s;

			
		}
	}

	return 0;
}
