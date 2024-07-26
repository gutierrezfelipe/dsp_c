#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIG_LENGTH 320

extern double InputSignal_f32_1kHz_15kHz[SIG_LENGTH];
double calc_signal_mean(double *sig_src_arr, int sig_length);
double calc_signal_variance(double *sig_src_arr, double sig_mean, int sig_length);
double calc_signal_std_deviation(double sig_variance);
double mean;
double variance;
double std_devation;

int main()
{
    mean = calc_signal_mean(&InputSignal_f32_1kHz_15kHz[0], SIG_LENGTH);
    
    printf("\n\nMean = %f\n\n\n", mean);

    variance = calc_signal_variance(&InputSignal_f32_1kHz_15kHz[0], mean, SIG_LENGTH);

    printf("\n\nVariance = %f\n\n\n", variance);

    std_devation = calc_signal_std_deviation(variance);

    printf("\n\nStandard deviation = %f\n\n\n", std_devation);

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

double calc_signal_std_deviation(double sig_variance)
{
    double _std_dev = sqrt(sig_variance);

    return _std_dev;
}
