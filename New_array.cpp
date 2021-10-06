#include "New_array.h"

New_array::New_array(){
    ptr = nullptr;
    size = 0;
}

New_array::New_array(const int* arr, int size){
    ptr = new int[size];
    copy(arr, arr + size, ptr);
    this->size = size;
}
New_array::New_array(const New_array& arr) {
    ptr = new int[arr.size];
    copy(arr.ptr, arr.ptr + arr.size, ptr);
    size = arr.size;
}

New_array::~New_array(){
    delete[] ptr;
}

void New_array::display(){
    for(int i = 0; i<size; i++){
        cout<< *(ptr +i)<<" ";
    }

}


New_array& New_array::operator=(const New_array& arr){

    if (this == &arr)
        return *this;

    delete[] ptr;

    ptr = new int[arr.size];
    copy(arr.ptr, arr.ptr + arr.size, ptr);
    size = arr.size;

    return *this;
}


New_array::New_array(New_array&& other) {
    ptr = other.ptr;
    size = other.size;
    other.ptr = nullptr;
}

std::ostream& operator<<(std::ostream& os, const New_array& other) {
    for (size_t i = 0; i < other.size; i++) {
        os << *(other.ptr + i) << " ";
    }

    return os;
}

std::istream& operator>>(std::istream& is, New_array& other) {
    size_t s;
    std::cout << "Enter the size of the array: ";
    is >> s;
    int* arr = new int[s];
    for (size_t i = 0; i < s; i++) {
        is >> *(arr + i);
    }

    New_array temp(arr, s);
    delete[] arr;

    other = temp;

    return is;
}

/*
New_array& operator-(const New_array& other){
    cout<<"Hello"<<endl;
};*/


New_array& New_array::operator-(){
    int temp = 9999;
    int index = 0;
    for (int i = 0; i < this->size; i++) {
        if (temp > ptr[i]){
            temp = ptr[i];
            index = i;
        }
    }
    //*(ptr +index) = *(ptr +index+1);
    // Delete x from arr[]
    deleteElement(ptr, size, temp);

    return *this;
}

int New_array::deleteElement(int arr[], int n, int x)
{
// Search x in array
    int i;
    for (i=0; i<n; i++)
        if (arr[i] == x)
            break;

// If x found in array
    if (i < n)
    {
        // reduce size of array and move all
        // elements on space ahead
        n = n - 1;
        for (int j=i; j<n; j++)
            arr[j] = arr[j+1];
    }

    return n;
}


New_array& New_array::operator+(const New_array& other) {

    int* temp = new int[size];
    std::copy(ptr, ptr + size, temp);
    delete[] ptr;
    ptr = new int[size + other.size];
    std::copy(temp, temp + size, ptr);
    std::copy(other.ptr, other.ptr + other.size, ptr+size);
    size = size + other.size;

    return *this;

}


New_array& New_array::operator=(New_array&& other){
    if (this == &other)
        return *this;

    delete[] ptr;

    ptr = other.ptr;
    size = other.size;
    other.ptr = nullptr;

    return *this;
}
