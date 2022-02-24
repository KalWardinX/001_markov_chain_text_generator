#include "data.h"

int transition_diag::get_pos(std::string s){
    return m.find(s)->second;
}

void transition_diag::insert_map(std::string key){
    if( m.find(key) == m.end()){
        m.insert({key,size});
        size++;
        graph.resize(size);
    }
}
void transition_diag::insert_graph(int pos , std::string value){
    for(auto n : graph[pos]){
        if(n->word.compare(value)){
            n->count++;
            return;
        }
    }
    graph[pos].push_back(new node(value,1));
}
void transition_diag::insert(std::string key, std::string value){
    this->insert_map(key);
    int pos_in_graph = this->get_pos(key);
    this->insert_graph(pos_in_graph , value);
}

table transition_diag::generate(){
    table t;
    for(auto i: m){
        int maxim=0;
        std::string str;
        for(auto v: graph[i.second]){
            if(v->count > maxim){
                str=v->word;
                maxim = v->count;
            }
        }
        t.insert(i.first,str);
    }
    return t;
}