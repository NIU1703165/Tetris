#include <stdlib.h>
#include "InfoJoc.h"


class NodesMoviment
{
public:
    NodesMoviment() { m_next = nullptr; };
    ~NodesMoviment() {};
    NodesMoviment(const int& valor) { m_valor = valor; m_next = nullptr; }
    NodesMoviment* getNext() { return m_next; }
    void setNext(NodesMoviment* next) { m_next = next; }
    int getValor() const { return m_valor; }
    void setValor(const int& valor) { m_valor = valor; }
private:
    
    int m_valor;
    NodesMoviment* m_next;

}; 
