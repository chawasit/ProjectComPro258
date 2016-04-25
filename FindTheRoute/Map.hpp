//
//  Map.hpp
//  FindTheRoute
//
//  Created by Chawasit Tengtrairat on 4/22/2559 BE.
//  Copyright © 2559 cpe24. All rights reserved.
//

#ifndef Map_hpp
#define Map_hpp

#include <cstdio>
#include <vector>
#include <string>
#include <limits>
#include <queue>

struct Edge {
    int from, to , weight;
    Edge(int f, int t, int w):from(f), to(t), weight(w) {};
};

class Map {
private:
    std::vector<Edge> paths;
    int nodes;
    int** map;
    int** next;
    bool calculated;
public:
    Map();
    ~Map();
    int** getMap(){ return map; };
    int** getNext(){ return next; };
    int getNode(){ return nodes; };
    void setNode(int n){nodes = n;};
    
    void addPath(int, int, int); // from, to, weight
    void addPath(int, int); // from, to, weight = 0
    void clearPath();
    
    void createMap();
    void destroyMap();
    void init();
    void floyd_warshall();
    
    bool isCalculated();
    std::queue<int> getRoute(int, int);
};


#endif /* Map_hpp */
