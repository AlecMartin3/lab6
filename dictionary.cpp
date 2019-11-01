//
// Created by Alec on 2019-11-01.
//

#include "dictionary.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

dictionary::dictionary(ifstream &file) {
    string line;
    while(getline(file, line)){
        istringstream iss(line);
        string word, def;
        if(!getline(iss, word, '-')){
            throw runtime_error("Bad input");
        }
        if(getline(iss, def, '-')){
            wordAndDef.insert(make_pair(word, def));
        }

    }
}

void dictionary::printMap() {
    for (auto const& pair: wordAndDef) {
        std::cout << pair.first << "-" << pair.second << "\n";
    }
}

void dictionary::findWord(string word){
    map<string, string>::iterator findWordAndDef = wordAndDef.find(word);
    if(findWordAndDef != wordAndDef.end()){
        cout << findWordAndDef->first << " - " << findWordAndDef->second<< endl;
    } else{
        cout<< "Word not found" <<endl;
    }
}

void dictionary::insertWordAndDef(ofstream &file) {
    string word, def;
    cout<<"insert a new word"<< endl;
    cin >> word;
    if(wordAndDef.count(word) == 1){
        cout<< "Word exists already" << endl;
    }else{
        cout<<"insert a definition for that word" <<endl;
        cin>>def;
        wordAndDef.insert(make_pair(word, def));
        file <<"\n" << word << '-' << def;
    }

}
