#include "AisEncoder.h"

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

static const std::vector<std::pair<std::string, char>> asc = { 
    {"101100", ','}, {"000000", '@'}, {"000001", 'A'}, {"000010", 'B'}, {"000011", 'C'},
    {"000100", 'D'}, {"000101", 'E'}, {"000110", 'F'}, {"000111", 'G'}, {"001000", 'H'},
    {"001001", 'I'}, {"001010", 'J'}, {"001011", 'K'}, {"001100", 'L'}, {"001101", 'M'},
    {"001110", 'N'}, {"001111", 'O'}, {"010000", 'P'}, {"010001", 'Q'}, {"010010", 'R'},
    {"010011", 'S'}, {"010100", 'T'}, {"010101", 'U'}, {"010110", 'V'}, {"010111", 'W'},
    {"011000", 'X'}, {"011001", 'Y'}, {"011010", 'Z'}, {"011011", '['}, {"011100", '\\'},
    {"011101", ']'}, {"011110", '^'}, {"011111", '_'}, {"100000", ' '}, {"100001", '!'},
    {"100010", '\''},{"100011", '#'}, {"100100", '$'}, {"100101", '%'}, {"100110", '&'},
    {"100111", '\''},{"101000", '('}, {"101001", ')'}, {"101010", '*'}, {"101011", '+'},
    {"101101", '-'}, {"101110", '.'}, {"101111", '/'}, {"110000", '0'}, {"110001", '1'},
    {"110010", '2'}, {"110011", '3'}, {"110100", '4'}, {"110101", '5'}, {"110110", '6'},
    {"110111", '7'}, {"111000", '8'}, {"111001", '9'}, {"111010", ':'}, {"111011", ';'},
    {"111100", 'Lt'},{"111101", '='}, {"111110", '>'}, {"111111", '?'} 
};

AisEncoder::AisEncoder(std::string msg, int fi, int dac, std::string s) {
    MSG = msg;
    FI = fi;
    DAC = dac;
    payloadText = s;
    buildMessage();
}

AisEncoder::~AisEncoder() {

}

void AisEncoder::buildMessage() {
    setFullMsg("!xxBBM,1,1,0,1,8,,0*");
    splitMessage(getFullMsg());
    setMsgPart(MSG, 5);

    std::string bitstr = "";
    bitstr += int2bit(10, DAC);         //DAC number
    bitstr += int2bit(6, FI);           //FI number
    bitstr += "000";                    //Version indicator
    bitstr += "001110";                 //UN country code N
    bitstr += "001100";                 //UN country code L
    bitstr += int2bit(17, 201);         //Fairway section
    bitstr += ASCII2bitString("05397");        //Object code
    bitstr += int2bit(17, 267);         //Fairway hectometre
    bitstr += "0";                      //Spare
    bitstr += ASCII2bitString(payloadText);   //Text input
    bitstr += "0000";                   //Spare

    setMsgPart(bit2str(bitstr), 6);
    setMsgPart(generateChecksum(getFullMsg()), 7);
}

//Generates the checksum from given string.
std::string AisEncoder::generateChecksum(std::string s) {
    int sum = 0;
    
    //XOR the string.
    for (int i = 1; i <= s.length() - 2; i++) {
        sum = sum ^ s[i];
    }
    
    //Convert to hex.
    std::stringstream sstream;
    sstream << std::hex << sum;
    std::string result = sstream.str();
    
    //Letters to caps.
    transform(result.begin(), result.end(), result.begin(), ::toupper);
    
    //Adds 0 before a single digit.
    if (result.length() <= 1) {
        result = "0" + result;
    }
    return result;
}

//Split the given AIS messages into the sections split by a comma. returns the given section number.
void AisEncoder::splitMessage(std::string message) {
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

//Searches the vector PAYLOAD_BITS for the bit string belonging to the given char.
char AisEncoder::vectorSearch(std::string mp) {
    auto i = std::find_if(PAYLOAD_BITS.begin(), PAYLOAD_BITS.end(), [mp](const std::pair<char, std::string> p) {
        return p.second == mp;
    });
    return i != PAYLOAD_BITS.end() ? i->first : ' ';
}

//Slices the given bit array from/untill a given points.
std::string AisEncoder::bitSlice(int startINT, int endINT, std::string payload) {
    std::string returnString;
    for (int i = startINT; i < endINT; i++) {
        returnString += payload[i];
    }
    return returnString;
}

//Turns the given string into bits.
std::string AisEncoder::bit2str(std::string payload) {
    std::string returnString;
    std::string bitstring;
    std::string conv;
    for (int i = 0; i <= payload.length() - 6; i+=6) {
        bitstring = bitSlice(i, i + 6, payload);
        conv = vectorSearch(bitstring);
        returnString += conv;
    }
    return returnString;
}

//Converts bits into intergers. bitset must have a constant value, therefor switchcase.
std::string AisEncoder::int2bit(int bitSize, int i) {
    std::string s = "";

    switch (bitSize) {
    case 6:
        s = std::bitset<6>(i).to_string();
        break;
    case 8:
        s = std::bitset<8>(i).to_string();
        break;
    case 10:
        s = std::bitset<10>(i).to_string();
        break;
    case 17:
        s = std::bitset<17>(i).to_string();
        break;
    case 30:
        s = std::bitset<17>(i).to_string();
        break;
    default:
        std::cout << "No such bitSize found!" << std::endl;
        s = "ERROR";
        break;
    }   
    return s;
}

//Converts ASCII characters into bit characters.
std::string AisEncoder::ASCII2bit(char c) {
    auto i = std::find_if(asc.begin(), asc.end(), [c](const std::pair<std::string, char> p) {
        return p.second == c;
        });
    return i != asc.end() ? i->first : " ";
}

std::string AisEncoder::ASCII2bitString(std::string s) {
    std::string returnstring = "";
    for (int i = 0; i < s.length(); i++) {
        returnstring += ASCII2bit(s[i]);
    }
    return returnstring;
}

//Sets a part of the AIS message to the given string.
void AisEncoder::setMsgPart(std::string s, int i) {
    if(i == 7)
        AisParts[i] = AisParts[7] + s;
    else
        AisParts[i] = s;
    AisMsg = "";
    for (int f = 0; f <= 7; f++) {
        if (f < 7) 
            AisMsg += AisParts[f] + ',';
        else 
            AisMsg += AisParts[f];
    }
}

//Returns Part of the AIS message currently beinf decoded.
std::string AisEncoder::getMsgPart(int i) {
    return AisParts[i];
}


//Set the full AIS message to be the given string.
void AisEncoder::setFullMsg(std::string s) {
    AisMsg = s;
}

//Returns full AIS message currently being decoded.
std::string AisEncoder::getFullMsg() {
    return AisMsg;
}

void AisEncoder::setDAC(int i) {
    DAC = i;
}

void AisEncoder::setFI(int i) {
    FI = i;
}