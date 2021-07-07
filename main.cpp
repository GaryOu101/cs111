#include <string>
#include <iostream>
#include "decode.hpp"

using namespace std;

int main (int argv, char** argc){
    cout << DecodeMessage("secretFile.txt");

    return 0;
}