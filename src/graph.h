////////////////////////////////////////////////////////////////////////////////////
// GRAPH ALGORITMS
// Author: Pranshu Gupta
// Adjacency List based implementation

struct VERTEX {
    double value;
    list<VERTEX*> neighbors;
    list<double> edgeWeights;
};

class GRAPH {
    public:
        list<VERTEX*> vertices;
};