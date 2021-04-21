#include "BlockChain.h"
#include <iostream>

int main()
{
    Block::Genesis();
    std::cout << BlockChain::ChainLength() << std::endl;

    std::cout << "Would you like to Mine a block. y/n " << std::endl;
    std::string input;
    std::cin >> input;

    if (input == "y")
    {
        MineBlock("data");
    }else
    {
        return;
    }

    for (Block& v : BlockChain::Chain)
    {
        v.WriteBlock();
    }
}