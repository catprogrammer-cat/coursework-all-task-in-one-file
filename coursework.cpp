
#include <iostream>

int max_value_matrix(int size){ //coursework_1 --> // Вычислить значение максимального 
    int max;                                       // элемента главной диагонали матрицы.
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

int counter_positive_element_rows_array2d(int x,int y){ //coursework_2 --> // Вычислить элементы вектора как количества 
    int **array2d = new int * [y];                                                  // положительных элементов строк матрицы.
    for(int i = 0;i<size;i++){
        array2d[i] = new int [x];
    }
    //create array
    int *array1d = new int[y]; 
    // fill matrix
    srand ( time(0) );
    for(int i = 0; i<y;i++){
        for(int j = 0;j<x;j++){
            array2d[i][j] = (rand() % 20)-10;
        }
    }
    // counter positive element
    int quantity = 0;
    for(int i=0; i<y; i++){
        quantity = 0;
        for(int j=0;j<x;j++){
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

int sum_positive_elements_column_array2d(int x,int y){ //coursework_3 --> // Определить: сумму элементов в тех столбцах, 
    //create matrix                                                       // которые не содержат отрицательных элементов;
    int **array2d = new int * [y];
    for(int i = 0;i<y;i++){
        array2d[i] = new int [x];
    }
    //create array
    int *array1d = new int[x]; 
    // fill matrix
    srand ( time(0) );
    for(int i = 0; i<y;i++){
        for(int j = 0;j<x;j++){
            array2d[i][j] = (rand() % 20)-10;
        }
    } 
    // Calculate sum of positive element which constist
    // in collumn without negative element array2d
    for(int i=0;i<x;i++){
        array1d[i] = 0;
        for(int j=0;j<y;j++){       
            if(array2d[j][i] < 0){
                array1d[i] = 0;
                break;
            }
            else{
                array1d[i]+=array2d[j][i];
            }
        }
    }
    //delete matrix
    for(int i = 0;i<y;i++){
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
