#include<iostream>
using namespace std;


int main() {
    
    int matrix_dim[] = {2, 3, 6, 4, 5};
    int size = sizeof(matrix_dim) / sizeof(int);
    
    int m[size][size];
    
    //Cost is 0 when multiplying one matrix
    for(int i = 0; i < size; i++)
    { m[i][i] = 0; }
    
    
    //Chain refers to the chain length
    for(int chain = 2; chain < size; chain++)
    {
        for(int i = 1; i < size - chain + 1; i++)
        {
            int j = i + chain - 1;
            m[i][j] = INT_MAX;
            
            for(int k = i; k < j; k++)
            {
                int q = m[i][k] + m[k+1][j] + matrix_dim[i-1] * matrix_dim[k] * matrix_dim[j];
                
                if(q < m[i][j])
                { m[i][j] = q; }
            }
        }
    }
    
    //m[1][size-1] will hold value the value for minimum number of multiplications needed to compute the matrices
    //of various order specified by matrix_dim[] array
    cout << m[1][size-1] << endl << endl;
    
    return 0;
}