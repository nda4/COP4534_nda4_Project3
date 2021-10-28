#include "genetic.hpp"

void Genetic::swap(int num1, int num2)
{
    int temp = s[num1];
    s[num1] = s[num2];
    s[num2] = temp;
    s[this->NUMELEMENTS] = s[0];
}

void Genetic::mutate(int num1, int num2)
{
    int temp = mutation[num1];
    mutation[num1] = mutation[num2];
    mutation[num2] = temp;
    mutation[this->NUMELEMENTS] = mutation[0];
}

void Genetic::printS()
{
    std::cout << std::endl;
    for (int i = 0; i < this->NUMELEMENTS + 1; i++)
    {
        std::cout << this->s[i] << "\t";
    }
    std::cout << "\n\n";
}

void Genetic::perm1(int permsThisCall)
{
    int m, k, p, q, i;
    //  printS();
    for (i = 1; i < permsThisCall; i++)
    {
        m = NUMELEMENTS - 2;
        while (s[m] > s[m + 1])
        {
            m = m - 1;
        }
        k = NUMELEMENTS - 1;
        while (s[m] > s[k])
        {
            k = k - 1;
        }
        swap(m, k);
        p = m + 1;
        q = NUMELEMENTS - 1;
        while (p < q)
        {
            swap(p, q);
            p++;
            q--;
        }
        //  printS();
    }
}

double Genetic::getBestCase(int numTours, int numGens, double percMut)
{
    double best = 0;
    double test1, test2;
    int numMutations;
    this->mutation = new int[this->NUMELEMENTS + 1];
    int elite[this->NUMELEMENTS + 1];
    for (int o = 0; o < this->NUMELEMENTS; o++)
    {
        best += this->matrix->matrix[s[o]][s[o + 1]];
        elite[o] = s[o];
    }
    elite[this->NUMELEMENTS] = 0;
    for (int i = 0; i < numGens; i++)
    {
        for (int o = 0; o < this->NUMELEMENTS + 1; o++)
            mutation[o] = elite[o];
        numMutations = (percMut * numTours);
        for (int j = 0; j < numTours; j++)
        {

            for (int o = 0; o < this->NUMELEMENTS; o++)
                test1 = 0;
                test2 = 0;
            if (i == 0)
            {
                for (int t = 0; t < NUMELEMENTS; t++)
                {
                    test1 += this->matrix->matrix[s[t]][s[t + 1]];
                }
                perm1(this->NUMELEMENTS - 1);
            }
            else
            {
                if (j != 0)
                {
                    if (numMutations >= 0)
                    { 
                        permMut(this->NUMELEMENTS - 1);
                        --numMutations;
                        for (int t = 0; t < this->NUMELEMENTS; t++)
                        {
                            test2 += this->matrix->matrix[mutation[t]][mutation[t + 1]];
                        }
                    }
                    else
                        perm1(this->NUMELEMENTS - 1);
                        for (int t = 0; t < this->NUMELEMENTS; t++)
                        {
                            test1 += this->matrix->matrix[s[t]][s[t + 1]];
                        }
                }
            }
            if (test1 <= best && test1 > 0)
            {
                best = test1;
                for (int tester = 0; tester < this->NUMELEMENTS; tester++)
                {
                    elite[tester] = s[tester];
                }
            }
            for (int t = 0; t < this->NUMELEMENTS; t++)
            {
                test2 += this->matrix->matrix[mutation[t]][mutation[t + 1]];
            }
            if (test2 <= best && test2 > 0)
            {
                best = test2;
                for (int tester = 0; tester < this->NUMELEMENTS; tester++)
                {
                    elite[tester] = s[tester];
                }
            }
        }
        
    }

    delete mutation;

    return best;
}

void Genetic::permMut(int permsThisCall)
{
    int random1, random2;
    for(int m = 1; m < this->NUMELEMENTS; m++){
        random1 = rand() % ((this->NUMELEMENTS-(m+1))+ 1) + (m+1);
        random2 = rand() % ((this->NUMELEMENTS-(m+1))+ 1) + (m+1);
        mutate(random1 - 1, random2 - 1);
    }
}

Genetic::Genetic(Matrix *matrix, int numCities, int numTours, int numGens, double percMut)
{
    this->NUMELEMENTS = numCities;
    this->s = new int[this->NUMELEMENTS + 1];
    for (int i = 0; i < this->NUMELEMENTS; i++)
        s[i] = i % 20;
    s[this->NUMELEMENTS] = 0;
    this->matrix = matrix;
    this->bestCase = getBestCase(numTours, numGens, percMut);

    std::cout <<"\nGenetic Algorithm Best Case: " << this->bestCase << std::endl;

    delete s;
}