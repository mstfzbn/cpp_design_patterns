#pragma once

class Singleton
{
private:
    Singleton(){};
public:
    static Singleton & get()
    {
        static Singleton m_singleton_object;
        return m_singleton_object;
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
