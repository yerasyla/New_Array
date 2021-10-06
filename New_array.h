#ifndef L5_NEW_ARRAY_H
#define L5_NEW_ARRAY_H
#include <algorithm>
#include <iostream>
using namespace std;

class New_array {
private:
    int* ptr;//pointer to first element of array //*(ptr +0)
    int size;

public:
    New_array();
    New_array(const int* arr, int size);
    New_array(const New_array& other);
    New_array(New_array&& other);
    ~New_array();

    void display();
    void print_size() {
        std::cout << size << std::endl;
    }



    friend std::ostream& operator<<(std::ostream& os, const New_array& other);
    friend std::istream& operator>>(std::istream& is, New_array& other);



    New_array& operator=(const New_array& other);
    New_array& operator=(New_array&& other);

    New_array& operator+(const New_array& other);

    // Overload operator- and this operator will remove the smallest element in the array;

    int deleteElement(int arr[], int n, int x);

    New_array& operator-();
    //friend New_array& operator-(const New_array& other);


};


#endif //L5_NEW_ARRAY_H
