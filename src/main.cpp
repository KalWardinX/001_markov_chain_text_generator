#include <iostream>
#include <fstream>
#include "data.h"
#include <filesystem>
#include <istream>
std::string get_new_string(std::string s, std::string ins){
    std::string result;
    std::string word;
    std::istringstream iss(s);
    iss>>word;
    while(iss>>word){
        result+=word+" ";
    }
    result+=ins;
    return result; 
}
std::string trim(std::string s){
    std::string res;
    for(auto ch: s){
        ch=tolower(ch);
        if(ch>='a' && ch<='z'){
            res+=ch;
        }
    }
    return res;
}
void generate(table& lookup, std::string s, int n){
    if(n==0){
        return;
    }
    std::cout << lookup.get_next(s) <<" ";
    s=get_new_string(s,lookup.get_next(s));
    generate(lookup, s, --n);
}


int main(int argc , char** argv){
    
    int num = std::atoi(argv[1]);
    int k = std::atoi(argv[2]);
    std::string init;
    for(int i=0; i<k; i++){
        std::string temp ;
        int j=0;
        while(argv[i+3][j]){
            temp+=argv[i+3][j];
            j++;
        }
        if(i==k-1){
            init+=temp;
            break;
        }
        init+=temp+" ";
    }

    transition_diag t;
    std::string inp_dir = "./input";
    for(const auto &entry : std::filesystem::directory_iterator(inp_dir) ){
        std::ifstream file;
        file.open(entry.path());
        std::string word;
        std::string key;
        std::string value;
        std::string next;
        for(int i=0; i<k;i++){
            file>>word;
            word = trim(word);
            if(i==k-1){
                key+=word;
                break;
            }
            key+=word+" ";
        }
        file>>value;
        value = trim(value);
        t.insert(key, value);
        while(file>>next){
            next= trim(next);
            key = get_new_string(key, value);
            value = next;
            t.insert(key ,value);
        }
    }

    table lookup = t.generate();
    std::cout << init<< " ";
    generate(lookup,init,num-k);
    return 0;
}