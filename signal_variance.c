#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIG_LENGTH 320

extern double InputSignal_f32_1kHz_15kHz[SIG_LENGTH];
double calc_signal_mean(double *sig_src_arr, int sig_length);
double calc_signal_variance(double *sig_src_arr, double sig_mean, int sig_length);
double mean;
double variance;

int main()
{
    mean = calc_signal_mean(&InputSignal_f32_1kHz_15kHz[0], SIG_LENGTH);
    
    printf("\n\nMean = %f\n\n\n", mean);

    variance = calc_signal_variance(&InputSignal_f32_1kHz_15kHz[0], mean, SIG_LENGTH);

    printf("\n\nVariance = %f\n\n\n", variance);

    return 0;
}

double calc_signal_mean(double *sig_src_arr, int sig_length)
{
    double _mean = 0.0;

    for(int i = 0; i < sig_length; i++)
    {
        _mean += sig_src_arr[i];
    }

    _mean = _mean / (double) sig_length;

    return _mean; 
}

double calc_signal_variance(double *sig_src_arr, double sig_mean, int sig_length)
{
    double _variance = 0.0;

    for(int i = 0; i < sig_length; i++)
    {
        _variance += pow((sig_src_arr[i] - sig_mean), 2);
    }

    _variance = _variance / (double)(sig_length - 1);

    return _variance;
}