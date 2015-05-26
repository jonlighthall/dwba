// Written by K.G. Leach, June 2011
// Uses the global triton set of Li, Liang, and Cai Nuclear Physics A 789, 103 (2007)
// Which is rated for 48 < A < 232 and 1 keV < E_t < 40 MeV

#include <stdio.h>

int main()
{
    int a = 0, b = 0, c = 0;
    double E_t = 0.0, r_c = 0.0, V_r = 0.0, r_v = 0.0, a_v = 0.0, W_v = 0.0, r_wv = 0.0, a_wv = 0.0;
    double W_s = 0.0, r_s = 0.0, a_s = 0.0, V_so = 0.0, r_so = 0.0, a_so = 0.0;
 
   printf("\nb** Calculates triton OMPs from the Li, Liang, and Cai Nuclear Physics A 789, 103 (2007) global parameters **\n");
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
   
   r_c = 1.4219;

//**Calculate volume terms**

   V_r = 137.6 - 0.1456 * E_t + 0.0436 * E_t * E_t + 4.3751 * (c - a) / b + 1.0474 * b / pow(a, 1/3.0);
   r_v = 1.1201 - 0.1504 * pow(b, -1/3.0);
   a_v = 0.6833 + 0.0191 * pow(b, 1/3.0);

   W_v = 7.383 + 0.5025 * E_t - 0.0097 * E_t * E_t;
   r_wv = 1.3202 - 0.1776 * pow(b, -1/3.0);
   a_wv = 1.119 + 0.01913 * pow(b, 1/3.0);

//**Calculate surface terms**

   W_s = 37.06 - 0.6451 * E_t - 47.19 * (c - a) / b;
   r_s = 1.251 - 0.4622 * pow(b, -1/3.0);
   a_s = 0.8114 + 0.01159 * pow(b, 1/3.0);

//**Calculate spin-orbit terms**

   V_so = 1.9029;
   r_so = 0.46991 + 0.1294 * pow(b, -1/3.0);
   a_so = 0.3545 - 0.0522 * pow(b, 1/3.0);


//**Print Out Values**//

   printf("*********************************\n\n");
   printf("Here are the requested parameters:\n\n");
   printf("Charge Radius\n");
   printf("r_c = %lf  fm\n", r_c);
   printf("\nReal Volume Terms\n");
   printf("V_v = %lf  MeV\n", V_r);
   printf("r_v = %lf  fm\n", r_v);
   printf("a_v = %lf  fm\n", a_v);
   printf("\nImaginary Volume Terms\n");
   printf("W_v = %lf  MeV\n", W_v);
   printf("r_w = %lf  fm\n", r_wv);
   printf("a_w = %lf  fm\n", a_wv);
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

