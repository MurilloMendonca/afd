#pragma once

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include "cpp-easy-file-stream/fs.hpp"
class AFD{
private:
std::unordered_map<std::string,std::unordered_map<std::string,std::string>> D;
std::string estadoInicial;
std::unordered_set<std::string> estadosFinais;
std::unordered_set<std::string> palavrasTeste;
std::vector<std::string> estados;
std::vector<std::string> alfabeto;

public:
AFD(std::string arquivoAFD);
bool testaPalavra(std::string palavra);
void realizaTestes();
void mostraAFD();
};