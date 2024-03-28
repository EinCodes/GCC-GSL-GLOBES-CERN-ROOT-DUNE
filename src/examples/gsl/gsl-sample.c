#include <stdio.h>
#include <gsl/gsl_sf_bessel.h>

int main(void)
{
    printf("\n# ---------------------------------- #\n");
    printf("Starting GSL Sample Code \n");

    double x = 5.0;
    double y = gsl_sf_bessel_J0(x);

    printf("J0(%g) = %.18e\n\n", x, y);

    printf("GSL Working\n");
    printf("\n# ---------------------------------- #\n");
    
    return 0;
}