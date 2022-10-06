

#include<bits/stdc++.h>

using namespace std;



int main(){
	
	int n;
	cin>> n;
	
	long long a[n];
	long long dif[n];
	
	for(int i = 0; i < n;i++ ){
		cin>>a[i];
	}
	
	long long b = 0;
	for(int i = 0; i < n;i++ ){
		cin>>b;
		dif[i]= a[i]-b;
	}
	
	sort(dif, dif+n);
	

	
	long long resp   = 0; // Respuesta.
	int limInf = 0;
	int limSup = n-1;
	int pos = -1;
	
	for(int i = 0; i< n ; i++){
		if(dif[i]>0) resp += n-(i+1);
		
		else{
			limSup = n-1;
			limInf = i;
			
			pos = -1;
			
			while(limSup >= limInf){
				int paso = (limSup - limInf)/2;
				if(dif[limInf + paso] + dif[i] > 0){
					pos    = limInf + paso;
					limSup = pos - 1;
				} 
				else limInf = limInf + paso +1;
			}
			if(pos != -1) resp += n- pos;		
		} 
	}
	
	cout<<resp;
	
	
	return 0;
}