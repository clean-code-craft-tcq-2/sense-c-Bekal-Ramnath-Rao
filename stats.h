#ifndef STATS_H
#define STATS_H
/* function declared to find out average,min and max of an array*/
struct Stats compute_statistics(const float* numberset, int setlength);

/* structure used to hold avrage,min and max of an array*/
struct Stats{
    float average;
    float min;
    float max;
};

#endif
