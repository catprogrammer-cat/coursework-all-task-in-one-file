// Input a string and change punctuation
// marks with symbol '#'
#include <iostream>
#include <stdio.h> // for gets, puts;
#include <conio.h> // for getch();
#include <string.h> // for strlen (s); necessary in online compiler
#include <cctype>

using namespace std;

// const int M = 3, N = 5;


void calculate_size_array2d(char* name, int &size_x, int &size_y){
    FILE* f;
    char s[100], *t; // t --> tabulation
    f = fopen(name, "rt"); //открыть файл для чтения как текстовый
    if (f == NULL){
        cout << "Cannot open file to veiw\n";
    }

    int i, j;
    // counter size of array2d from FILES
    for(i=0; fgets(s, 100, f); i++){ // Считывать из файла строки, пока они не закончатся
        j=0;
        t = strtok(s, " \t");
        for(;t != NULL; j++){
            // array2d[i][j] = atoi(t);
            t = strtok(NULL, " \t");
        }
    }
    int x, y;
    size_x = j;
    size_y = i;

    fclose(f);
}


int** read_and_push_array2d_return(char* name){
    
    FILE* f;
    char s[100], *t; // t --> tabulation
    f = fopen(name, "rt"); //открыть файл для чтения как текстовый
    if (f == NULL){
        return 0;
    }

    int i, j;
    // counter size of array2d from FILES
    for(i=0; fgets(s, 100, f); i++){ // Считывать из файла строки, пока они не закончатся
        j=0;
        t = strtok(s, " \t");
        for(;t != NULL; j++){
            // array2d[i][j] = atoi(t);
            t = strtok(NULL, " \t");
        }
    }
    int x, y;
    x = j;
    y = i;

    // create array using size
    //create matrix
    int **array2d = new int * [y];
    for(int i = 0;i<x;i++){
        array2d[i] = new int [x];
    }
    fclose(f);
    f = fopen(name, "rt"); //открыть файл для чтения как текстовый
    if (f == NULL){
       return 0;
    }
    // push values into array2d form FILES
    for(i=0; fgets(s, 100, f); i++){ // Считывать из файла строки, пока они не закончатся
        j=0;
        t = strtok(s, " \t");
        
        for(;t != NULL; j++){
            array2d[i][j] = atoi(t);
            t = strtok(NULL, " \t");
        }
    }
    fclose(f);
    return array2d;

}

int main()
{
    //double A[M][N];
    int i, j;
    int size_x;
    int size_y;
    
    char  name_1[] = "F1.txt";
    char  name_3[] = "F3.txt";

    // find size of array2d
    calculate_size_array2d(name_1, size_x,size_y);
    cout << "size_x = " << size_x << endl;
    cout << "size_y = " << size_y << endl;

    FILE* f3;
    f3 = fopen(name_3, "wt"); //открыть файл для создания как текстовый
    if (f3 == NULL) {
        cout << "Cannot open file to view\n";
        return 1;
    }
    
    int **array2d;
    array2d = read_and_push_array2d_return(name_1);
    // read_and_push_array2d(name1, double array2d[M][N])
    for(int i=0;i<size_y;i++){
        for(int j=0;j<size_x;j++){
            cout << "[" << array2d[i][j] << "]";
        }
        cout << endl;
    }
    
    // create_matrix(name_1, A);
    // for (i = 0; i < M; i++){
    //     for (j = 0; j < N; j++){
    //         cout << A[i][j] << "\t";    
    //         fprintf(f3, "%7.1f\t", A[i][j]);
    //     }
    //     cout << endl;
    //     fprintf(f3,"\n");
    // }

    // fclose(f3);
    system("pause");
    return 0;
}
// Enter a string:
// Hello! My name is Vlad. How are you?
// Hello# My name is Vlad# How are you#
