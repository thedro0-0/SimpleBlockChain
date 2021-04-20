#include "BlockChain.h"

Block::Block(uint32_t index, const std::string& data)
{
    Index = index;
    Data = data;

    std::time_t result = std::time(nullptr);
    Time = asctime(std::localtime(&result));

    PrevHash = getLastBlock().hash_nounce.second;
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

