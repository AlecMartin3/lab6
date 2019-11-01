//
// Created by Alec on 2019-11-01.
//

#ifndef LAB06_DICTIONARY_HPP
#define LAB06_DICTIONARY_HPP
#include <map>
#include <iterator>
using namespace std;

class dictionary {
private:
    map<string, string> wordAndDef;
public:
    dictionary(ifstream &file);
    void printMap();
    void findWord(string word);
    void insertWordAndDef(ofstream &file);
};


#endif //LAB06_DICTIONARY_HPP
