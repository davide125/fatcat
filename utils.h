#ifndef _FATCAT_UTILS_H
#define _FATCAT_UTILS_H

#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

// Utils
#define FAT_READ_SHORT(buffer,x) ((buffer[x]&0xff)|((buffer[x+1]&0xff)<<8))
#define FAT_READ_LONG(buffer,x) \
        ((buffer[x]&0xff)|((buffer[x+1]&0xff)<<8))| \
        (((buffer[x+2]&0xff)<<16)|((buffer[x+3]&0xff)<<24))

// trim from start
static inline std::string ltrim(std::string s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
        return s;
}

// trim from end
static inline std::string rtrim(std::string s) {
        s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
        return s;
}

// trim from both ends
static inline std::string trim(std::string s) {
        return ltrim(rtrim(s));
}

// split a string into vector
static inline vector<string> &split(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while(getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

#endif // _FATCAT_UTILS_H