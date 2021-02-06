//gradient descent for a 2 variables function with fixed learning rate By kingridda
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

//parameters 
#define N 100000  //maximum number of iterations
#define ALFA 0.0005 //learning rate 
#define Error 0.01 //tolerated error

float f(float x, float y){
	return 0.5*pow(x, 2) + 0.5*pow(y, 2);
}
float dfx(float x, float y){
	return x;
}
float dfy(float x,float y){
	return y;
}

int main(){
	int i = 0;
	float  x, y, tempX, tempY, tempDfx = 100, tempDfy = 100, err = Error, alpha = ALFA;

	x = rand() % 200 - 100; // first iteration from a random point, x and y between -100 and 99
	y = rand()  % 200 - 100; 
	
	while ( (fabs(tempDfx) > err || fabs(tempDfy) > err ) && i < N ){
		
		tempX = x - alpha * tempDfx;
		tempY = y - alpha * tempDfy;
		x = tempX;
		y = tempY;
		
		printf("iteration %d :   (x,y) = (%f,%f) ====> f(x,y) = %f\n", i, x, y, f(x, y));
		i = i + 1;	
		
		//compute derevative for next iteration
		tempDfx = dfx(x, y);
		tempDfy = dfy(x, y);
	}
	
	printf("(x*,y*)    :   (x,y) = (%f,%f)\n", x, y);
	printf("....done after %d iteration\n", i);
}
