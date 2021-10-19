#include <iostream>
#include <stdlib.h>
#include <time.h>

//true for ascending and false for descending

int arr_size = 10;

using namespace std;

// Create array and Print array used for demo purpose
void create_array(int arr[]){
    srand(rand()%arr_size+1*time(0));

    for(int i = 0; i<arr_size; i++){
        arr[i] = rand()%100+1;
    }
}

void printArray(int arr[]){
    int i;
    for (i = 0; i < arr_size; i++)
        cout <<arr[i] << " ";
    cout << endl;
}


//Bubble************************************************************************************************************
// Order = True for Ascending Order
void bubbleSort(int arr[], int n, bool order) {
    int i, j;
    for (i = 0; i < n-1; i++)

        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
//Ascending
        {
            if (order) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
//Descending
            else {
                if (arr[j] < arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            };
        }
}


///// Same code shorter Version
/*
void bubbleSort(int arr[], int n, bool order) {
    int i, j;
    for (i = 0; i < n-1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (order ? arr[j] > arr[j + 1] : arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}
*/

//Only used for demo purpose
int main() {

    int arr1[arr_size];

    //Store Random integers
    create_array(arr1);

    cout<<"Unsorted Array : ";
    printArray(arr1);


    cout << "\nSelection Sort Ascending Order" << endl;
    bubbleSort(arr1, arr_size, true);

    cout << "Sorted Array : ";
    printArray(arr1);


    cout << "\nSelection Sort Descending Order" << endl;
    bubbleSort(arr1, arr_size, false);

    cout << "Sorted Array : ";
    printArray(arr1);

    return 0;
}
