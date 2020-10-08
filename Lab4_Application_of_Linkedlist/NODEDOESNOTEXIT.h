#pragma once
#include "CUSTOMERROR.h"
class NODEDOESNOTEXIST :public CUSTOMERROR
{
public:
    NODEDOESNOTEXIST();
};
NODEDOESNOTEXIST::NODEDOESNOTEXIST() :CUSTOMERROR("Trying to remove a node after a node that does not exist") {}