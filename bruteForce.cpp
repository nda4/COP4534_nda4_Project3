#include "bruteForce.hpp"

void BruteForce::swap(int num1, int num2){
  int temp = s[num1];
  s[num1] = s[num2];
  s[num2] = temp;
  s[this->NUMELEMENTS] = s[0];
}

void BruteForce::printS(){
  std::cout << std::endl;
  for(int i = 0; i < this->NUMELEMENTS + 1; i++){
    std::cout << this->s[i] << "\t";
  }
  std::cout << "\n\n";
}

void BruteForce::perm1(int permsThisCall) 
  {
     int m, k, p , q, i;
    //  printS();
     for(i = 1; i < permsThisCall; i++)
     {
       m = NUMELEMENTS-2;
       while(s[m]>s[m+1])
       {
          m = m - 1;
       }
       k = NUMELEMENTS-1;
       while(s[m] > s[k])
       {
          k = k - 1;
       }
       swap(m,k);
       p = m + 1;
       q = NUMELEMENTS-1;
       while( p < q)
       {
         swap(p,q);
         p++;
         q--;
       }
      //  printS();
     }
   }

BruteForce::BruteForce(Matrix *matrix, int numCities){
  this->NUMELEMENTS = numCities;
  this->s = new int[this->NUMELEMENTS + 1];
  for(int i = 0; i < NUMELEMENTS; i++){
    s[i] = i%20;
  }
  s[this->NUMELEMENTS] = 0;
  this->matrix = matrix;
  this->bestCase = getBestCase();
}

double BruteForce::getBestCase(){
  int num = this->NUMELEMENTS;
  double best = 0;
  for(int i = this->NUMELEMENTS; i > 1; i--){
    num *= (i-1);
  }
  for(int k = 0; k < NUMELEMENTS; k++){
    best += this->matrix->matrix[s[k]][s[k+1]];
  }
  double testCase;
  for(int q = 0; q < num; q++){
    testCase = 0;
    // while(s[0] != 0)
    //   perm1(this->NUMELEMENTS - 1);
    if(this->s[0] == 0){
    for(int j = 0; j < NUMELEMENTS; j++){
      // std::cout << testCase << "\ttestCase\n";
      testCase += this->matrix->matrix[s[j]][s[j+1]];
      // std::cout << std::endl << this->matrix->matrix[s[j]][s[j+1]] << std::endl;
      // std::cout << testCase << "\ttestCase B\n";
      
    }
    // std::cout <<"\nNEWLINE test\n";
    if(testCase < best)
      best = testCase;
    for(int y = 0; y < this->NUMELEMENTS +1; y++)
      std::cout << s[y] << "\t";
    std::cout << std::endl << std::endl;
    // std::cout << best << " BESTCASE\n\n";
    perm1(this->NUMELEMENTS - 1);
    }
    else
      perm1(this->NUMELEMENTS - 1);
  }

  std::cout << std::endl << best;

  return best;
}

int main(){
  Matrix matrix;
  BruteForce BF(&matrix, 4);
  return 0;
}