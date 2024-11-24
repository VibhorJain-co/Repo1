#include <iostream>
using namespace std;


int main(){
    int n{0};
    cin>>n;

    int sols{0};
    for (int i = 0; i < n; i++)    {
        int sum{0};
        for (int j = 0; j < 3; j++)    {
            int a{0};
            cin>>a;
            sum+=a;
        }
        if(sum>=2){
            sols++;
        } 
    }
    
    cout<<sols;
    
    return 0;
}
