#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gsl/gsl_randist.h>
#include <gsl/gsl_cdf.h>


/*
 * Compute the p-value of random variable that
 * follows a binary distribution.
 *
 * See Wolfram's binomial distribution discussion:
 * http://mathworld.wolfram.com/BinomialDistribution.html
 *
 */

int usage(char **argv){
	printf("Usage: %s WHITE_FREQ WHITE_BALLS TOTAL_BALLS\n", argv[0]);
	printf("WHITE_FREQ = background frequency of white balls\n");
	printf("WHITE_BALLS = number of white balls picked out\n");
	printf("TOTAL_BALLS = number of total balls picked out\n");
}

double exactPval(int k, double p, int N){
	int i;
	double pval=0.0;
	for (i=k ; i<=N ; i++){
		pval += gsl_ran_binomial_pdf (i, p, N);
	}
	return pval;
}

double approxPval (int k, double p, int N){
	double mean=0.0;
	double stdev=0.0;
	mean = p * N;
	stdev = sqrt((double)N * p * ((double)1-p));
	return gsl_cdf_gaussian_Q (k-1.0-mean, stdev);
}

int 
main(int argc, char **argv){
	double p;
	double pval=0.0;
	double prob=0.0;
	int i;
	int white;
	int total;
	if(argc != 4){
		usage(argv);
		exit(1);
	}
	p = atof(argv[1]);
	white = atoi(argv[2]);
	total = atoi(argv[3]);
	if(total < white){
		printf("Error: Total number of balls is less than\n");
		printf("number of white balls.  Quitting!\n");
		exit(0);
	}

	if(total > 20 && p > 0.05 && p < 0.95){
		pval = approxPval(white, p, total);
	}else{
		pval = exactPval(white, p, total);
	}
	printf("%e\n", pval);
	return 1;
}
