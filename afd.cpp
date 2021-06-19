#include "afd.hpp"
#include <iostream>
#include <string>

AFD::AFD(std::string arquivoAFD){

    //Inicia a leitura do arquivo de texto recedbido
    FileStream a (arquivoAFD);

    //Na primeira linha lê-se os estados
    this->estados = a.lineValues();

    //Na segunda linha lê-se o alfabeto
    this->alfabeto = a.lineValues();

    //Para cada estado
    for(auto estado:estados){

        //Le a linha que corresponde as transições a partir do estado
        auto transicoes = a.lineValues();

        //Mapeia para qual estado cada entrada do alfabeto leva
        std::unordered_map<std::string,std::string> mapaAux;
        for(int i=0;i<alfabeto.size();i++)
            mapaAux.insert(std::pair<std::string,std::string>(alfabeto.at(i),transicoes.at(i)));

        //Insere o mapeamento na matriz de transições
        this->D.insert(std::pair<std::string,std::unordered_map<std::string,std::string>>(estado, mapaAux));
    }

    //Lê o estado inicial 
    this->estadoInicial =a.lineValues().at(0);

    //Lê os estados finais e insere no conjunto
    auto finais = a.lineValues();
    for(auto s:finais)
        this->estadosFinais.insert(s);

    //Lê a quantidade de palavras de teste
    int numeroDePalavrasDeTeste = a.nextInt();

    //Insere cada palavra de teste lida no conjunto de palavras de teste
    for(int i=0;i<numeroDePalavrasDeTeste;i++)
        this->palavrasTeste.insert(a.nextWord());
}

void AFD::mostraAFD(){
    std::cout<<"Tabela de transicoes: \n     ";
    for(auto letra:alfabeto)
        std::cout<<letra<<" ";
    std::cout<<std::endl;
    for(auto letra:alfabeto)
        std::cout<<"______";
    std::cout<<std::endl;
    for (auto d : D) {
        (estadosFinais.find(d.first) != estadosFinais.end())? std::cout<<"*":std::cout<<" ";
        (d.first==estadoInicial)? std::cout<<"+":std::cout<<" ";
        std::cout<<d.first<<"| ";
        for(auto letra:alfabeto)
            std::cout<<d.second[letra]<<" ";
        std::cout<<std::endl;
    }
    std::cout<<"\n\n* Estado final\n+ Estado inicial\n";
}

bool AFD::testaPalavra(std::string palavra){
    std::string estado = estadoInicial;                         //estado atual = estado inicial
    for(char x:palavra)                                         //Para cada símbolo da paravra de entrada
        estado=D[estado][std::string(1,x)];                     //estado atual = transicao(estado atual, prox())
    return (estadosFinais.find(estado) != estadosFinais.end()); //retorna sim se o estado após o processamento estiver contido no conjuntos dos estados finais
}

void AFD::realizaTestes(){
    for(auto palavra:palavrasTeste){                            //Para cada palavra no conjunto de palavras teste
        std::cout<<"\nA palavra "<<palavra;
        testaPalavra(palavra)?std::cout<<" foi aceita":std::cout<<" foi rejeitada";
    }
    std::cout<<std::endl;
}