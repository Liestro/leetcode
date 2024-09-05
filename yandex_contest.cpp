#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

std::vector<std::string> splitPath(const std::string& path)
{
    std::vector<std::string> result;

    std::istringstream iss(path);
    std::string node;

    while(getline(iss, node, '/')) {
        result.push_back(node);
    }

    return result;
}

bool check_right(std::unordered_map<std::string, std::unordered_map<std::string, std::unordered_map<std::string, bool>>>& rights,                 
                 const std::string& user,
                 const std::string& mode,
                 const std::string& path
                )
{
    bool result = false;
    auto splittedPath = splitPath(path);

    std::string currPath;
    for (auto it : splittedPath) {
        if (it == "") continue;
        currPath += "/" + it;

        if (rights.count(currPath)) 
            if ((rights[currPath]).count(user)) {
                result = rights[currPath][user][mode];
            }
    }

    return result;
}

int main()
{
    std::string command, user, mode, path;
    ifstream fin("input.txt");

    std::unordered_map<std::string, std::unordered_map<std::string, std::unordered_map<string, bool>>> rights;
    while(fin >> command >> user >> mode >> path) {
        if (command == "grant") {
            rights[path][user][mode] = true;
            std::cout << "done" << std::endl;
            std::cout << path << user << mode << rights[path][user][mode] << std::endl;
        } else if (command == "block") {
            rights[path][user][mode] = false;
            std::cout << "done" << std::endl;
        } else {
            bool right = check_right(rights, user, mode, path);
            std::cout << (right ? "allowed" : "forbidden") << endl;
        }
    }

    return 0;
}