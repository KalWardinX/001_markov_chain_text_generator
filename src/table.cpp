#include "data.h"
void table::insert(std::string key, std::string value){
    m.insert({key, value});
}


std::string table::get_next(std::string s){
    std::string res;
    if(m.find(s) != m.end()){
        res = m.find(s)-> second;
        return res;
    }
    int rand_pos = rand()%m.size();
    std::map<std::string, std::string>::iterator it=  m.begin();

    for(int i=0; i<m.size(); i++,it++){
        if(i==rand_pos){
            res= it->second;
        }
    }
    return res;
}
