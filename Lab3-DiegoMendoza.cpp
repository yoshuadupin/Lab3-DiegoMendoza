#include<iostream>
#include<vector>
using namespace std;

int** operar(int**,int,int,int);
void imprimir(int**,int ); 


int main(){
	//Main
	//int*** matriz3D;
	vector<int**>	vMatriz;
	int opcion;
	int divisor;
	
	cout<<"Bienvenido al ejercicio\n";
	cout<<"Ingrese el ejercicio que desea\n1.Ejercicio 1\n2.Ejercicio 2\n3. salir";
	cin>>opcion;

	while(opcion!=3){

		if(opcion == 1){
			
			int grado; 
			cout<<"--------Ejercicio 1-----------\n";
			cout<<"Ingrese el grado del Polinomio:\n";

			do{

			cin>>grado;

			//Iniciar Matriz3D
			

			}while(grado<=0);
			//LLenado de Matriz
		
			cout<<"Ingrese a:\n";
			cin>>divisor;

			int** matriz = new int*[3];
	
			for(int i = 0 ; i < 3 ; i++){
				matriz[i] = new int[grado];
			}
	
			for(int i = 0 ; i<grado;i++){
				cout<<"Ingrese el polinomio x^"<<i<<":";
				cin>>matriz[0][i];
			}
	
			matriz[2][0]=matriz[0][1];
			vMatriz.push_back(matriz);
		//	for(int i = 0 ; i<3 ; i++){
		//		delete[] matriz[i];	
		//	}
		//	delete matriz;
			
			
			
			for(int i = 0 ; i<grado;i++){
			 vMatriz.push_back(operar(vMatriz[i],i,divisor,grado));
				//vMatriz.push_back(matriz);
			}
			
			//Imprimir 
			for (int i = 0 ; i<vMatriz.size() ; i++){
				cout<<"----------------------------------------\n";
				imprimir(vMatriz.at(i),grado+1);
				cout<<"---------------------------------------------\n";
			}
		//	for(int i = 0 ; i<grado ; i++){
		//		matriz3D[i] = new int*[3];
		//	}
		//	for(int i = 0 ; i<grado ; i++){
		//		for(int j = 0 ; j<3 ; j++){
		//			for(int k = 0 ; k<grado ; k++){
		//				matriz3D[i][j][k]=NULL;
		//			}
		//		}
		//	}
						
				
			
	}else{
		cout<<"EJERCICIO 2:\n";
		
		
	}
	}
	return 0;

}
void imprimir(int** m ,int grado ){
	for(int i = 0 ; i<3 ; i++){
   	for(int j = 0 ; j<grado ; j++){
			cout<<m[i][j];
			
		}
		cout<<endl;
	}
}




int** operar(int** matriz, int colum,int a,int grado){
	if(colum==grado){
		matriz[2][colum+1]=matriz[0][colum+1]+matriz[1][colum+1];
	
	}else{
		matriz[1][colum+1]=matriz[2][colum]*a+matriz[1][colum+1];
		matriz[2][colum+1]=matriz[0][colum+1]+matriz[1][colum+1];
	}		
	return matriz;
}
