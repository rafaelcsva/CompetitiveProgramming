#include <bits/stdc++.h>

using namespace std;

int main (){
	map<string, string>dicionario;
	
	dicionario["brasil"] = 
	
	dicionario["brasil"] = "Feliz Natal!";
	dicionario["alemanha"] = "Frohliche Weihnachten!";
	dicionario["austria"] = "Frohe Weihnacht!";
	dicionario["coreia"] = "Chuk Sung Tan!";
	dicionario["espanha"] = "Feliz Navidad!";
	dicionario["grecia"] = "Kala Christougena!";
	dicionario["estados-unidos"] = "Merry Christmas!";
	dicionario["inglaterra"] = "Merry Christmas!";
	dicionario["australia"] = "Merry Christmas!";
	dicionario["portugal"] = "Feliz Natal!";
	dicionario["suecia"] = "God Jul!";
	dicionario["turquia"] = "Mutlu Noeller";
	dicionario["argentina"] = "Feliz Navidad!";
	dicionario["chile"] = "Feliz Navidad!";
	dicionario["mexico"] = "Feliz Navidad!";
	dicionario["antardida"] = "Merry Christmas!";
	dicionario["canada"] = "Merry Christmas!";
	dicionario["irlanda"] = "Nollaig Shona Dhuit!";
	dicionario["belgica"] = "Zalig Kerstfeest!";
	dicionario["italia"] = "Buon Natale!";
	dicionario["libia"] = "Buon Natale!";
	dicionario["siria"] = "Milad Mubarak!";
	dicionario["marrocos"] = "Milad Mubarak!";
	dicionario["japao"] = "Merii Kurisumasu!";
	
	string s;
	
	while(cin>>s){
		map<string,string>::iterator it;
		
		it = dicionario.find(s);
		
		if(it != dicionario.end()){
			cout<<it->second<<'\n';
		}else{
			cout<<"--- NOT FOUND ---\n";
		}
	}
}
