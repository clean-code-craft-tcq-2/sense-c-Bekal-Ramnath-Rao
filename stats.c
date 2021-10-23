#include "stats.h"
#include "stdio.h"
#include "math.h"

/* to check whether NAN is defined or not*/
#ifdef NAN
#endif

/* structure to hold minimum and maximum value of an array*/
struct min_max
{
	float min;
	float max;
};

/*function defined to calculate sum*/
float SUM(const float* numberset, int setlength)
{
	float sum = 0;
	int i;

	for(i=0;i<setlength;i++)
	{
		sum = sum + *(numberset + i);
	}

	return sum;
}

/*function defined to calculate average*/
float average_numberset(float sum, int setlength)
{
	return sum/setlength;
}

/*function defined to find out minimum and maximum element in an array */
struct min_max Minimum_Maximum(const float* numberset, int setlength)
{
	struct min_max pair;
	int i=0;

	if(setlength == 1)
	{
		pair.min = *(numberset);
		pair.max = *(numberset);
	}

	if(*(numberset) > *(numberset + 1))
	{
		pair.min = *(numberset + 1);
		pair.max = *(numberset);
	}
	else
	{
		pair.max = *(numberset + 1);
		pair.min = *(numberset);
	}

	for(i=2;i<setlength;i++)
	{
		if(*(numberset + i) > pair.max)
		{
			pair.max = *(numberset + i);
		}
		else if(*(numberset + i) < pair.min)
		{
			pair.min = *(numberset + i);
		}
	}

	return pair;
}

/* function defined to find out average,min and max in an array*/
struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    struct min_max mn_mx;
    float sum=0;

    if(setlength != 0)
    {
	    sum = SUM(numberset,setlength);
	    s.average = average_numberset(sum,setlength);
	    mn_mx = Minimum_Maximum(numberset,setlength);
	    s.min = mn_mx.min;
	    s.max = mn_mx.max;
	}
	else
	{
		s.average = NAN;
		s.min = NAN;
		s.max = NAN;
	}

    return s;
}
