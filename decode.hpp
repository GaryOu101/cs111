#include <string>
#include <vector>
#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

//finds coefficient*(secretNum)^exponent (mod n) and returns it
int findDecodedNum(int coefficient, int secretNum, int exponent, int n){
    if(exponent == 1){
        return (secretNum * coefficient) % n;
    }else if(exponent % 2 == 0){
        exponent /= 2;
        secretNum = (secretNum * secretNum) % n;
        return findDecodedNum(coefficient, secretNum, exponent, n);
    }else if(exponent % 2 == 1){
        exponent -= 1;
        coefficient = (coefficient * secretNum) % n;
        return findDecodedNum(coefficient, secretNum, exponent, n);
    }
    return 0;
}

//converts the number into the letter equivalent and returns it
char convertToLetter(int decodedNum){
    decodedNum -= 3;
    decodedNum += 'a';
    if(decodedNum <= 122)
        return decodedNum;
    else if(decodedNum == 123)
        return ' ';
    else if(decodedNum == 124)
        return '"';
    
    return '.';
}  

/*
Have we decoded this letter yet?
If yes, find what we got last time, and concatenate it to the string.
If not, then decode it, find the char equivalent, and concatenate to the string.
*/
string DecodeMessage(string fileName){
    int d = 1027;
    int n = 1633;
    vector<int> key(184);
    fill(key.begin(), key.end(), 0);
    ifstream input;
    input.open(fileName);

    int decodedNum;
    string finalString;
    int current;

    while(!input.eof()){
        input >> current;
        input.ignore();
        if(key[current] == 0){
            decodedNum = findDecodedNum(1, current, d, n);
            key[current] = decodedNum;
        }else{
            decodedNum = key[current];
        }
        finalString += convertToLetter(decodedNum);
        cout << decodedNum << endl;
    }

    return finalString;
} 