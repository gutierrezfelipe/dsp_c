#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIG_LENGTH 320

void calc_running_sum(double *sig_src_arr, double *sig_out_arr, int sig_length);

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

    calc_running_sum(&InputSignal_f32_1kHz_15kHz[0], &Output_signal[0], SIG_LENGTH);

    out_fptr = fopen("rs_output_sig.dat", "w");

    for(int i=0; i<SIG_LENGTH; i++)
    {
        fprintf(out_fptr, "\n%f", Output_signal[i]);
    }

    fclose(out_fptr);


    return 0;
}

void calc_running_sum(double *sig_src_arr, double *sig_out_arr, int sig_length)
{
    for(int i=0; i<sig_length; i++)
    {
        sig_out_arr[i] = sig_out_arr[i-1] + sig_src_arr[i];
    }
}


