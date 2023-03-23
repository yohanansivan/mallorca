#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <vector>
using namespace std;


class Parser {
    private:
        string mChunk;
        string mActionUrl;
        string mUserField;
        string mPassField;
        vector<string> search(string str, string sub1, string sub2, string in = "");
        vector<string> search2(string str, string sub1, string sub2);

    public:
        void setChunk(string chunk);
        string getChunk();
        int customSearch();
        string getActionUrl();
        string getUserField();
        string getPassField();
};


#endif // PARSER_H
