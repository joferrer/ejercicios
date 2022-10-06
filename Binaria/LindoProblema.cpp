#include<bits/stdc++.h>


using namespace std;

int* leerNumeros (int n){
	int* array= new int[n];
	for(int i = 0; i < n; i++){
		cin>>array[i];	
	}
	return array;
}

int posMenorPositivo (const int diferencia[], const int mayor, int menor, const int n){
	
	
	if(diferencia[mayor]==0 || diferencia[menor]>=0 || diferencia[menor]+ diferencia[mayor] > 0) return menor;
	int limSuperior = mayor;
	while(true){
		
		if(diferencia[menor]>=0 || menor > limSuperior) return menor;
		
		int paso = (limSuperior + menor)/2;
		cout<<"mayor "<< mayor<<"\n";
		cout<<"lmSS: "<<diferencia[limSuperior]<<" menorS: "<<diferencia[menor]<<" paso S "<<paso<<"\n";

		if( paso>0 && diferencia[mayor] > diferencia[paso]){
			limSuperior= paso-1;
			//cout<<"lmS: "<<limSuperior<<" menor: "<<menor<<" paso "<<paso<<"\n";
		} 
		else{
			if(paso<0) paso = 0;
			menor = paso+1;
			cout<<"lmS2: "<<limSuperior<<" menor2: "<<menor<<" paso "<<paso<<"\n";
		}
			
	}
	
	return 0;
}

int main(){
	
	
	int n =0;
	cin>>n; //Tamaño de ambos arrays
	
	int* profesor   = leerNumeros(n);
	int estudiante = 0;
	
	int diferencia[n];
	
	for(int i = 0; i < n; i++){
		cin>>estudiante;
		diferencia[i] = profesor[i] - estudiante;
	}
	
	sort(diferencia,diferencia+n);
	
	
	int resp = 0;
	int menor = 0;
	
	for(int i = 0; i < n; i++){
		cout<<diferencia[i]<<" ";
	}
	
	cout<<"\n";
	
	int i = n-1;
	while( i && diferencia[i]>0){
		
		menor = posMenorPositivo(diferencia,i,menor,n);
		resp += i -  menor ;
		cout<<"i: "<<i<<" Res "<<resp<<" menor: "<<menor<<"\n";
		i--;
	}
	
	cout<<resp; 
	
	return 0;
}

