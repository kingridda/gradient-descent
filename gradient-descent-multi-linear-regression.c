//gradient descent for a 2 variables function with fixed learning rate By kingridda
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

//parameters 
#define N 100000  //maximum number of iterations
#define ALFA 0.01 //learning rate 
#define Error 0.00001 //tolerated error
#define Dimension 3 // dimention of the function (number of features)
#define N_data 3 //nbr of data entries (samples)



float tetas[Dimension + 1];
float X[N_data][Dimension + 1]={{1,2,1,2}, {1,0,3,3},{1,3,3,0}}; //X contain a 1 in the first feature exemple Xi=(2,2,2) ==> X[i] = {1, 2, 2, 2}
float Y[N_data];
float targetY[N_data] = {4,2, 3};
float Dtetas[Dimension + 1];//gradint dereivitive for every theta

float dot_product(int i){
	int j = 0;
	float tempy = 0;
	for(; j <= Dimension; j++)tempy += X[i][j] * tetas[j];
	return tempy;	
}
void predict_Y(){
	int i = 0;
	for(; i < N_data; i++) Y[i] = dot_product(i);
}
float cost_f(){
	int i = 0;
	float res = 0;
	float temp_2m = 2 * N_data; // we devide the total error by the number of samples (2 useful for clean derevative porposes)
	for(; i < N_data; i++)res += pow(Y[i] - targetY[i], 2) /temp_2m;
	return res;
}

float gradient_teta(int i){//the derevative for a selected theta
	float tempdi = 0;
	int j = 0;
	for(; j <= N_data; j++)tempdi +=  (Y[j] - targetY[j] )* X[j][i];
	return tempdi;
}

void gradient_tetas(){
	int i = 0;
	for(; i <= Dimension; i++ )
		Dtetas[i] = gradient_teta(i);
}

void descent_f(){
	int i = 0;
	for(; i <= Dimension; i++)
		tetas[i] = tetas[i] - ALFA / N_data * Dtetas[i];
}




void initialize(){
	//initalize  params tetas to random value
	int i = 0;
	for(; i < N_data; i++)X[i][0] = 1;
	for(i = 0; i <= Dimension; i++)tetas[i] = (float)rand()/(float)(RAND_MAX);
}

int main(){
	initialize();
	int i = 0;	
	
	while ( i < N &&  cost_f() >Error ){
		
		predict_Y();
		
		gradient_tetas();
		
		descent_f();
		
		printf("iteration %d cost function = %f\n",i, cost_f());
		i++;
	}
	
	printf(" cost function:   %f\n", cost_f() );
	printf("....done after %d iteration\n", i);
	for(i = 0; i < N_data; i++)printf("%f : %f \n",Y[i],targetY[i]);
	for(i = 0; i <= Dimension; i++)printf("%f  \n",tetas[i]);
	
}
