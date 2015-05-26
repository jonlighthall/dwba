// Written by K.G. Leach, June 2011
// Uses the global deuteron set of An and Cai Phys. Rev. C 73, 054605 (2006)
// Which is rated for 12 < A < 238 and 1 keV < E_t < 183 MeV

#include <stdio.h>
#include <math.h>

int main()
{
    int a = 0, b = 0, c = 0;
    double E_d = 0.0, r_c = 0.0, V_r = 0.0, r_v = 0.0, a_v = 0.0, W_v = 0.0, r_wv = 0.0, a_wv = 0.0;
    double W_s = 0.0, r_s = 0.0, a_s = 0.0, V_so = 0.0, r_so = 0.0, a_so = 0.0;
 
   printf("\n** Calculates deuteron OMPs from the An and Cai Phys. Rev. C 73, 054605 (2006) global parameters **\n");
   printf("** Parameters are rated for 2 < A < 238 and 1 keV < E_t < 183 MeV **\n\n");
   printf("Z of Target:");
   scanf("%d", &a);
   printf("A of Target:");
   scanf("%d", &b);
   printf("Deuteron Energy in MeV:");
   scanf("%lf", &E_d);

//Calculate N of target

   c = b - a;

//Calculate charge radius
   
   r_c = 1.303;

//**Calculate volume terms**

   V_r = 91.85 - 0.249 * E_d + 0.000116 * E_d * E_d + 0.642 * a * pow(b, -1/3.0);
   r_v = 1.152 - 0.00776 * pow(b, -1/3.0);
   a_v = 0.719 + 0.0126 * pow(b, 1/3.0);

   W_v = 1.104 + 0.0622 * E_d;
   r_wv = 1.305 + 0.0997 * pow(b, -1/3.0);
   a_wv = 0.855 - 0.100 * pow(b, 1/3.0);

//**Calculate surface terms**

   W_s = 10.83 - 0.0306 * E_d;
   r_s = 1.334 + 0.152 * pow(b, -1/3.0);
   a_s = 0.531 + 0.062 * pow(b, 1/3.0);

//**Calculate spin-orbit terms**

   V_so = 3.557;
   r_so = 0.972;
   a_so = 1.011;


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

