#include <cstring>
#include "sstream"
#include "Comm.h"
class Solution {
public:
    vector<string> splitStringByFilter(const string& s, const string& filter) {
        vector<string> tokens;
        string currentToken;
        for (char c : s) {
            if (filter.find(c) == string::npos) {
                currentToken += c;
            } else {
                if (!currentToken.empty()) {
                    tokens.push_back(currentToken);
                    currentToken.clear();
                }
            }
        }
        if (!currentToken.empty()) {
            tokens.push_back(currentToken);
        }
        return tokens;
    }

    string mostCommonWord(string &paragraph, vector<string> &banned) {
        for (char& c : paragraph) {
            if (c >= 'A' && c <= 'Z') {
                c = c - 'A' + 'a';
            }
        }
        for(auto &c:paragraph){
            if(!(c>='a'&&c<='z')){
                c = ' ';
            }
        }
        unordered_map<string,int> dic;
        auto vec = splitStringByFilter(paragraph," ,.");
        for(auto&e:vec){
            ++dic[e];
        }
        for(auto &e:banned){
            dic.erase(e);
        }
        string maxFreq;
        int max = 0;
        for(auto&p : dic){
            if(p.second>max){
                maxFreq = p.first;
                max = p.second;
            }
        }
        return maxFreq;
    }
};
