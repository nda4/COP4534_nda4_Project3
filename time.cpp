#include "time.hpp"

void Time::bruteStart(Matrix matrix, int value)
{
    struct timeval *t;
    struct timezone *z;

    t = (struct timeval *)malloc(sizeof(struct timeval));
    z = (struct timezone *)malloc(sizeof(struct timezone));

    int startsec, endsec, startmil, endmil;
    gettimeofday(t, z);
    startsec = int(t->tv_sec);
    startmil = int(t->tv_usec);
    BruteForce BF(&matrix, value);
    bruteValue = BF.bestCase;
    gettimeofday(t, z);
    endsec = int(t->tv_sec);
    endmil = int(t->tv_usec);
    std::cout << "\n\nBrute Force Algorithm Time: "
              << endsec - startsec << " SECONDS\n\n";
};

void Time::geneticStart(Matrix matrix, int value, int numTours, int numGens, double percMut)
{
    struct timeval *t;
    struct timezone *z;

    t = (struct timeval *)malloc(sizeof(struct timeval));
    z = (struct timezone *)malloc(sizeof(struct timezone));

    int startsec, endsec, startmil, endmil;
    gettimeofday(t, z);
    startsec = int(t->tv_sec);
    startmil = int(t->tv_usec);
    Genetic g(&matrix, value, numTours, numGens, percMut);
    geneticValue = g.bestCase;
    gettimeofday(t, z);
    endsec = int(t->tv_sec);
    endmil = int(t->tv_usec);
    std::cout << "\n\nGenetic Algorithm Time: "
              << endsec - startsec << " SECONDS\n\n";
};
