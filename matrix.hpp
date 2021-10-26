#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <iostream>
#include <fstream>


class Matrix{
    public:
    double matrix[20][20] = {};
    int numEdge;
    Matrix();
    Matrix(std::string filename, int numNodes);

    private:
    void readFile(std::string filename);    

    void printMatrix();

};




#endif