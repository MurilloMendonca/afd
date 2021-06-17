#include "afd.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    vector<AFD> v;
    for(int i=0;i<5;i++)
        v.emplace_back(AFD("afd"+to_string(i+1)+".txt"));
    for(AFD x:v){
        x.mostraAFD();
        x.realizaTestes();
    }
    return 0;
}