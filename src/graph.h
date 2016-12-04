////////////////////////////////////////////////////////////////////////////////////
// GRAPH
// Author: Pranshu Gupta

struct VERTEX {
    double value;
    list<VERTEX*> neighbors;
    list<double> edgeWeights;
};

class GRAPH {
    public:
        list<VERTEX*> vertices;
        
}