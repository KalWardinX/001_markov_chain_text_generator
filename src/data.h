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
