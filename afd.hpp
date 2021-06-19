/**
 * @file afd.hpp
 * @author Murillo Mendonça
 * @author Abraão Duarte
 * @brief Cabeçalho da classe AFD
 * @version 0.1
 * @date 2021-06-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>

//Cabeçalho com funções de manipulação de testo desenvolvido pelos próprios alunos
#include "cpp-easy-file-stream/fs.hpp"

/**
 * @brief Classe capaz de ler e simular um Autômato Finito Determinístico
 * 
 */
class AFD{
private:
/**
 * @brief A tabela de transições do Automato
 * Dado o estado atual, Esta variável mapeia os possíveis estados futuros dependendo do simbolo de entrada 
 */
std::unordered_map<std::string,std::unordered_map<std::string,std::string>> D;

/**
 * @brief Estado inicial
 * 
 */
std::string estadoInicial;

/**
 * @brief Conjunto de todos os estados finais
 * Este conjunto contem todos os possíveis estados de aceitação
 */
std::unordered_set<std::string> estadosFinais;

/**
 * @brief Conjunto de todas as palavras de teste
 * Este conjunto contem todos as palavras de teste inseridas pelo usuário
 */
std::unordered_set<std::string> palavrasTeste;

/**
 * @brief Vetor de todos os possíveis estados
 * Este vetor contem todos os estados que o autômato pode assumir
 */
std::vector<std::string> estados;

/**
 * @brief Vetor de todos os símbolos do alfabeto
 * Este vetor contem todos os símbolos determinados pelo usuário
 */
std::vector<std::string> alfabeto;

public:

/**
 * @brief Constroi um novo objeto de AFD baseado em um arquivo de texto
 * O construtor vai ler e interpretar linha a linha as informações e definições do autômato
 * no formato disponibilizado pelo professor
 * @param arquivoAFD Caminho do arquivo de texto base para a definição do autômato
 */
AFD(std::string arquivoAFD);

/**
 * @brief Testa se uma certa palavra será aceita pelo autômato
 * 
 * @param palavra A palavra a ser testada, uma string contendo n símbolos pertencentes ao alfabeto
 * @return true Se após o processamento da palavra de entrada o autômato se encontra em um estado de aceitação
 * @return false Caso contrário
 */
bool testaPalavra(std::string palavra);

/**
 * @brief Testa todas as palavras presentes do conjunto de palavrasTeste
 * 
 */
void realizaTestes();

/**
 * @brief Escreve a tabela de transição do autômato na tela, indicando o estado inicial e os finais
 * 
 */
void mostraAFD();
};