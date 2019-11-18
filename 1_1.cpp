#include <iostream>

using namespace std;

int main()
{
    srand ( time(0) );
    int size = 2;
    int max;
    //create matrix
    int **array2d = new int * [size];
    for(int i = 0;i<size;i++){
        array2d[i] = new int [size];
    }
    //create array
    int *array1d = new int[size]; 
    
    
    
    // fill matrix
    for(int i = 0; i<size;i++){
        for(int j = 0;j<size;j++){
            array2d[i][j] = (rand() % 100);
        }
    }
    
    
    // output matrix 
    for(int i = 0; i<size;i++){
        cout << i << ":\t";
        for(int j = 0;j<size;j++){
            if(array2d[i][j]>=0){
                cout << "[ " << array2d[i][j]  << "]";
            }else{
                cout << "[" << array2d[i][j]  << "]";
            }
            
        }
        cout << ";" << endl;
    }
    // calculating matrix
    for(int i=0,j=0; i<size,j<size; i++,j++){
        array1d[i] = array2d[i][j];
    }
    // output array1d
    for(int i = 0;i<size;i++){
        cout << "[" << array1d[i] << "]";
    }
    // find max value of array1d(diagonal)
    max = array1d[0];
    for(int i = 0; i<size; i++){
        if(array1d[i] > max){
            max = array1d[i];
        }
    }
    
    cout << "\n" << max << endl;
    
    
    //delete matrix
    for(int i = 0;i<size;i++){
        delete[] array2d[i];
    }
    delete[] array2d;
    //delete array1d
    delete[] array1d;
    return 0;
}
