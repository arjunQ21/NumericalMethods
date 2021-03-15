#include <stdio.h>
#include <math.h>
#include <conio.h>

//float 

void gaussElimintaion( double mat[20][20], int n);
void showMatrix( float mat[20][20], int n){
	printf("\n") ;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j <=n ; j++){
			printf("%g\t", mat[i][j]) ;
		}
		printf("\n") ;
	}
	printf("\n") ;
}

main(){
	int i, j, k, n = 3 ;
	 float coeffMatrix[20][20]  ;
	 
//	 = {
//		{4, 1, -1, 3},
//		{2, 7, 1, 19},
//		{1, -3, 12, 31}
//	};
//		[4, 1, -1, 3],
//		[2, 7, 1, 19], 
//		[1, -3, 12, 31]
//	];
	printf("\nEnter order of matrix: ") ;
	scanf("%d", &n) ;
	if( n < 3 || n > 20){
		printf("A value between 3 and 20 is expected. \nExiting.") ;
		return 0;
	}
	
//	input part
	for(i = 0 ; i < n ; i++){
				showMatrix(coeffMatrix, n);
		for(j = 0 ; j <= n ; j++){
			printf("\nEnter element[%d][%d]: ", i + 1, j + 1);
			scanf("%f", &coeffMatrix[i][j]) ;
			
//			printf("\nYou entered: %e", coeffMatrix[i][j]);
		}
//		showMatrix(coeffMatrix, n);
		double h = coeffMatrix[i][0] ;
		for(j = 0 ; j < n  ; j++){
//			printf("\nj = %d, i = %d, n = %d, item = %d", j, i, n, coeffMatrix[i][j]);
			if(coeffMatrix[i][j] > h) h = coeffMatrix[i][j] ; 
		}
		if(h != coeffMatrix[i][i]){
			printf("\nDiagonal element is not dominant in row no: %d. \nEnding...", i + 1) ;
			return 0 ;
		}
	}
	// calculation part
	showMatrix(coeffMatrix, n) ;
	for(int i = 0 ; i < n ; i++){
		 double diagCoeff = coeffMatrix[i][i] ;
		if(diagCoeff == 0){
			printf("\nDiagonal coeff found 0 at row %d. Ending...", i + 1) ;
		}
		printf("\nNormalizing row: %d\n", i + 1) ;
		for(j = 0 ; j <=n ; j++){
			coeffMatrix[i][j] /= diagCoeff ;
		}
		showMatrix(coeffMatrix, n) ;
		printf("\nNormalizing Column: %d\n", i + 1) ;
		for(k = 0 ; k < n ; k++){
			if(i == k) continue ;
			 double factor = coeffMatrix[k][i] ;
//			
				printf("\nPerforming R%d = R%d - %f*R%d\n", k+ 1, k+1, factor, i + 1 );
			for(j = 0 ; j <=n ; j++){
//				if(k == j) continue ;
				coeffMatrix[k][j] -= factor * coeffMatrix[i][j] ;
			}
			showMatrix(coeffMatrix, n) ;
		}
	}
	printf("\n: final answer: ") ;
	showMatrix(coeffMatrix, n) ;
	getch();
	
}












