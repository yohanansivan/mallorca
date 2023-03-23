#include <iostream>
#include <cstring>
#include <vector>
#include "requests.h"
#include "parser.h"

using namespace std;


int example1() {
    Requests request;
    request.setUrl1("http://localhost:5000");
    request.setUrl2("login");
    request.requestGet();
    cout << "Return:" << endl << request.getChunk() << endl;
    return 0;
}


int example2() {
    Requests request;
    request.setUrl1("http://localhost:5000");
    request.setUrl2("login");
    request.setNameTitle("uname");
    request.setNameValue("myname");
    request.setPassTitle("pass");
    request.setPassValue("mypass");
    request.requestPost();
    cout << "Return:" << endl << request.getChunk() << endl;
    return 0;
}


int example3() {
    Requests request;
    request.setUrl1("http://testphp.vulnweb.com");
    request.setUrl2("login.php");
    request.requestGet();
    cout << "Return:" << endl << request.getChunk() << endl;
    return 0;
}


int example4() {
    Requests request;
    request.setUrl1("http://testphp.vulnweb.com");
    request.setUrl2("userinfo.php");
    request.setNameTitle("uname");
    request.setNameValue("test");
    request.setPassTitle("pass");
    request.setPassValue("test");
    request.requestPost();
    cout << "Return:" << endl << request.getChunk() << endl;
    return 0;
}


int example5() {
    Requests request;
    Parser parser;
    // Getting the login html
    request.setUrl1("http://testphp.vulnweb.com");
    request.setUrl2("login.php");
    request.requestGet();
    // Parsing the login html
    parser.setChunk(request.getChunk());
    int ok = parser.customSearch();
    if(ok != 0) return 1;
    // Posting
    request.setUrl2(parser.getActionUrl());
    request.setNameTitle(parser.getUserField());
    request.setNameValue("test");
    request.setPassTitle(parser.getPassField());
    request.setPassValue("test");
    request.requestPost();
    cout << "Return:" << endl << request.getChunk() << endl;
    return 0;
}


int main() {
    cout << "Main start" << endl;
    int res = example5();
    return res;
}
