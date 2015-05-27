// Written by K.G. Leach, June 2011
// Uses the global proton set of Koning and Delaroche, Nucl. Phys. A 713, 231-310 (2003)
// Which is rated for 24 < A < 209 and 1 keV < E_p < 200 MeV

#include <stdio.h>
#include <math.h> //added

int main()
{
    int a = 0, b = 0, c = 0;
    double v_1 = 0.0, v_2 = 0.0, v_3 = 0.0, v_4 = 0.0, w_1 = 0.0, w_2 = 0.0;
    double d_1 = 0.0, d_2 = 0.0, d_3 = 0.0, vso_1 = 0.0, vso_2 = 0.0, wso_1 = 0.0, wso_2 = 0.0;
    double E_p = 0.0, E_f = 0.0, r_c = 0.0, V_c = 0.0, V_r = 0.0, r_v = 0.0, a_v = 0.0, W_v = 0.0, r_wv = 0.0, a_wv = 0.0;
    double W_s = 0.0, r_s = 0.0, a_s = 0.0, V_so = 0.0, W_so = 0.0, r_so = 0.0, a_so = 0.0;
 
   printf("\n** Calculates proton OMPs from the Koning and Delaroche, Nucl. Phys. A 713, 231-310 (2003) global parameters **\n");
   printf("** Parameters are rated for 24 < A < 209 and 1 keV < E_p < 200 MeV **\n\n");
   printf("Z of Target:");
   scanf("%d", &a);
   printf("A of Target:");
   scanf("%d", &b);
   printf("Proton Energy in MeV:");
   scanf("%lf", &E_p);

//Calculate N of target

   c = b - a;

//Calculate the Fermi Energy

   E_f = -8.4075 + 0.01378 * b;

//Calculate charge radius

   r_c = 1.198 + 0.697 * pow(b, -2.0/3.0) + 12.994 * pow(b, -5.0/3.0) ;

//Calculate Coulomb potential averaged over radial coordinates

   V_c = 1.73 / r_c * a * pow(b, -1.0/3.0);

//Calculate the many parameters involved in the various potential parameters

   v_1 = 59.30 + 21.0 * (c - a) / b - 0.024 * b;
   v_2 = 0.007067 + 4.23e-6 * b;
   v_3 = 1.729e-5 + 1.136e-8 * b;
   v_4 = 7.00e-9;

   w_1 = 14.667 + 0.009629 * b;
   w_2 = 73.55 + 0.0795 * b;

   d_1 = 16.0 + 16.0 * (c - a) / b;
   d_2 = 0.0180 + 0.003802 / (1 + exp((b - 156.0 ) / 8.0));
   d_3 = 11.5;

   vso_1 = 5.922 + 0.0030 * b;
   vso_2 = 0.0040;

   wso_1 = -3.1;
   wso_2 = 160.0;

//**Calculate volume terms**

   V_r = v_1 * (1 - v_2 * (E_p - E_f) + v_3 * (E_p - E_f) * (E_p - E_f) - v_4 * (E_p - E_f) * (E_p - E_f) * (E_p - E_f)) + V_c * v_1 * (v_2 - 2 * v_3 * (E_p - E_f) - 3 * v_4 * (E_p - E_f) * (E_p - E_f));
   r_v = 1.3039 - 0.4054 * pow(b, -1.0/3.0);
   a_v = 0.6778 - 1.487e-4 * b;

   W_v = w_1 * ((E_p - E_f) * (E_p - E_f) / ((E_p - E_f) * (E_p - E_f) + w_2 * w_2));
   r_wv = r_v;
   a_wv = a_v;

//**Calculate surface terms**

   W_s = d_1 * ((E_p - E_f) * (E_p - E_f) / ((E_p - E_f) * (E_p - E_f) + d_2 * d_2)) * exp(-d_2 * (E_p - E_f));
   r_s = 1.3424 - 0.01585 * pow(b, 1.0/3.0);
   a_s = 0.5187 + 5.205e-4 * b;

//**Calculate spin-orbit terms**

   V_so = vso_1 * exp(-vso_2 * (E_p - E_f));
   W_so = wso_1 * ((E_p - E_f) * (E_p - E_f) / ((E_p - E_f) * (E_p - E_f) + wso_2 * wso_2));
   r_so = 1.1854 - 0.647 * pow(b, -1.0/3.0);
   a_so = 0.59;   

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
   printf("a_so = %lf  fm\n", a_so);
   printf("\nImaginary Spin-Orbit Terms\n");
   printf("W_so = %lf  MeV\n", W_so);
   printf("r_so = %lf  fm\n", r_so);
   printf("a_so = %lf  fm\n\n", a_so);
   printf("*********************************\n");

   //added below for PTOLEMY
   printf("*********************************\n\n");
   printf("Here are the requested parameters:\nFormatted for PTOLEMY\n");
   printf("$Proton potential calculated for A=%d Z=%d E_p=%f\n",a,b,E_p);   
   printf("$Charge Radius\n");
   printf("RC0 = %lf\n", r_c);
   printf("$Real Volume Terms\n");
   printf("V = %lf\n", V_r);
   printf("R0 = %lf\n", r_v);
   printf("A = %lf\n", a_v);
   printf("$Imaginary Volume Terms\n");
   printf("VI = %lf\n", W_v);
   printf("RI0 = %lf\n", r_wv);
   printf("AI = %lf\n", a_wv);
   printf("$Imaginary Surface Terms\n");
   printf("VSI = %lf\n", W_s);
   printf("RSI0 = %lf\n", r_s);
   printf("ASI= %lf\n", a_s);
   printf("$Real Spin-Orbit Terms\n");
   printf("VSO = %lf\n", V_so);
   printf("RSO0 = %lf\n", r_so);
   printf("ASO = %lf\n", a_so);
   printf("$Imaginary Spin-Orbit Terms\n");
   printf("VSOI = %lf\n", W_so);
   printf("RSOI0 = %lf\n", r_so);
   printf("ASOI = %lf\n\n", a_so);
   printf("*********************************\n");

    return 0;

}

