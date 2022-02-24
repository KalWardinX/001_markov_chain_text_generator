#include <string>
#include <map>
#include <vector>

class table{
    private:
        std::map<std::string, std::string> m;
    public:
        std::string get_next(std::string);
        void insert(std::string , std::string );
};

class transition_diag{
    private:
        std::map<std::string, int> m;
        struct node{
            std::string word;
            int count;
            node(std::string w, int c){
                word = w;
                count = c;
            }
        };
        std::vector< std::vector<node*> > graph;
        int size;
        int get_pos(std::string);
        void insert_map(std::string);
        void insert_graph(int , std::string );
    public:
        void insert(std::string, std::string);
};