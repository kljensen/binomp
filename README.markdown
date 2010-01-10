# Computing p-values for binomial distributions

This program computes [p-values](http://en.wikipedia.org/wiki/P-value) for random variables that follow a [binomial distribution](http://en.wikipedia.org/wiki/Binomial_distribution).  For example, say you had a bucket with 60% blackballs and 40% white balls.  This code will help you answer questions like: what is the probability of reaching into the bucket and pulling out 100 balls and having 65 or more of them be white, etc.

The code uses an exact calculation for small numbers and an approximation for larger numbers.  See the discussion of the [binomial distribution on Wolfram's web site](http://mathworld.wolfram.com/BinomialDistribution.html) for more details.  The only dependency is the [GNU Scientific Library](http://www.gnu.org/software/gsl/).

Kyle  
<kljensen@gmail.com>
