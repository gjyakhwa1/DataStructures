#pragma once
#include "CUSTOMERROR.h"
class EMPTYLIST :public CUSTOMERROR
{
public:
    EMPTYLIST();
};
EMPTYLIST::EMPTYLIST() :CUSTOMERROR("Removing from empty list is not possible") {}