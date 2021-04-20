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

protected:
    static std::vector<Block> Chain;    // This is the BlockChain
    

};

class Block
{ 
    // Friend Declarations
    friend BlockChain;
    
public:
    //Constructor
    Block(const std::string& Data);

    // Public Methods
    std::string getHash(int);

    static void Genesis();


private:
    // Private Members
    std::string PrevHash;
    uint32_t Index;
    std::string Data;
    std::string Time;
    std::pair<int, std::string> hash_nounce;

    // Private Methods
    std::string calcHash() const;

    Block& getLastBlock() const;

    std::pair<int, std::string> PoW();

    void WriteBlock();

    void addBlocktoChain();


};