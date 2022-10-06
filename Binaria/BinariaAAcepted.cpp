#include<bits/stdc++.h>

using namespace std;

int main(){
	
	int n,m ;
	cin>> n >>m;
	
	int a[n];
	int b[m];
	
	for(int i = 0; i<n; i++)cin>>a[i];
	for(int i = 0; i<m; i++)cin>>b[i];
	
	sort(a,a+n);
	int limInf = 0;
	int limSup = n;
	int pos    = -1; // Si no lo encuentro -1;
	int mitad  = 0;
	int buscar = 0; //Numero de b al que se le sacan menores o iguales.
	int resp   = 0;
	
	for(int i = 0; i<m; i++){
		
		pos    = -1;
		resp   = 0;
		buscar = b[i];
		limInf = 0;
		limSup = n-1; 
		
		while(limInf <= limSup){
			
			mitad = limInf + (limSup - limInf)/2;
			if(a[mitad]<= buscar){
				
				pos = mitad;
				limInf = pos + 1;
				
			}
			else limSup = mitad - 1;
			
		}
		if(pos != -1) resp = pos+1;
		cout<<resp<<" ";
	}
	
	return 0;
}