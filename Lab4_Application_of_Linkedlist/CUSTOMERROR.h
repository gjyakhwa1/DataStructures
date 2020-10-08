#pragma once
//Error that can occur in linked list
#include<string>
class CUSTOMERROR
{
private:
    std::string exception;
public:
    CUSTOMERROR();
    CUSTOMERROR(std::string exception);
    std::string get_exception();
};
//methods of error class
CUSTOMERROR::CUSTOMERROR()
{
    exception = '\0';
}
CUSTOMERROR::CUSTOMERROR(std::string exception)
{
    this->exception = exception;
}
std::string CUSTOMERROR::get_exception()
{
    return exception;
}
