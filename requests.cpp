#include "requests.h"
#include <curl/curl.h>


static size_t callback(void* data, size_t size, size_t nmemb, void* chunkVP) {
    size_t realsize = size * nmemb;
    string dataString(static_cast<char*>(data), realsize);
    string* chunkSP = static_cast<string*>(chunkVP);
    chunkSP->append(dataString);
    return realsize;
}


void Requests::setUrl1(std::string url) {
    mUrl1 = url;
}


string Requests::getUrl1() {
    return mUrl1;
}


void Requests::setUrl2(std::string url) {
    mUrl2 = url;
}


string Requests::getUrl2() {
    return mUrl2;
}


string Requests::getChunk() {
    return mChunk;
}


int Requests::requestGet() {
    CURL *curl;
    CURLcode res;
    string chunk;
    curl = curl_easy_init();
    if(curl == NULL) return 1;
    string url = mUrl1;
    if(mUrl2.length() > 0) url += "/" + mUrl2;
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, static_cast<void*>(&chunk));
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);
    res = curl_easy_perform(curl);
    if(res != CURLE_OK) return 1;
    curl_easy_cleanup(curl);
    mChunk = chunk;
    return 0;
}


void Requests::setNameTitle(string nameTitle) {
    mNameTitle = nameTitle;
}


string Requests::getNameTitle() {
    return mNameTitle;
}


void Requests::setNameValue(string nameValue) {
    mNameValue = nameValue;
}


string Requests::getNameValue() {
    return mNameValue;
}


void Requests::setPassTitle(string passTitle) {
    mPassTitle = passTitle;
}


string Requests::getPassTitle() {
    return mPassTitle;
}


void Requests::setPassValue(string passValue) {
    mPassValue = passValue;
}


string Requests::getPassValue() {
    return mPassValue;
}


int Requests::requestPost() {
    CURL *curl;
    CURLcode res;
    std::string chunk;
    string postfields;
    curl = curl_easy_init();
    if(curl == NULL) return 1;
    string url = mUrl1;
    if(mUrl2.length() > 0) url += "/" + mUrl2;
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    postfields = mNameTitle + "=" + mNameValue + "&" + mPassTitle + "=" + mPassValue;
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postfields.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, static_cast<void*>(&chunk));
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);
    res = curl_easy_perform(curl);
    if(res != CURLE_OK) return 1;
    curl_easy_cleanup(curl);
    mChunk = chunk;
    return 0;
}
