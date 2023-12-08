#include <fstream>
#include <sstream>

#include "include/graph.hpp"

using namespace std;

const string REFERENCE = "https://github.com/prokls/edmonds-branching-algorithm/blob/master/haskell/edmonds.hs";

const string FILE_NAME = "examples/graph4.txt";

vector<string> remove_empty_lines(const vector<string> lines) {
    vector<string> ls;

    for(const string& line : lines) {
        bool b = true;

        for(const char& c : line) {
            b = b && isspace(c);
        }

        if(!b) {
            ls.push_back(line);
        }
    }

    return ls;
}

vector<string> remove_comments(const vector<string> lines) {
    vector<string> ls;

    for(const string& line : lines) {
        size_t i = line.find('#');
        if(i != string::npos) {
            ls.push_back(line.substr(0, i));
        } else {
            ls.push_back(line);
        }
    }

    return remove_empty_lines(ls);
}

vector<string> read_lines() {
    vector<string> lines;
    string line;
    ifstream input_file(FILE_NAME);

    if(!input_file.is_open()) {
        cerr << "Error: Unable to open file `" << FILE_NAME << "`" << endl;
        exit(EXIT_FAILURE);
    }

    while(getline(input_file, line)) lines.push_back(line);

    input_file.close();
    return remove_comments(lines);
}

int main() {
    Graph* g = new Graph(read_lines());
    cout << g->str() << endl;

    Graph arb = Graph::edmonds(*g);
    cout << arb.str() << endl;
    
    delete g;
    return 0;
}
