#pragma once
#include <string>
#include <vector>
#include <memory>

class HtmlBuilder
{
public:

    class HtmlElement
    {
    public:

        std::string name;
        std::string text;
        std::vector<HtmlElement> elements;

        //communicating intent
        static std::unique_ptr<HtmlBuilder> build( const std::string& root_name )
        {
            return std::make_unique<HtmlBuilder>( root_name );
        }

        std::string echo( int indent = 0 ) const
        {
            std::string to_return{};

            for( size_t i{0}; i < elements.size(); ++i )
            {
                to_return += elements[i].text + " ";
            }

            return to_return;
        }

    public:

        HtmlElement() {}
        HtmlElement( const std::string& name, const std::string& text ) : name{name}, text{text} {}
    };

public:

    HtmlElement root;

    HtmlBuilder( const std::string& root_name ) { root.name = root_name; }

    void add_child( const std::string& child_name, const std::string& child_text )
    {
        HtmlElement e{ child_name, child_text };
        root.elements.emplace_back(e);
    }

    //fluent interface /operator.
    HtmlBuilder& add_child_chained( const std::string& child_name, const std::string& child_text )
    {
        HtmlElement e{ child_name, child_text };
        root.elements.emplace_back(e);
        return *this;
    }

    // /operator->
    HtmlBuilder* add_child_chained_arrow_operator( const std::string& child_name, const std::string& child_text )
    {
        HtmlElement e{ child_name, child_text };
        root.elements.emplace_back(e);
        return this;
    }
    ////

    std::string echo() { return root.echo(); }

};



//Composite Builder
/*
class Person
{
    //address
    std::string m_street_address, m_post_code, m_city;

    //employment
    std::string m_company_name, m_position;
    int m_annual_income{0};

    Person() {}
};

class PersonBuilderBase
{
protected:
    Person& m_person;
    explicit PersonBuilderBase( Person& person ) : m_person{person} {}

public:
    operator Person()
    {
        return std::move( m_person );
    }

    //builder facets
    PersonAddressBuilder lives() const;
    PersonJobBuilder works() const;

};
*/





























































































