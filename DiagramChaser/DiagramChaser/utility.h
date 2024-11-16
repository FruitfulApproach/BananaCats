#pragma once

#include<sstream>
#include<string>


template<typename T>
std::string intToHex(T i)
{
    std::stringstream stream;
    stream << std::string("0x")
        << std::setfill('0') << std::setw(sizeof(T) * 2)
        << std::hex << i;
    return stream.str();
}

template<typename T>
std::string objectToAddressString(const T* t)
{
    auto address = (const unsigned long*)t;
    return std::string(typeid(*t).name()).substr(6, -1) + " @ " + intToHex<unsigned long>(*address);
}