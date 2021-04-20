#include <string>
#include <vector>
#include "sha256.h"
#include <ctime>
#include <utility>
#include <iostream>

class BlockChain;
class Block;

class BlockChain
{
    friend Block;
public:
    static unsigned int ChainLength();

     static inline std::vector<Block> Chain;  // This is the BlockChain
    

};

class Block
{ 
    // Friend Declarations
    friend BlockChain;
    
public:
    //Constructor
    Block(const std::string& data);
    Block(const std::string& Data, bool isGen); // Genesis Block Constructor

    // Public Methods
    std::string getHash(int);

    void WriteBlock();

    static void Genesis();


private:
    // Private Members
    std::string PrevHash;
    uint32_t Index;
    std::string Data;
    std::string Time;
    std::pair<int, std::string> hash_nounce;

    // Private Methods

    Block& getLastBlock() const;

    std::pair<int, std::string> PoW();

    

    void addBlocktoChain();


};