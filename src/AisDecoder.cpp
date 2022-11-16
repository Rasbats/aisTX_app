#include "AisDecoder.h"

static const std::vector<std::pair<char, std::string>> PAYLOAD_BITS = {
    {'0', "000000"}, {'1', "000001"}, {'2', "000010"}, {'3', "000011"}, {'4', "000100"},
    {'5', "000101"}, {'6', "000110"}, {'7', "000111"}, {'8', "001000"}, {'9', "001001"},
    {':', "001010"}, {';', "001011"}, {'<', "001100"}, {'=', "001101"}, {'>', "001110"},
    {'?', "001111"}, {'@', "010000"}, {'A', "010001"}, {'B', "010010"}, {'C', "010011"},
    {'D', "010100"}, {'E', "010101"}, {'F', "010110"}, {'G', "010111"}, {'H', "011000"},
    {'I', "011001"}, {'J', "011010"}, {'K', "011011"}, {'L', "011100"}, {'M', "011101"},
    {'N', "011110"}, {'O', "011111"}, {'P', "100000"}, {'Q', "100001"}, {'R', "100010"},
    {'S', "100011"}, {'T', "100100"}, {'U', "100101"}, {'V', "100110"}, {'W', "100111"},
    {'`', "101000"}, {'a', "101001"}, {'b', "101010"}, {'c', "101011"}, {'d', "101100"},
    {'e', "101101"}, {'f', "101110"}, {'g', "101111"}, {'h', "110000"}, {'i', "110001"},
    {'j', "110010"}, {'k', "110011"}, {'l', "110100"}, {'m', "110101"}, {'n', "110110"},
    {'o', "110111"}, {'p', "111000"}, {'q', "111001"}, {'r', "111010"}, {'s', "111011"},
    {'t', "111100"}, {'u', "111101"}, {'v', "111110"}, {'w', "111111"}
};

AisDecoder::AisDecoder(std::string s):AisMsg (s) {

}

AisDecoder::~AisDecoder() {

}

//Split the given AIS messages into the sections split by a comma. returns the given section number
void AisDecoder::splitMessage(std::string message) {
    std::string s = "";
    int i = 0;
    int j = 0;
    for (auto x : message) {
        if (x == ',') {
            AisParts[i] = s;
            i++;
            s = "";
        }
        else {
            s += x;
        }
    }
    AisParts[i] = s;
}

//Searches the vector PAYLOAD_BITS for the bit string belonging to the given char
std::string AisDecoder::vectorSearch(char mp) {
    auto i = std::find_if(PAYLOAD_BITS.begin(), PAYLOAD_BITS.end(), [mp](const std::pair<char, std::string> p) {
        return p.first == mp;
    });
    return i != PAYLOAD_BITS.end() ? i->second : "";
}

//Slices the given bit array from/untill a given points
std::string AisDecoder::bitSlice(int startINT, int endINT, std::string payload) {
    std::string returnString;
    for (int i = startINT; i < endINT; i++) {
        returnString += payload[i];
    }
    return returnString;
}

//Turns the given string into bits
std::string AisDecoder::str2bit(std::string payload) {
    std::string returnString;
    for (int i = 0; i <= payload.length() - 1; i++) {
        std::string conv = vectorSearch(payload[i]);
        returnString += conv;
    }
    return returnString;
}

//Converts bits into intergers
int AisDecoder::bit2int(std::string bits) {
    int tempInt;
    int num = 0;
    for (int i = 0; i < bits.length(); i++) {
        tempInt = bits[i] - '0';
        num = num + tempInt * pow(2, (bits.length() - 1 - i));
    }
    return num;
}

//Converts bits into ASCII characters
std::string AisDecoder::bit2ASCII(std::string s) {
    std::stringstream sstream(s);
    std::string output;
    while (sstream.good()) {
        std::bitset<8> bits;
        sstream >> bits;
        char c = char(bits.to_ulong());
        output += c;
    }
    return output;
}

//Returns full AIS message currently being decoded
std::string AisDecoder::getFullMsg() {
    return AisMsg;
}

//Returns Part of the AIS message currently beinf decoded
std::string AisDecoder::getMsgPart(int i) {
    return AisParts[i];
}