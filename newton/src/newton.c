#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// function that calculates the value of the polynomial
double f(double a0,double a1,double a2,double a3,double a4,double a5,double x0){
    return a0 + a1*x0 + a2*pow(x0, 2) + a3*pow(x0, 3) + a4*pow(x0, 4) + a5*pow(x0, 5);
}

// function that calculates the value of the derivative of the polynomial
 double fparagwgos(double a1,double a2,double a3,double a4,double a5,double x0){
    return a1 + 2*a2*x0 + 3*a3*pow(x0, 2) + 4*a4*pow(x0, 3) + 5*a5*pow(x0, 4);
}

int main(int argc, char *argv[]){
    if (argc != 8){ // check if the correct amount of arguments is provided
        return 1;
    }
    double a0 = strtod(argv[1] , NULL );
    double a1 = strtod(argv[2] , NULL );
    double a2 = strtod(argv[3] , NULL );
    double a3 = strtod(argv[4] , NULL );
    double a4 = strtod(argv[5] , NULL );
    double a5 = strtod(argv[6] , NULL );
    double x0 = strtod(argv[7] , NULL );
    double xn;
    int i = 0;
    while (i <= 999){ // checks if the number of repetitions is grater than 1000
        xn = x0 - f(a0, a1, a2, a3, a4, a5, x0)/fparagwgos(a1, a2, a3, a4, a5, x0); // check the division by 0
        if (fparagwgos (a1, a2, a3, a4, a5, x0) == 0){ // checks if fparagwgos is 0 beacause we cant divide by 0
            printf("nan\n");
            return 0;
        }
        if (fabs(xn - x0) < 0.000001){ // checks if |xn+1 - xn| < 10^-6
            printf("%.2f\n", xn); // print the result with two decimal 
            return 0;
        }
        x0 = xn; // update x0
        i++;
    }
    printf("incomplete\n"); // if the did not finish within 1000 repetitions
    return 0;

}
