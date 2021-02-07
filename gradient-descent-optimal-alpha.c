//gradient descent for a 2 variables function with  variable and optimal learning rate By kingridda
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

//parameters 
#define N 100000  //maximum number of iterations
#define Min_ALFA 0.0001 //Minimum accepted learning rate 
#define Max_ALFA 0.5 //since optimal is calculated. we 'd want to restrict it with a max value
#define Error 0.0001 //tolerated error

//notice if we dont restrict alfa in this exemple the algorithm converge in 2 iterations because optimal founded by alpha is global :) (optimal alpha is a powerfull method)

float f(float x, float y){
	return 0.5*pow(x, 2) + 0.5*pow(y, 2);
}
float dfx(float x, float y){
	return x;
}
float dfy(float x,float y){
	return y;
}

//simple math to find optimal alpha for the funtion f at every iteration
float optimal_alfa(float x, float y, float dx, float dy){
	
	return (dx * x + dy * y)/(pow(dx, 2) + pow(dy, 2));
}

float positify_restrict(float alf){
	if(alf > Max_ALFA) return Max_ALFA;
	if(alf > Min_ALFA) return alf;
	return Min_ALFA;
}

int main(){
	int i = 0;
	float  x, y, tempX, tempY, tempDfx, tempDfy, err = Error, alpha = Min_ALFA;

	x = rand() % 200 - 100; // first iteration from a random point, x and y between -100 and 99
	y = rand()  % 200 - 100; 
	tempDfx = dfx(x, y);
	tempDfy = dfy(x, y);
	
	while ( (fabs(tempDfx) > err || fabs(tempDfy) > err ) && i < N ){
		
		tempX = x - alpha * tempDfx;
		tempY = y - alpha * tempDfy;
		x = tempX;
		y = tempY;
		
		printf("iteration %d with alfa %f:   (x,y) = (%f,%f) ====> f(x,y) = %f\n", i, alpha, x, y, f(x, y));
		i = i + 1;	
		
		//compute derevative for next iteration
		tempDfx = dfx(x, y);
		tempDfy = dfy(x, y);
		alpha = positify_restrict(optimal_alfa(x, y, tempDfx, tempDfy));
		
	}
	
	printf("(x*,y*)    :   (x,y) = (%f,%f)\n", x, y);
	printf("....done after %d iteration\n", i);
	return 0;
}
