#include "BlockChain.h"
#include <iostream>

int main()
{
    Block::Genesis();
    std::cout << BlockChain::ChainLength() << std::endl;
}