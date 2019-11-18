
#include <iostream>

int max_value_matrix(int size){ //coursework_1 --> //Вычислить значение максимального 
    int max;                                       //элемента главной диагонали матрицы.
    // Create array2d
    int **array2d = new int * [size];
    for(int i = 0;i<size;i++){
        array2d[i] = new int [size];
    }
    // Create array
    int *array1d = new int[size]; 
    // fill matrix
    srand ( time(0) );
    for(int i = 0; i<size;i++){
        for(int j = 0;j<size;j++){
            array2d[i][j] = (rand() % 100);
        }
    }
    // Calculating matrix
    for(int i=0,j=0; i<size,j<size; i++,j++){
        array1d[i] = array2d[i][j];
    }
    // Find max value of array1d(diagonal)
    max = array1d[0];
    for(int i = 0; i<size; i++){
        if(array1d[i] > max){
            max = array1d[i];
        }
    }
    //delete matrix
    for(int i = 0;i<size;i++){
        delete[] array2d[i];
    }
    delete[] array2d;
    //delete array1d
    delete[] array1d;
    return max;
}

int counter_positive_element_rows_array2d(int size){ //coursework_2 --> //Вычислить элементы вектора как количества 
    int **array2d = new int * [size];                                   //положительных элементов строк матрицы.
    for(int i = 0;i<size;i++){
        array2d[i] = new int [size];
    }
    //create array
    int *array1d = new int[size]; 
    // fill matrix
    srand ( time(0) );
    for(int i = 0; i<size;i++){
        for(int j = 0;j<size;j++){
            array2d[i][j] = (rand() % 20)-10;
        }
    }
    // counter positive element
    int quantity = 0;
    for(int i=0; i<size; i++){
        quantity = 0;
        for(int j=0;j<size;j++){
            if(array2d[i][j]>=0){
                quantity++;
            }
        }
        array1d[i] = quantity;
    }
    //delete matrix
    for(int i = 0;i<size;i++){
        delete[] array2d[i];
    }
    delete[] array2d;
    //delete array1d
    delete[] array1d;
    return array1d;
}
using namespace std;

int main()
{
    cout<<max_value_matrix(1000);

    return 0;
}
