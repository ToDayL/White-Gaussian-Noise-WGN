

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <fstream>
//v is the mean of noise and sigma is the standard deviation of noise
double WGN(double v,double sigma)
{
	double rn1 = rand()*(1. / RAND_MAX);
	double rn2 = rand()*(1. / RAND_MAX);
	double R = sqrt(-2. * log(rn2));
	double theta = 2 * 3.14159265 * rn1;
	double Z = R*cos(theta);
	double x = v + Z * sigma;
	return x;
}

int main()
{
	srand((unsigned)(time(NULL)));
	//std::cout << WGN(1) << std::endl;
	std::ofstream os;
	os.open("noise.txt");
	for (int i = 0; i < 10000; i++)
	{
		os << WGN(3,1) << std::endl;
	}
	os.close();
	return 0;
}