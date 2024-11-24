#include<iostream>  //preprocessor directives start with "$" or "#"  ---- can be used for Conditionala compilation
#include<vector>

using namespace std; // otherwise we would have to use std::cin,std::cout,std::endl,std::vector


//cout,cin,cerr,clog??
int main(){
    int age{0};
    const int size{5};
    int ages1[size] {1,2,3,4}; // last element = 0

    vector <int> vector1(size,2); // very efficient, many cool fns like sort,reverse,find,etc .... can grow and shrink at execution time.
    //                             all values are initiallized to 2 in the above example.
    
    // cout<<"Enter Age: ";
    // cin>> age;
    // cout<< endl;

    vector1.at(2) = 25;
    cout<< vector1[2]<<endl;        //no bounds check
    cout<< vector1.at(2)<<endl;     // checks bounds
    cout<< vector1.at(2)<<endl;
    cout<< vector1.size()<<endl;
    vector1.push_back(89);
    cout<< vector1.size()<<endl;

    int a{3},b{2};
    double avg = static_cast<double>(a)/b; //NOTE: static_cast<double>(a/b) wont work;

    enum direction{
        up,down,left,right // majorly used in switch casesS
    };// there will be a semilcolon here

    direction moving{left}; // direction is the enumerated type - basically it assigns numbers to these diff values, EG: up = direction.0

    cout << (1>2) ? 1 : 2; // ternary operator.
}