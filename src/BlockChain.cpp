#include "BlockChain.h"

unsigned int BlockChain::ChainLength()
{
    return Chain.size()-1;
}

Block::Block(const std::string& data)
{
    Index = BlockChain::Chain.size();
    Data = data;

    std::time_t result = std::time(nullptr);
    Time = asctime(std::localtime(&result));

    PrevHash = getLastBlock().hash_nounce.second;
    hash_nounce = PoW();

}

Block::Block(const std::string& data, bool isGen)
{
    Index = 0;
    Data = data;
    std::time_t result = std::time(nullptr);
    Time = asctime(std::localtime(&result));
    PrevHash = "0";

    hash_nounce = PoW();
}

std::pair<int, std::string> Block::PoW()
{
    std::string difficulty = "00";
    int nounce = 0;
    while (true)
    {
        std::string Hnounce = getHash(nounce);
        if (Hnounce.find(difficulty) == 0)
        {
            return std::make_pair(nounce, Hnounce);
        }else {
            ++nounce;
            std::cout << "attempted" << std::endl;
        }
    }
}

std::string Block::getHash(int nounce)
{
    std::string sha = std::to_string(nounce) + std::to_string(Index) + Time + Data + PrevHash;
    return sha256(sha);
}

Block& Block::getLastBlock() const
{
    Block& bloc = BlockChain::Chain.back();
    return bloc;
}

void Block::WriteBlock()
{
    std::cout << "Block \n index: " << Index << "\n Time: " << Time
    << "\n Data: " << Data << "\n Previous Hash: " << PrevHash << "\n Nounce: " 
    << hash_nounce.first << "\n Hash: " << hash_nounce.second << std::endl;
}

void Block::addBlocktoChain()
{
    BlockChain::Chain.push_back(*this);
}

void Block::Genesis()
{
    Block GenesisBlock("First Block", true);
    GenesisBlock.addBlocktoChain();

}


