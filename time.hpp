#ifndef TIME_HPP
#define TIME_HPP
#include <sys/time.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h> /*  for malloc */
#include <unistd.h> // for sleep()
#include "bruteForce.hpp"
#include "genetic.hpp"


class Time{
    public:
        double bruteValue, geneticValue;
        void bruteStart(Matrix matrix, int value);
        void geneticStart(Matrix matrix, int value, int numTours, int numGens, double percMut);
};




#endif