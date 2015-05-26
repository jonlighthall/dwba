// Written by K.G. Leach, June 2011
// Uses the global deuteron set of Han, Shi, and Shen, Phys. Rev. C 74, 044615 (2006)
// Which is rated for 12 < A < 209 and 1 keV < E_t < 200 MeV

#include <stdio.h>

int main()
{
    int a = 0, b = 0, c = 0;
    double E_d = 0.0, r_c = 0.0, V_r = 0.0, r_v = 0.0, a_v = 0.0, W_v = 0.0, r_wv = 0.0, a_wv = 0.0;
    double W_s = 0.0, r_s = 0.0, a_s = 0.0, V_so = 0.0, r_so = 0.0, a_so = 0.0, W_so = 0.0, dummy = 0.0;
 
   printf("\nb** Calculates deuteron OMPs from the Han, Shi, and Shen, Phys. Rev. C 74, 044615 (2006) global parameters **\n");
   printf("** Parameters are rated for 12 < A < 209 and 1 keV < E_t < 200 MeV **\n\n");
   printf("Z of Target:");
   scanf("%d", &a);
   printf("A of Target:");
   scanf("%d", &b);
   printf("Deuteron Energy in MeV:");
   scanf("%lf", &E_d);

//Calculate N of target

   c = b - a;

//Calculate charge radius
   
   r_c = 1.698;

//**Calculate volume terms**

   V_r = 82.18 - 0.148 * E_d - 0.000886 * E_d * E_d - 34.811 * (c - a) / b + 1.058 * a * pow(b, -1 / 3.0);
   r_v = 1.174;
   a_v = 0.809;

   dummy = -4.916 + 0.0555 * E_d + 0.0000442 * E_d * E_d + 35.0 * (c - a) / b;

   if (dummy <= 0.0){
     W_v = 0.0;
   }

   else{
     W_v = dummy;
   }

   r_wv = 1.563;
   a_wv = 0.700 + 0.045 * pow(b, 1 / 3.0);

//**Calculate surface terms**

   W_s = 20.968 - 0.0794 * E_d - 43.398 * (c - a) / b;
   r_s = 1.328;
   a_s = 0.465 + 0.045 * pow(b, 1 / 3.0);

//**Calculate spin-orbit terms**

   V_so = 3.703;
   r_so = 1.234;
   a_so = 0.813;

   W_so = -0.206;

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
   printf("\nImaginary Spin-Orbit Terms\n");
   printf("V_so = %lf  MeV\n", W_so);
   printf("r_so = %lf  fm\n", r_so);
   printf("a_so = %lf  fm\n\n", a_so);
   printf("*********************************\n");

    return 0;

}

