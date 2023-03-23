#ifndef REQUESTS_H
#define REQUESTS_H

#include <iostream>
using namespace std;


class Requests {
    private:
        string mUrl1;
        string mUrl2;
        string mChunk;
        string mNameTitle;
        string mNameValue;
        string mPassTitle;
        string mPassValue;
        
    public:
        void setUrl1(string url);
        string getUrl1();
        void setUrl2(string url);
        string getUrl2();
        string getChunk();
        int requestGet();
        void setNameTitle(string nameTitle);
        string getNameTitle();
        void setNameValue(string nameValue);
        string getNameValue();
        void setPassTitle(string passTitle);
        string getPassTitle();
        void setPassValue(string passValue);
        string getPassValue();
        int requestPost();
};


#endif // REQUESTS_H
