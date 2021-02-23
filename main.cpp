//
//  main.cpp
//  sandbox
//
//  Created by John Jeang on 9/27/20.
//  Copyright © 2020 John Jeang. All rights reserved.
//  these double forward slahses are comments
//  adding const before a variable prevents it from being changed
//  adding two chars together results in an int by default; but string addition concats!
//  Can get ascii character of string just by casting as int
//  typeid(myBool).name() prints out the object type
//  compiler actually accepts non-booleans in if statements, but the behavior is super weird..
//  TODO: Figure out what "auto" does

/*
 Below is syntax to prevent compiler from throwing warning that you are giving and int a float
 int myint;
 myint = static_cast<int>(3.2);
 */


/*
 C++ goes through code declaration line by line, so if a function is called before defined it will not know
 how to interpret.  A solution is to just delcare functions without definitions at the beginning of the code
 int factorial(int x);
 the above is example syntax
 */

/*
 In C++ you can only ever return 1 value, however to work aroudn this can you
 use Call By Reference (pointers) to affect multiple values without returning them
 */

/*
 static array size must be known as compile time
 non-initialized values in array are 0
 you actually CAN pass in array of unknown size into a function
 
 A vector is pretty much an array that can change sizes automatically
 vector<int> v;
 for (....)
 v.push_back(i *100); this is how to add elements to a vector
 vector.size() gives number of elements in vector
 
 C++ now supports ranged for loops to iterate over all elements of a structure
 for (int i: v)
 cout << i << endl;
 
 */

/*
 When reading strings, cin goes from whitespace to whitespace
 Need to use "getline(cin,str) to get the entire line
 Can slice strings with str.substr(3, 2) to get index and length
 str.length() also exists
 str.find('x') finds the index of where 'x' appears.  If not found it will return string::npos
 can give optional argument to find for looking at indices beyond a certain point (starting index).
 */


/*
 ~~~~POINTERS~~~~~~
 variables created on the heap do not have names, so that can only be accessed by pointer
 memory allocated on the heap does not get destroyed after a function call, only deallocated when you do it
 pointer pointing to nothing to point to nullptr
 int * ptr = new int;  this is an example of creating a variable on the heap
 delete ptr; this is an example of deleting a heap dynamic vairable
 then the pointer needs to point to nullptr!
 heap dynamic variables are useful for changing the size of arrays which are normally static
 There is an implicit dereferencing happening when indexing array pointers.
 */



//  built in library that is allowing me to print
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <typeinfo>
#include <cstdio>
#include <locale>
#include <vector>


const int MAX_ARRAY = 60;
const double my_pi = M_PI;
//  string is not a primitive data type
//  The line below would keep me from having to keep writing "std::" in front of cout/cin
using namespace std;

void addOne(int *ptrNum){
    *ptrNum = *ptrNum + 1;
}

int maxabsinlst(int lst[], int size){
    int max = abs(lst[0]);
    int printer = lst[0];
    for(int i = 0; i < size; i++){
        if (abs(lst[i]) > max){
            max = abs(lst[i]);
            printer = lst[i];
        }
    }
    return printer;
}

int multiplication(int a, int b) {
    int product(0);
    product = a*b;
    return product;
}

int factorial(int x){
    int product = 1;
    for(int counter = 1;counter <= x; counter++)
        product *= counter;
    return product;
}

int triangular(int x) {
    int counter = 0,sum = 0;
    while(counter <= x){
        sum += counter;
        counter++;
    }
    return sum;
}

// example of a function using switch branching
// numeric expression after swtich must be int char or bool
string dishes(int day){
    string disher;
    switch(day){
        case 7:
            disher = "Jeffrey";
            break;
        default:
            disher = "John";
            break;
    }
    return disher;
}

void countParity(){
    int a, b, c, d;
    string message;
    cout << "please give 4 space separated number \n";
    cin >> a >> b >> c >> d;
    cout << "you chose: " << a << " " << b << " " << c << " " << " \n";
}

void iter_evens(int x){
    int sum = 0;
    for(int display = 0;display < x; display++){
        sum += 2;
        cout << sum << " tada \n";
    }
}

void fibbonacci(int x){
    int n1 = 1, n2 = 1,counter = 0, n3;
    cout << n1 << "\n";
    cout << n2 << "\n";
    while(counter < x - 2){
        n3 = n1 + n2;
        n1 = n2;
        n2 = n3;
        counter++;
        cout << n3 << "\n";
    }
}

int gcd(int x, int y){
    if(y == 0){
        return x;
    }
    else{
        return gcd(y, x%y);
    }
}


char splitter(string& first, string& second, string str){
    unsigned long mid = str.length()/2;
    first = str.substr(0,mid);
    second = str.substr(mid+1, mid);
    return str[mid];
}

// This is just a toy example of how to use references so that you can affect vairbles outside the scope!

void reference_swap(int& x, int& y){
    int temp;
    temp = y;
    y = x;
    x = temp;
}

string student_status(int grade1, int grade2){
    string message;
    if ((grade1 < 60) && (grade2 < 60)){
        message = "Student failed! \n";
    }
    else if ((grade1 > 90) && (grade2 > 90)){
        message = "Student gradutated with honors! \n";
    }
    else{
        message =  "Student graduated normally. \n";
    }
    return message;
}

double* getDoubles(int numDoubles){
    double *thirds = new double[numDoubles];
    for(int i = 0; i < numDoubles; i++){
        thirds[i] = (double)i/(double)3;
    }
    return thirds;
}

void swap(int *xp, int *yp){
    int temp = *yp;
    *yp = *xp;
    *xp = temp;
}

int main(){
    int lst[] = {19, 2, 20, 1, 0, 18};

    cout << lst[0] << " and " << lst[1] << endl;
    swap(&lst[0],&lst[1]);
    
    cout << lst[0] << " and " << lst[1] << endl;
    return 0;
}




// ~~~~ BASIC POINTER EXAMPLE ~~~~~

//int main() {
//    int num;
//    int *ptrNum;
//    cout << "Gimme a number" << endl;
//    cin >> num;
//    ptrNum = &num;
//    addOne(ptrNum);
//    cout << "And now the number is "<< num << endl;
//    cout << "Dereferenced pointer value is " << *ptrNum << endl;
//    return 0;
//}

