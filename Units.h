#pragma once

#include <string>


namespace units 
{

    class Unit
    {
    public:
        std::string name;
    };

    class Town : public virtual Unit
    {
    public:
        Town(std::string name_inp)
        {
            this->name = name_inp;
        }
        Town() {}
    };

    class Region : public virtual Unit
    {
    protected:
        std::string level_name()
        {
            return "region";
        }
        virtual std::string level_name_virtual()
        {
            return "region";
        }

    public:
        Region(std::string name_inp)
        {
            this->name = name_inp;
        }
        Region() {}
        std::string get_level_name()
        {
            return level_name();
        }
        std::string get_level_name_virtual()
        {
            return level_name_virtual();
        }
    };

    class Capital : public Town, Region
    {
    public:
        Capital(Town* town_inp) : Town(), Region(), Unit()
        {
            this->name = town_inp->name;
        }
    };

    class County : public Region
    {
    protected:
        std::string level_name()
        {
            return "county";
        }
        virtual std::string level_name_virtual()
        {
            return "county";
        }

    public:
        County(std::string name_inp)
        {
            this->name = name_inp;
        }
        County() {}
        std::string get_level_name()
        {
            return level_name();
        }
        std::string get_level_name_virtual()
        {
            return level_name_virtual();
        }
    };

    class Metropolitan_county : private County
    {
    public:
        Metropolitan_county(std::string name_inp)
        {
            this->name = name_inp;
        }
        std::string get_name()
        {
            return this->name;
        }
    };

    class Shire : protected County
    {
    public:
        Shire(std::string name_inp)
        {
            this->name = name_inp;
        }
        Shire() {}
    };

    class Rural_shire : public Shire
    {
    public:
        Rural_shire(std::string name_inp)
        {
            this->name = name_inp;
        }
        std::string get_name()
        {
            return this->name;
        }
    };

    class Unitary_authority : public County
    {
    public:
        Unitary_authority(std::string name_inp)
        {
            this->name = name_inp;
        }
    };

}
