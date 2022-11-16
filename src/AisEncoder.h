#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <bitset>
#include <sstream>

class AisEncoder {
public:
    AisEncoder(std::string, int, int, std::string);
    virtual ~AisEncoder();
    virtual void buildMessage();
    virtual std::string generateChecksum(std::string);
    virtual void splitMessage(std::string);
    virtual char vectorSearch(std::string);
    virtual std::string bitSlice(int, int, std::string);
    virtual std::string bit2str(std::string);
    virtual std::string int2bit(int, int);
    virtual std::string ASCII2bit(char);
    virtual std::string ASCII2bitString(std::string);
    virtual void setMsgPart(std::string, int);
    virtual std::string getMsgPart(int);
    virtual void setFullMsg(std::string);
    virtual std::string getFullMsg();
    virtual void setDAC(int i);
    virtual void setFI(int i);
private:
    std::string AisParts[8];
    std::string AisMsg = "";
    std::string MSG = "";
    int DAC = 0;
    int FI = 0;
    std::string payloadText = "";
};