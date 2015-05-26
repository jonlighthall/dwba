// Written by K.G. Leach, June 2011
// Uses the global triton set of PANG, ROUSSEL-CHOMAZ, SAVAJOLS, VARNER, AND WOLSKI PRC 79, 024615 (2009)
// Which is rated for 6 < A < 232 and 4 < E_t < 450 MeV

#include <stdio.h>

int main()
{
    int a = 0, b = 0, c = 0;
    double E_t = 0.0, R_c = 0.0, E_c = 0.0, V_r = 0.0, R_v = 0.0, a_v = 0.0, W_v = 0.0, R_wv = 0.0, a_wv = 0.0, W_s = 0.0;
 
   printf("\n** Calculates triton OMPs from the PANG, ROUSSEL-CHOMAZ, SAVAJOLS, VARNER, AND WOLSKI PRC 79, 024615 (2009) global parameters **\n");
   printf("** Parameters are rated for 6 < A < 232 and 4 < E_t < 450 MeV **\n\n");
   printf("Z of Target:");
   scanf("%d", &a);
   printf("A of Target:");
   scanf("%d", &b);
   printf("Triton Energy in MeV:");
   scanf("%lf", &E_t);

//Calculate N of target

   c = b - a;

//Calculate charge radius
   
   R_c = 1.24 * pow(b, 1/3.0) + 0.12;

//Calculate Coulomb correction energy
  
   E_c = (6 * a) / (5 * R_c);

//**Calculate volume terms**

   V_r = 118.30 + (-0.13) * (E_t - E_c);
   R_v = 1.30 * pow(b, 1/3.0) - 0.48;
   a_v = 0.820;

   W_v = 38.50 / (1 + exp((156.1 - (E_t - E_c)) / 52.40));
   R_wv = 1.31 * pow(b, 1/3.0) - 0.13;
   a_wv = 0.840;

//**Calculate surface terms (all are the same as volume except depth)**

   W_s = (35.0 - 34.2 * (c - a)/b) / (1 + exp(((E_t - E_c) - 30.8) / 106.4));

//**Print Out Values**//

   printf("*********************************\n\n");
   printf("Here are the requested parameters:\n\n");
   printf("Charge Radius\n");
   printf("r_c = %lf  fm\n", R_c / pow(b, 1/3.0));
   printf("\nReal Volume Terms\n");
   printf("V_v = %lf  MeV\n", V_r);
   printf("r_v = %lf  fm\n", R_v / pow(b, 1/3.0));
   printf("a_v = %lf  fm\n", a_v);
   printf("\nImaginary Volume Terms\n");
   printf("W_v = %lf  MeV\n", W_v);
   printf("r_w = %lf  fm\n", R_wv / pow(b, 1/3.0));
   printf("a_w = %lf  fm\n", a_wv);
   printf("\nImaginary Surface Terms\n");
   printf("W_s = %lf  MeV --> 4*W_s = %lf  MeV\n", W_s, 4 * W_s);
   printf("r_s = %lf  fm\n", R_wv / pow(b, 1/3.0));
   printf("a_s = %lf  fm\n\n", a_wv);
   printf("*********************************\n");

    return 0;

}

