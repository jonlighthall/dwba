// Written by K.G. Leach, June 2011
// Uses the global triton set of Perey and Perey Atomic Data and Nuclear Data Tables, Vol. 17, No. 1, January 1976
// Which is rated for A > 40 and 1 keV < E_t < 40 MeV

#include <stdio.h>

int main()
{
    int a = 0, b = 0, c = 0;
    double E_t = 0.0, r_c = 0.0, V_r = 0.0, r_v = 0.0, a_v = 0.0;
    double W_s = 0.0, r_s = 0.0, a_s = 0.0, V_so = 0.0, r_so = 0.0, a_so = 0.0;
 
   printf("\n** Calculates triton OMPs from the Perey and Perey Atomic Data and Nuclear Data Tables 17, 1 (1976) global parameters **\n");
   printf("** Parameters are rated for 48 < A < 232 and 1 keV < E_t < 40 MeV **\n\n");
   printf("Z of Target:");
   scanf("%d", &a);
   printf("A of Target:");
   scanf("%d", &b);
   printf("Triton Energy in MeV:");
   scanf("%lf", &E_t);

//Calculate N of target

   c = b - a;

//Calculate charge radius
   
   r_c = 1.300;

//**Calculate volume terms**

   V_r = 165.0 - 0.17 * E_t - 6.4 * (c - a) / b;
   r_v = 1.20;
   a_v = 0.72;

//**Calculate surface terms**

   W_s = 46.0 - 0.33 * E_t - 110 * (c - a) / b;
   r_s = 1.40;
   a_s = 0.840;

//**Calculate spin-orbit terms**

   V_so = 2.500;
   r_so = 1.20;
   a_so = 0.720;


//**Print Out Values**//

   printf("*********************************\n\n");
   printf("Here are the requested parameters:\n\n");
   printf("Charge Radius\n");
   printf("r_c = %lf  fm\n", r_c);
   printf("\nReal Volume Terms\n");
   printf("V_v = %lf  MeV\n", V_r);
   printf("r_v = %lf  fm\n", r_v);
   printf("a_v = %lf  fm\n", a_v);
   printf("\nImaginary Surface Terms\n");
   printf("W_s = %lf  MeV --> 4*W_s = %lf  MeV\n", W_s, 4 * W_s);
   printf("r_s = %lf  fm\n", r_s);
   printf("a_s = %lf  fm\n", a_s);
   printf("\nReal Spin-Orbit Terms\n");
   printf("V_so = %lf  MeV\n", V_so);
   printf("r_so = %lf  fm\n", r_so);
   printf("a_so = %lf  fm\n\n", a_so);
   printf("*********************************\n");

    return 0;

}

