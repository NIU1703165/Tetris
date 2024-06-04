#include "NodesMoviment.h"

class LlistaMoviments
{
public:
	LlistaMoviments() { m_primer = nullptr; }
	~LlistaMoviments();
	LlistaMoviments(const LlistaMoviments& x);
	LlistaMoviments& operator=(const LlistaMoviments& x);
	NodesMoviment* insereix(const int& mov);
	void elimina();
	int getNElements() const;
	int getPrimer() const { return m_primer->getValor(); }
	bool esBuida() const { return m_primer == nullptr; }

private:
	NodesMoviment* m_primer;
	NodesMoviment* m_ultim;
};
