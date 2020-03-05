# pragma once

#include <memory>

class Salad
{
    public:
    Salad(float c, float p, float w) : calories(c), price(p), weight(w){}
    virtual std::string print_salad_name() = 0;
    float get_calories()
    {
        return calories*weight;
    };
    float get_price()
    {
        return price*weight;
    };
    float get_weight()
    {
        return weight;
    };

    float calories;
    float price;
    float weight;
};

using salad_ref = std::unique_ptr<Salad>;

class Greek : public Salad
{
    public:
    Greek(float c, float p, float w) : Salad(c,p,w){}
    std::string print_salad_name() override
    {
        return "Greek";
    }
};

class Potatoe : public Salad
{
    public:
    Potatoe(float c, float p, float w) : Salad(c,p,w){}
    std::string print_salad_name() override
    {
        return "Potatoe";
    }
};

class Creator
{
    public:
    virtual salad_ref create() = 0;
};

class GreekCreator : public Creator
{
    public:
    salad_ref create() override;
};

class PotatoeCreator : public Creator
{
    public:
    salad_ref create() override;
};