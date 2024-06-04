#include <stdlib.h>
#include "InfoJoc.h"
#include "Figura.h"

typedef struct
{
    TipusFigura tipus;
    int fila;
    int columna;
    int gir;
} Fdoc;

class NodesFigura
{
public:
    NodesFigura() { m_next = nullptr; };
    ~NodesFigura() {};
    NodesFigura(const Fdoc& valor) { m_valor = valor; m_next = nullptr; }
    NodesFigura* getNext() { return m_next; }
    void setNext(NodesFigura* next) { m_next = next; }
    Fdoc getValor() { return m_valor; }
    void setValor(const Fdoc& valor) { m_valor = valor; }
private:
    Fdoc m_valor;
    NodesFigura* m_next;
};
