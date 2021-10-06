#include <iostream>
#include <vector>
#include <ctime>
#include "New_array.h"
using namespace std;

//Let's create class New_array which is for storing arrays of integers.
// Overload operator- and this operator will remove the smallest element in the array;


int main() {
    New_array array1;
    New_array array2((int[]){6,1,6,1,7}, 5);
    New_array arrayTemp((int[]){3,1,11,23,4}, 5);

    New_array array3;
    array3 = array2;


    array2+arrayTemp;
    //array2.display();

    int x = 5;
    int five_divided_by_x = ( x != 0    ?    25 / x      :     0 );

    // coin toss, return head if rand>0.5 otherwise return tail;

    srand(time(NULL));

    string coin_toss_result = (rand()%2<0.5 ?  "head" : "tail");



    cout<< coin_toss_result;

    //cin>>array1;
    //cout<<array1<<endl;


    -array2; //Delete the lowest integer in array


    //cout<<array2<<endl;
    //array2.operator-();
    //-array2;

    //turnarray

    return 0;
}


