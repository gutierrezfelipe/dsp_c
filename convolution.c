#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIG_LENGTH 320
#define IR_LENGTH 29

void calc_convolution(double *arr_1, double *arr_2, double *result_arr, 
                        int arr_1_len, int arr_2_len);

extern double InputSignal_f32_1kHz_15kHz[SIG_LENGTH];
extern double  Impulse_response[IR_LENGTH];
double Output_signal[SIG_LENGTH+IR_LENGTH];

int main()
{
    FILE *input_sig_fptr, *ir_fptr, *out_fptr;

    input_sig_fptr = fopen("input_sig.dat", "w");
    ir_fptr = fopen("ir.dat", "w");

    for(int i=0;i<SIG_LENGTH;i++)
    {
        fprintf(input_sig_fptr, "\n%f", InputSignal_f32_1kHz_15kHz[i]);
    }

    fclose(input_sig_fptr);

    for(int i=0; i<IR_LENGTH;i++)
    {
        fprintf(ir_fptr, "\n%f", Impulse_response[i]);
    }

    fclose(ir_fptr);

    calc_convolution(&InputSignal_f32_1kHz_15kHz[0], 
                    &Impulse_response[0], 
                    &Output_signal[0], 
                    SIG_LENGTH, IR_LENGTH);


    out_fptr = fopen("conv_output_sig.dat", "w");

    for(int i=0; i<SIG_LENGTH+IR_LENGTH; i++)
    {
        fprintf(out_fptr, "\n%f", Output_signal[i]);
    }

    fclose(out_fptr);


    return 0;
}


void calc_convolution(double *arr_1, double *arr_2, double *result_arr, 
                        int arr_1_len, int arr_2_len)
{
    int result_size = arr_1_len + arr_2_len;
    
    for(int i=0;i<result_size;i++)
    {
        result_arr[i] = 0.0;
    }

    for(int i = 0; i < result_size; i++)
    {
        for (int j = 0; j < arr_2_len; j++)
        {
            result_arr[i] += arr_2[j] * arr_1[i - j];
        }
    }

    
}

