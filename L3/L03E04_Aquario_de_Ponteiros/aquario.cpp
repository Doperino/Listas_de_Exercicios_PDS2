#include "aquario.hpp"

void Aquario::add_peixe(double peso, char sexo) {
    _criaturas.push_back(std::shared_ptr<Peixe>(new Peixe(peso, sexo)));
}

void Aquario::add_polvo(double qi) {
    _criaturas.push_back(std::shared_ptr<Polvo>(new Polvo(qi)));
}

void Aquario::acasalamento(int id1, int id2) {
    int num_animais_aquario = _criaturas.size();
    
    if (id1 >= num_animais_aquario || id2 >= num_animais_aquario)
        return;

    std::list<std::unique_ptr<Criatura>> lista_filhotes;
  
    lista_filhotes = _criaturas[id1]->acasalar(_criaturas[id2]); 

    std::shared_ptr<Criatura> filhote;
    
  
    std::list<std::unique_ptr<Criatura>>::iterator it;
    for(it = lista_filhotes.begin(); it != lista_filhotes.end(); ++it) {
        filhote = std::move(*it);
        _criaturas.push_back(filhote);
    }
}

void Aquario::print() {
    std::cout << "=============" << std::endl;
    std::cout << "Aquario Info:" << std::endl;
    
    for (auto n : _criaturas) {
        n->print_info();
    }

    std::cout << "=============" << std::endl;
}

/*
Aquario::Aquario(const Aquario &orig) {

    std::shared_ptr<Criatura> p;
    for (auto n : orig._criaturas) {
        
        p = std::move(n);
        _criaturas.push_back(p);
    }
}
*/

Aquario::Aquario(const Aquario &orig) {

    
    for (auto n : orig._criaturas) {

        std::string subtipo_criatura = n->get_subtipo();

        if (subtipo_criatura == "Peixe") {

            std::shared_ptr<Criatura> criatura = new Criatura();
        }

        else {
         

 
        }
    }
}

/*
Aquario::Aquario(const Aquario &orig) {

    
    for (auto n : orig._criaturas) {

        std::string subtipo_criatura = n->get_subtipo();

        if (subtipo_criatura == "Peixe") {

            std::shared_ptr<Peixe> p;
            p = std::dynamic_pointer_cast<Peixe>(n);

            double peso_peixe = p->get_peso();
            char sexo_peixe = p->get_sexo();
            _criaturas.push_back(std::shared_ptr<Peixe>(new Peixe(peso_peixe, sexo_peixe)));
        }

        else {
            std::shared_ptr<Polvo> p;
            p = std::dynamic_pointer_cast<Polvo>(n);

            double qi_polvo = p->get_qi();

            _criaturas.push_back(std::shared_ptr<Polvo>(new Polvo(qi_polvo)));
 
        }
    }
}
*/