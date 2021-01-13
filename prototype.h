#pragma once
#include "includes.h"

struct Address
{
    std::string street, city;
    int suite;
};

struct Contact
{
    std::string name;
    Address* address;
    //std::shared_ptr<Address> address;

    Contact( const Contact& rhs) : name{ rhs.name }
    {
        address = new Address
        {
                rhs.address->street,
                rhs.address->city,
                rhs.address->suite
        };
    };

    Contact( const std::string name, const Address* rhs) : name{ name }
    {
        address = new Address
        {
                rhs->street,
                rhs->city,
                rhs->suite
        };
    };

    Contact& operator=( const Contact& rhs)
    {
        if(this == &rhs)
        {
            return *this;
        }

        this->name = rhs.name;
        this->address = rhs.address;

        return *this;
    };

};


