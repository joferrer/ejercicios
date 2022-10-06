#include<bits/stdc++.h>

using namespace std;

int main(){
	//n -> # ingredientes : m -> poderMagico
	int n,k ;
	cin>> n >>k;
	int cuesta[n], tengo[n];
	for(int i = 0; i<n ; i++) cin>>cuesta[i];
	for(int i = 0; i<n ; i++) cin>>tengo[i];
	
	//Se hace binaria sobre las posibles soluciones.
	int  menor = 0, mayor = 2001;
	
	while(menor <= mayor ){
		
		int mitad = menor + (mayor - menor)/2;
		int costo = 0;
		
		for(int i = 0; i<n ; i++){
			costo += max(cuesta[i]*mitad - tengo[i], 0);  
		}
		if(costo <= k) menor = mitad +1;
		else mayor = mitad -1; 
	}
	
	cout<< mayor; 
	
	return 0;
}