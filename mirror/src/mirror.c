#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int prime(long long n){
    long long divisor;
    int is_prime = 1;
	if((n != 2 && n % 2 == 0) || (n != 3 && n % 3 == 0)){
		is_prime = 0;
	}
	else {
		for (divisor = 5; divisor * divisor <= n ; divisor += 6){
			if(n % divisor == 0 || n % (divisor + 2) == 0){
				is_prime = 0;
				break;
			}
		}
	}
    return is_prime;
}

long long flip(long long n){
    long long remain, rever = 0;
    while (n != 0){
        remain = n % 10;
        rever = rever * 10 + remain;
        n /= 10 ;
    }
    return rever;
}


int main (int argc, char *argv[]){ // takes arguments from the command line
    if (argc == 3){
        long long low = atoll(argv[1]);  // low : lower limit of number range
        long long high = atoll(argv[2]); // high : high limit of number range
        if (low <= high && low >= 1 && high <= 1000000000000000){
            long long sum = 0;
            long long x = sqrt(low);
            while (x*x <= high ){
                if (prime(x)){
                    long long n1 = x*x;
                    long long n2 = flip(n1);
                    if (n1 != n2){
                        long long temp = sqrt(n2);
                        if (temp * temp == n2){
                            if (prime(temp)){
                                sum += n1;
                            }
                        }
                    }
                }
                x++;
            }
            printf("%lld \n", sum);
        }
        else 
            return 1;   
    }
}

