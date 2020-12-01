#include<stdio.h>
#include<math.h>
#define EPS 0.0000001

//x2 = x1 - f(x1)/f'(x1)
//3x-cosx+1
float f(float x){
//	return x*x*x*x - x - 10 ;
return (3*x - cos(x) - 1) ;
}
float f1(float x){
//	return 4*x*x*x - 1 ;
return (3 + sin(x)) ;
}
 

main(){
	printf("\n\tNewton Rhapson Method.\n\n") ;
	printf("\nSN.  xN  xN+1  Error");
	int i = 0 ;
	float current = 5000 ;
	float lastValue = current ;
	do{
		i++ ;
		if(f1(current) == 0){
			printf("Denominator came 0. stopping.") ;
			break ;
		}
		lastValue = current ;
		current = lastValue - (f(lastValue)/ f1(lastValue)) ;
		printf("\n%d. %f  %f  %f", i, lastValue, current, fabs(current - lastValue)) ;
		
	}while(fabs(current - lastValue) > EPS) ;
	printf("\nFound root: %f", current) ;
}
