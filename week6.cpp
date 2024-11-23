
#include <iostream>
#include <iomanip>
using namespace std;


void sort(int*);
void getNums(int[]);
void reverse(int[], int[]);
void displayElements(int[], bool);
void displayNames();
void deAllocate(int[]);

int const ARRAYLENGTH = 10; // Global since we know all arrays are length of 10

int main(){
    // this time we added everything into functions for organization and readability
    int arr1[ARRAYLENGTH];
    int *reverserdArr = new int[ARRAYLENGTH]; // allocating array
    displayNames();
    getNums(arr1);
    sort(arr1);
    reverse(arr1, reverserdArr);
    displayElements(arr1, false); // boolean value to determine if reversed or not to diplay proper string before array
    displayElements(reverserdArr, true);
    deAllocate(reverserdArr);

    cin.ignore();
    cin.get();
    return 0;
}

void displayNames(){
    cout << "Student name:" << setw(18) << "Glen Dsouza" << endl;
    cout << "Student number:" << setw(14) << "900914917" << endl;
    cout << "Student name:" << setw(24) << "Jordon Marchesano" << endl;
    cout << "Student number:" << setw(14) << "900536880" << endl;
    cout << endl << endl;
};

void getNums(int arr[]){
    for (int rep = 0; rep < ARRAYLENGTH; rep++){
        cout << "Enter number " << rep+1 << ": ";
        cin >> arr[rep];
    }
};

void sort(int *num){
    int temp;
    bool checkSwap;
    do{
        checkSwap = false;
        for (int i = 0; i < ARRAYLENGTH - 1; i++){
            if (*(num+i) > *(num+i+1)){
                temp = *(num + i);
                *(num+i) = *(num+i+1);
                *(num+i+1) = temp;
                //if elements are swapped then the array isn't fully sorted yet
                checkSwap = true;
            }
        }
    }while(checkSwap);
};

void reverse(int arr[], int newArr[]){
    for (int i = 0; i < ARRAYLENGTH; i++){
        newArr[i] = arr[ARRAYLENGTH - i -1];
    }
};

void displayElements(int arr[], bool reversed){
    if(!reversed){
        cout << "First Array (Low --> High)" << endl;
        cout << "------------------------------------------------------------" << endl;
    }else{
        cout << "Second Array (High --> Low)" << endl;
        cout << "------------------------------------------------------------" << endl;
    }
    for (int rep = 0; rep < ARRAYLENGTH; rep++){
        cout << "Element " << rep+1 << ": " << *(arr + rep) << endl;
    }
};

void deAllocate(int arr[]){
    delete[] arr;
};
