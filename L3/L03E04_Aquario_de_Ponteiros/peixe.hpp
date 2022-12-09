#ifndef PEIXE_H
#define PEIXE_H

#include "criatura.hpp"

class Peixe: public Criatura{
    public:
        Peixe(double peso, char sexo);
        virtual ~Peixe();

        double get_peso();
        char get_sexo();

        virtual void print_info() override;

        virtual std::list<std::unique_ptr<Criatura>> acasalar(std::shared_ptr<Criatura> c) override;

    protected:
        double _peso;
        char _sexo;

};

#endif