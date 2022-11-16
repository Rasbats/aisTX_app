#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <bitset>
#include <sstream>

class AisDecoder {
public:
    AisDecoder(std::string);
    virtual ~AisDecoder();
    virtual void splitMessage(std::string);
    virtual std::string vectorSearch(char);
    virtual std::string bitSlice(int, int, std::string);
    virtual std::string str2bit(std::string);
    virtual int bit2int(std::string);
    virtual std::string bit2ASCII(std::string);
    virtual std::string getMsgPart(int);
    virtual std::string getFullMsg();
private:
    std::string AisParts[7];
    std::string AisMsg;
};