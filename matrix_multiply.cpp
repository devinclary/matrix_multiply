#include <iostream>
#include <ctime>
using namespace std;
using namespace std;


int rand(int upperLim ) //generate random number between 1 and upperLim
{
	return rand()%upperLim;
}

void initDynM(int **a, int size){
	for(int row=0; row<size; row++) //initializ **mp
		a[row]=new int[size];
}

void printDynM(int **mp, int size){
	for(int row=0; row<size; row++){
		for (int col=0; col<size; col++){
			cout<<*(mp[row]+col)<<" | ";
		}
		cout<<endl;
	}
}


void randDynM(int **mp, int size){
	initDynM(mp, size);
	for(int row=0; row<size; row++) //assign random values to *mp
		for (int col=0; col<size; col++)
			*(mp[row]+col)=rand(10);
}

void dynMFromStatM(int stat[10][10], int **dyn){ //create a dynamic matrix that is equal to a static matrix
	int i, j;
	int n=10;
	initDynM(dyn, n);
	for(i=0; i<n; i++) //assign each value in **dyn according to the same entry in stat[][]
		for (j=0; j<n; j++)
			*(dyn[i]+j)=stat[i][j];
}


void multiplyDynamicM(int **a, int **b, int **c, int n){
	int i, j, k;
	for(i=0; i<n; i++){
	    for(j=0; j<n; j++){
	    	for(*(c[i]+j)=k=0; k<n; k++){
	    		*(c[i]+j)+= *(a[i]+k) * *(b[k]+j);
	    	}
	    }
	}
}

void printStatM(int c[10][10]){
	for(int i=0; i<10; i++){
		for(int k=0; k<10; k++){
			cout<<c[i][k]<<" | ";
		}
		cout<<endl;
	}
}

void randStatM(int a[10][10]){
	for(int i=0; i<10; i++)
		for (int j=0; j<10; j++)
			a[i][j]=rand(10);
}


void multiplyStatM(int a[10][10], int b[10][10], int c[10][10]){
	int i, j, k;
	for(i=0; i<10; i++)
		for(j=0; j<10; j++)
			for(c[i][j]=k=0; k<10; k++)
                c[i][j] += a[i][k]*b[k][j];
}






int main(void){
	srand((unsigned int)time(NULL));
	int **dynMA=new int* [10];
	int **dynMB=new int* [10];
	int **dynResult=new int* [10];
	initDynM(dynResult, 10);
	int statMA[10][10];
	int statMB[10][10];
	int statResult[10][10];
	randStatM(statMA);
	randStatM(statMB);
	dynMFromStatM(statMA, dynMA);
	dynMFromStatM(statMB, dynMB);
	// randDynM(dynMA, 10);



	cout<<"Dynamic Multiplication: "<<'\n'<<endl;
	cout<<"Matrix A: "<<endl;
	printDynM(dynMA, 10);
	cout<<endl;
	cout<<"Matrix B: "<<endl;
	printDynM(dynMB, 10);
	cout<<endl;
	multiplyDynamicM(dynMA, dynMB, dynResult, 10);
	cout<<"A*B Result: "<<endl;
	printDynM(dynResult, 10);


	cout<<"Static Multiplication: "<<'\n'<<endl;
	cout<<"Matrix A: "<<endl;
	printStatM(statMA);
	cout<<endl;
	cout<<"Matrix B: "<<endl;
	printStatM(statMB);
	cout<<endl;
	multiplyStatM(statMA, statMB, statResult);
	cout<<"A*B Result: "<<endl;
	printStatM(statResult);



	// randDynM(mp);
	// printDynM(mp);


	
	return 0;
}