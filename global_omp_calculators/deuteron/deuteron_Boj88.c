// Written by K.G. Leach, June 2011
// Uses the global deuteron set of J. Bojowald, H. Machner, H. Nann, W. Oelert, M. Rogge, and P. Turek Phys. Rev. C 38, 1153 (1988)
// Which is rated for 27 < A < 208 and 1 keV < E_t < 100 MeV

#include <stdio.h>

int main()
{
    int a = 0, b = 0, c = 0;
    double E_d = 0.0, r_c = 0.0, V_r = 0.0, r_v = 0.0, a_v = 0.0, W_v = 0.0, r_wv = 0.0, a_wv = 0.0;
    double W_s = 0.0, r_s = 0.0, a_s = 0.0, V_so = 0.0, r_so = 0.0, a_so = 0.0, dummy = 0.0;
 
   printf("\n** Calculates deuteron OMPs from the J. Bojowald, H. Machner, H. Nann, W. Oelert, M. Rogge, and P. Turek Phys. Rev. C 38, 1153 (1988) global parameters **\n");
   printf("** Parameters are rated for 27 < A < 208 and 1 keV < E_t < 100 MeV **\n\n");
   printf("Z of Target:");
   scanf("%d", &a);
   printf("A of Target:");
   scanf("%d", &b);
   printf("Deuteron Energy in MeV:");
   scanf("%lf", &E_d);

//Calculate N of target

   c = b - a;

//Calculate charge radius
   
   r_c = 1.300;

//**Calculate volume terms**

   V_r = 81.31 + 1.43 * a * pow(b, -1 / 3.0) - 0.24 * E_d;
   r_v = 1.18;
   a_v = 0.636 + 0.035 * pow(b, 1 / 3.0);

   if (E_d > 44.9){
    W_v = 0.132 * (E_d - 45.0);
   }

   else{
    W_v = 0;
   }

//**Calculate surface terms**

   dummy = 7.80 + 1.04 * pow(b, 1 / 3.0) - 0.712 * W_v;

   if (dummy < 0){
     W_s = 0;
   }

   else{
     W_s = dummy;
   }

   r_s = 1.27;
   a_s = 0.768 + 0.021 * pow(b, 1 / 3.0);

//**Calculate spin-orbit terms**

   V_so = 6.0;
   r_so = 0.78 + 0.038 * pow(b, 1 / 3.0);
   a_so = 0.78 + 0.038 * pow(b, 1 / 3.0);


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
   printf("r_w = %lf  fm\n", r_v);
   printf("a_w = %lf  fm\n", a_v);
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

