#ifndef CRIATURA_H
#define CRIATURA_H

#include <string>
#include <iostream>
#include <list>
#include <memory>

class Criatura{
    public:
        Criatura(std::string subtipo);
        virtual ~Criatura();

        std::string get_subtipo();
        virtual void print_info();

        virtual std::list<std::unique_ptr<Criatura>> acasalar(std::shared_ptr<Criatura> c) = 0;

    protected:
        std::string _subtipo;

};

#endif