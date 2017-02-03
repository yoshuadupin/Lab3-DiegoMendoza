#include<iostream>
#include<vector>
using namespace std;

void operar(int**,int,int);
void imprimir(vector<int**>); 


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
				cin>>matriz[0][i];
			}
	
			matriz[2][0]=matriz[0][1];
			vMatriz.push_back(matriz);
			for(int i = 0 ; i<3 ; i++){
				delete[] matriz[i];	
			}
			delete matriz;
			
			
			
			for(int i = 0 ; i<grado;i++){
				matriz = operar(vMatriz[i],i,divisor);
				vMatriz.push_back(matriz);
			}
			cout<<"-----------------------------------------------";
			//Imprimir 
			imprimir(vMatriz);
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
						
				
			
	}
	return 0;

}
void imprimir(vector<int**> vMatriz){
	for(int i = 0 ; i<vMatriz.size() ; i++){
      for(int j = 0 ; j<3 ; j++){
          for(int k = 0 ; k<grado ; k++){
             if(k==grado-1){
                cout<<vMatriz[i][j][k]<<" |"<<endl;
              }else{
                cout<<vMatriz[i][j][k]<<"  "<<endl;
               }
				if(j==1){
					cout<<"----------------------------------------------------------";
				}	
           }
      }
  
   }
}	




int** operar(int** matriz, int colum,int a){
	if(colum==0){
		matriz[2][colum+1]=matriz[0][colum+1]+matriz[1][colum+1];
	
	}else{
		matriz[1][colum+1]=matriz[2][colum]*a+matriz[1][colum+1];
		matriz[2][colum+1]=matriz[0][colum+1]+matriz[1][colum+1];
	}		
	return matriz;
}
