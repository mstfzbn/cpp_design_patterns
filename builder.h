#pragma once
#include <string>
#include <vector>

class HtmlElement
{
public:

    std::string name;
    std::string text;
    std::vector<HtmlElement> elements;

    HtmlElement() {}
    HtmlElement( const std::string& name, const std::string& text ) : name{name}, text{text} {}

    std::string str( int indent = 0 ) const
    {

        std::cout << elements[0].text << " ";
    }
};

class HtmlBuilder
{
public:

    HtmlElement root;

    HtmlBuilder( const std::string& root_name) { root.name = root_name; }

    void add_child( const std::string& child_name, const std::string& child_text)
    {
        HtmlElement e{ child_name, child_text };
        root.elements.emplace_back(e);
    }

    std::string str() { return root.str(); }

};























