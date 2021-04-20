#include <string>
#include <vector>
#include "sha256.h"
#include <ctime>
#include <utility>

class BlockChain;
class Block;

class BlockChain
{
    friend Block;

protected:
    static std::vector<Block> Chain;

};

class Block
{
    friend BlockChain;
public:
    //Constructor
    Block(uint32_t Index, const std::string& Data);

    // Public Methods
    std::string getHash(int);

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

};