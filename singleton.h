#pragma once
#include "includes.h"

class Singleton
{
protected:
    Singleton(){};
public:
    static Singleton & get()
    {
        //this is thread safe, since c++11
//        static Singleton m_singleton_object;
//        return m_singleton_object;

        //heap allocation, which not cause a memory leak
        static Singleton * m_singleton_object = new Singleton;
        return * m_singleton_object;
    }

    void some_function()
    {
        printf("i'm one and only\n");
    }

    Singleton(Singleton const &) = delete;
    Singleton(Singleton &&) = delete;
    Singleton & operator=( Singleton const & ) = delete;
    Singleton & operator=( Singleton && ) = delete;
};
