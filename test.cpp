// Input a string and change punctuation
// marks with symbol '#'
#include <iostream>
#include <stdio.h> // for gets, puts;
#include <conio.h> // for getch();
#include <string.h> // for strlen (s); necessary in online compiler
#include <cctype>

using namespace std;

// const int M = 3, N = 5;
void read_and_push_array2d(char* name){

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
    x = j;
    y = i;


    // create array using size
    //create matrix
    int **array2d = new int * [y];
    for(int i = 0;i<x;i++){
        array2d[i] = new int [x];
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
    cout << "x : " << x << endl; // i --> y
    cout << "y : " << y << endl; // j --> x

    cout << endl;

    // output matrix 
    for(int i = 0; i<y;i++){
        cout << i << ":\t";
        for(int j = 0;j<x;j++){
            if(array2d[i][j]>=0){
                cout << "[ " << array2d[i][j]  << "]";
            }else{
                cout << "[" << array2d[i][j]  << "]";
            }
            
        }
        cout << ";" << endl;
    }
    // while (fgets(s, 100, f)) { //считывать из файла строки, пока они не закончатся
    //     j = 0;
    //     t = strtok(s, " \t");
    //     while (t != NULL){
    //         array2d[i][j] = atoi(t);
    //         t = strtok(NULL, " \t");
    //         j++;
    //     }
    //     i++;
    // }
    fclose(f);
}

int main()
{
    //double A[M][N];
    int i, j;
    char  name_1[] = "F1.txt";
    char  name_3[] = "F3.txt";
    FILE* f3;
    f3 = fopen(name_3, "wt"); //открыть файл для создания как текстовый
    if (f3 == NULL) {
        cout << "Cannot open file to view\n";
        return 1;
    }
    
    
    read_and_push_array2d(name_1);
    // read_and_push_array2d(name1, double array2d[M][N])

    
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
