// Создать одномерный массив из элементов матрицы.

#include <iostream>

using namespace std;

// int* transfer_array2d_array1d(int size_x,int size_y){
//     //create matrix
//     int **array2d = new int * [size_y];
//     for(int i = 0;i<size_x;i++){
//         array2d[i] = new int [size_x];
//     }
//     //create array
//     int *array1d = new int[size_x*size_y]; 
//     // fill matrix
//     srand ( time(0) );
//     for(int i = 0; i<size_x;i++){
//         for(int j = 0;j<size_y;j++){
//             array2d[i][j] = (rand() % 100);
//         }
//     }
//     // transfer 'array2d' to 'array1d'
//     int index=0;
//     for(int i=0;i<size_x;i++)
//         for(int j=0;j<size_y; j++,index++)
//             array1d[index] = array2d[i][j];
//     // // delete matrix
//     // for(int i = 0;i<size_x;i++){
//     //     delete[] array2d[i];
//     // }
//     // delete[] array2d;
//     // //delete array1d
//     // delete[] array1d;
//     return array1d;
// }

int* transfer_array2d_array1d(int ** array2d){
    // int size_x =  sizeof array2d / sizeof array2d[0];  
    // int size_y =  sizeof array2d[0] / sizeof(int);
    
    int *array1d = new int[5]; 
    
    // transfer 'array2d' to 'array1d'
    // int index=0;
    // for(int i=0;i<size_x;i++)
    //     for(int j=0;j<size_y; j++,index++)
    //     array1d[index] = array2d[i][j];
    // delete matrix
    // for(int i = 0;i<size_x;i++){
    //     delete[] array2d[i];
    // }
    // delete[] array2d;
    return array1d;
    // //delete array1d
    // delete[] array1d;
}

int main()
{
    int size_x = 5;
    int size_y = 2;
    //create array2d
    int **array2d = new int * [size_x];
    for(int i = 0;i<size_x;i++){
        array2d[i] = new int [size_y];
    }
    /////////////////////////////
    // fill matrix
    srand ( time(0) );
    for(int i = 0; i<size_x;i++){
        for(int j = 0;j<size_y;j++){
            array2d[i][j] = (rand() % 10);
        }
    }
    
   
    
    int* result = transfer_array2d_array1d(array2d);
    
    for(int i = 0; i<5; i++){
        cout << "[" << result[i] << "]";
    }
    delete result;
    delete[] result;
    
}
