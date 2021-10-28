#ifndef GENETIC_HPP
#define GENETIC_HPP
#include "matrix.hpp"
#include <random>

class Genetic
{
private:
    int NUMELEMENTS;
    int *s, *mutation;
    void perm1(int permsThisCall);
    Matrix *matrix;
    
    double getBestCase(int numTours, int numGens, double percMut);
    void printS();
    void swap(int element, int element2);
    void permMut(int permsThisCall);
    void mutate(int num1, int num2);

public:
    double bestCase;
    Genetic(Matrix *matrix, int numCities, int numTours, int numGens, double percMut);
};

#endif