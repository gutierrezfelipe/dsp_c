#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIG_LENGTH 320



extern double InputSignal_f32_1kHz_15kHz[SIG_LENGTH];
double Output_signal[SIG_LENGTH];

int main()
{
    FILE *input_sig_fptr, *out_fptr;

    input_sig_fptr = fopen("input_sig.dat", "w");

    for(int i=0;i<SIG_LENGTH;i++)
    {
        fprintf(input_sig_fptr, "\n%f", InputSignal_f32_1kHz_15kHz[i]);
    }

    fclose(input_sig_fptr);

    

    out_fptr = fopen("rs_output_sig.dat", "w");

    for(int i=0; i<SIG_LENGTH; i++)
    {
        fprintf(out_fptr, "\n%f", Output_signal[i]);
    }

    fclose(out_fptr);


    return 0;
}



