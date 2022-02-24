#include "data.h"

void table::insert(std::string key, std::string value){
    m.insert({key, value});
}


std::string table::get_next(std::string s){
    return m.find(s)->second;
}