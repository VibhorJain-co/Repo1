#include <iostream>
using namespace std;


int main(){
    int w{0};
    cin >> w;
    if(w!=0 && w!=2 && w%2==0){
        cout<<"YES";
    }else{
         cout<<"NO";
    }
    
    return 0;
}