//
// Created by ML103 on 3/12/2026.
//
#include <iostream>
using namespace std;

void swapValues(int* p1, int* p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void printArray(int* arr, int size) {
    int* first = &arr[0];
    for (int i = 0; i < size; i++) {
        cout << *first<<endl;
        first++;
    }
}

int findSum(int* arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

void shiftRight(int* arr, int size) {
    int last = *( arr+ size-1); // arr[size-1];
    for (int i = size-1; i > 0; i--) {
        *(arr+i) = *(arr+i-1);
    }

    *arr = last;
}

int* createArray(int size) {
    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cout<<"Enter array values: ";
        cin>> arr[i];
    }
    return arr;
}

void deleteArray(int* arr) {
    delete[] arr;
}

int main() {

    cout<<"Creating dynamic array..."<< endl;
    int size;
    cout<<"Enter size of array: ";
    cin>>size;

   int* arrAddress = createArray(size);

    printArray(arrAddress, size);
    cout<<"\n Sum of elements: " << findSum(arrAddress, size);
    cout<<"\n --------------------"<< endl;
    cout<<"Swapping to numbers "<<endl;
    int a;
    cout<<"Enter the first number: "<<endl;
    cin>> a;
    int b;
    cout<<"Enter the second number: "<<endl;
    cin>> b;
    cout<<"Before swap "<<endl;
    cout<<"a = "<< a << "\n b = " << b << endl;
    swapValues(&a,&b);
    cout<<"\n After swap "<<endl;
    cout<<"a = "<< a << "\n b = " << b;
    cout<<"\n --------------------";
    cout<<"\n Shifting array to the right... ";
    shiftRight(arrAddress, size);
    cout<<"\n Array after shiftRight: ";
    printArray(arrAddress, size);
    cout<<"\n --------------------";
    cout<<"\n Deleting the array... ";
    deleteArray(arrAddress);
    cout<<"\n Memory released successfully.";
}
