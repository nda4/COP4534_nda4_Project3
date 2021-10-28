#include "time.hpp"



int main(){
    int numCities, numGens, numTours;
    double percentMut;
    Matrix matrix;

    std::cout <<"Please Enter the number of Cities: ";
    std::cin >> numCities;
    std::cout <<"\nPlease Enter the number of Generations: ";
    std::cin >> numGens;
    std::cout << "\nPlease Enter the number of Tours per generation: ";
    std::cin >> numTours;
    std::cout << "\nPlease Enter the percent of values to be Mutations (.1 -> .9): ";
    std::cin >> percentMut;
    std::cout << "\n--------------------\n\n";

    Time timer;
    timer.bruteStart(matrix, numCities);
    timer.geneticStart(matrix, numCities, numGens, numTours, percentMut);
    
    std::cout << "\nPercent Optimal: " << (timer.geneticValue/timer.bruteValue) * 100 << "%\n\n";

    return 0;
    
}