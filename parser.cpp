#include "parser.h"


void Parser::setChunk(string chunk) {
    mChunk = chunk;
}


string Parser::getChunk() {
    return mChunk;
}


vector<string> Parser::search(string str, string sub1, string sub2, string in) {
    vector<string> out;
    size_t pos1 = str.find(sub1);
    while(pos1 != string::npos) {
        size_t pos2 = str.find(sub2, pos1 + sub1.length());
        if(pos2 == string::npos) break;
        string sub = str.substr(pos1, pos2 - pos1 + sub2.length());
        pos1 = str.find(sub1, pos2 + sub2.length());
        if(in.length() > 0) {
            size_t pos = sub.find(in);
            if(pos == string::npos) continue;
        }
        out.push_back(sub);
    }
    return out;
}


vector<string> Parser::search2(string str, string sub1, string sub2) {
    vector<string> out;
    size_t pos1 = str.find(sub1);
    while(pos1 != string::npos) {
        size_t pos2 = str.find(sub2, pos1 + sub1.length());
        if(pos2 == string::npos) break;
        string sub = str.substr(pos1 + sub1.length(), pos2 - pos1 - sub1.length());
        pos1 = str.find(sub1, pos2 + sub2.length());
        out.push_back(sub);
    }
    return out;
}


int Parser::customSearch() {
    string out;

    // Search for the form with password
    vector<string> forms = search(mChunk, "<form", "</form>", "type=\"password\"");
    if(forms.size() != 1) return 1;
    string form = forms[0];

    // Search the form action field
    vector<string> actions = search2(form, "action=\"", "\"");
    if(actions.size() != 1) return 1;
    string actionUrl = actions[0];

    // Search for the input with type text
    vector<string> inputs1 = search(form, "<input", ">", "type=\"text\"");
    if(inputs1.size() != 1) return 1;
    string input1 = inputs1[0];

    // Search the input with type text for name field
    vector<string> fields1 = search2(input1, "name=\"", "\"");
    if(fields1.size() != 1) return 1;
    string userField = fields1[0];

    // Search for the input with type text
    vector<string> inputs2 = search(form, "<input", ">", "type=\"password\"");
    if(inputs2.size() != 1) return 1;
    string input2 = inputs2[0];

    // Search the input with type text for name field
    vector<string> fields2 = search2(input2, "name=\"", "\"");
    if(fields2.size() != 1) return 1;
    string passField = fields2[0];

    mActionUrl = actionUrl;
    mUserField = userField;
    mPassField = passField;
    return 0;
}


string Parser::getActionUrl() {
    return mActionUrl;
}


string Parser::getUserField() {
    return mUserField;
}


string Parser::getPassField() {
    return mPassField;
}
