#include <string>
#include <vector>

class BlockChain
{
    friend Block;

private:
    std::vector<Block> Chain;

};

class Block
{
public:
    //Constructor
    Block(uint32_t Index, const std::string& Data);

    // Public Methods
    std::string getHash();

private:
    // Private Members
    std::string Hash;
    std::string PrevHash;
    uint32_t Index;
    int64_t nNonce;
    std::string Data;
    time_t Time;

    // Private Methods
    std::string calcHash() const;
    

};