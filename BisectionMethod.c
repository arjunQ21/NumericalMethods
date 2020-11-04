#include <stdio.h>
#include <math.h>
#define EPS 0.001

int iteration = 0;

float f(float x){
	//f(x) = x-sin(x)-1/2
	return (x - sin(x) - 0.5) ;
}
float bisection(float a, float b){
	if(f(a)*f(b) < 0){
		float c = (a + b) / 2 ;
		float error = fabs(a - b) ;
		printf("Iteration: %d ", ++iteration) ;
		printf("a: %f, b: %f, c: %f, f(a): %f, f(b): %f, f(c): %f, Error: %f\n", a, b, c, f(a), f(b), f(c), error) ;

		if(error < EPS) {
			printf("\n\nEnd.\nx= %f", c);
			return c ;
		}
		if(f(a)*f(c) < 0){
			 bisection(a, c) ;
		}else{
			 bisection(b, c) ;
		}
	}else{
		printf("invalid range: (%.2f, %.2f)", a, b) ;
		return 0.0 ;
	}
}
main(){
	float a, b ;
	printf("\nEnter range \na: ");
	scanf("%f", &a) ;
	printf("\nb:") ;
	scanf("%f", &b) ;
	bisection(a, b) ;
}


