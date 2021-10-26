#ifndef BRUTE_FORCE_HPP
#define BRUTE_FORCE_HPP
#include "matrix.hpp"




class BruteForce{
    public: 
    BruteForce(Matrix *matrix, int numCities);

    private:
    int NUMELEMENTS;
    int *s;
    void perm1(int permsThisCall);
    Matrix *matrix;
    double bestCase;
    double getBestCase();
    void printS();
    void swap(int element, int element2);
};







#endif