// Written by K.G. Leach, June 2011
// Uses the global deuteron set of Perey and Perey Atomic Data and Nuclear Data Tables, Vol. 17, No. 1, January 1976
// Which is rated for A > 40 and 12 < E_d < 25 MeV

#include <stdio.h>

int main()
{
    int a = 0, b = 0, c = 0;
    double E_d = 0.0, r_c = 0.0, V_r = 0.0, r_v = 0.0, a_v = 0.0;
    double W_s = 0.0, r_s = 0.0, a_s = 0.0, V_so = 0.0, r_so = 0.0, a_so = 0.0;
 
   printf("\n** Calculates deuteron OMPs from the Perey and Perey Atomic Data and Nuclear Data Tables 17, 1 (1976) global parameters **\n");
   printf("** Parameters are rated for A > 40 and 12 < E_d < 25 MeV **\n\n");
   printf("Z of Target:");
   scanf("%d", &a);
   printf("A of Target:");
   scanf("%d", &b);
   printf("Deuteron Energy in MeV:");
   scanf("%lf", &E_d);

//Calculate N of target

   c = b - a;

//Calculate charge radius
   
   r_c = 1.150;

//**Calculate volume terms**

   V_r = 81.0 - 0.22 * E_d + 2.0 * (a * pow(b, -1.0/3));
   r_v = 1.15;
   a_v = 0.81;

//**Calculate surface terms**

   W_s = 14.4 + 0.24 * E_d;
   r_s = 1.34;
   a_s = 0.68;

//**Calculate spin-orbit terms (From set for 8-13 MeV)**

   V_so = 7.00;
   r_so = 0.750;
   a_so = 0.500;


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

