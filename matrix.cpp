#include "matrix.hpp"


Matrix::Matrix(){
    this->numEdge = 400;
    readFile("distances.txt");
    printMatrix();
}

Matrix::Matrix(std::string filename, int numCities){
    this->numEdge = (numCities/20) + 20;
    readFile(filename);
}

void Matrix::readFile(std::string filename){
    std::ifstream is;
    is.open(filename);
    int count = 0;
    double value;

    int row = 0;
    int f = 0;
    while(row != 20){
        f = 0;
        for(int col = 0; col < 19; col++){
            is >> value;
            if(row == col){
                matrix[row][col] = 0;
                f++;
                // std::cout << f <<" <<< F\n\n";
            }   
            matrix[row][col + f] = value;
            count++;
        }
        row++;
    }
    std::cout << count << std::endl;
}


void Matrix::printMatrix(){
    int count = 0;
    for(int row = 0; row < (numEdge/20); row++){
        for(int col = 0; col < (numEdge/20); col++){
            std::cout << "| " << matrix[row][col] << " ";
        }
        std::cout << "|\n\n";
       }
}