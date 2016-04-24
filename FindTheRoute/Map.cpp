//
//  Map.cpp
//  FindTheRoute
//
//  Created by Chawasit Tengtrairat on 4/22/2559 BE.
//  Copyright © 2559 cpe24. All rights reserved.
//

#include "Map.hpp"

Map::Map()
{
    nodes = 0;
    calculated = false;
    map = NULL;
    next = NULL;
}

Map::~Map()
{
    if(map or next)
        destroyMap();
}

void Map::addPath(int from, int to, int weight)
{
    Edge add(from, to, weight);
    paths.push_back(add);
}

void Map::addPath(int from, int to)
{
    addPath(from, to, 10);
}

void Map::createMap()
{
    map = new int*[nodes];
    next = new int*[nodes];
    for (int i=0; i<nodes; i++) {
        map[i] = new int[nodes];
        next[i] = new int[nodes];
    }
}

void Map::destroyMap()
{
    for (int i=0; i<nodes; i++) {
        delete[] map[i];
        delete[] next[i];
    }
    delete[] map;
    delete[] next;
    map = next = NULL;
}

void Map::init()
{
    for (int i=0; i<nodes; i++) {
        for (int j=0; j<nodes; j++) {
            map[i][j] = std::numeric_limits<int>::max();
            next[i][j] = j;
        }
    }
    int f,t,w;
    for (int i=0; i<paths.size(); i++) {
        f = paths[i].from;
        t = paths[i].to;
        w = paths[i].weight;
        map[f][t] = w;
    }
}

void Map::floyd_warshall()
{
    int dist;
    for (int k=0; k<nodes; k++) {
        for (int i=0; i<nodes; i++) {
            for (int j=0; j<nodes; j++) {
                dist = map[i][k] + map[k][j];
                if(dist<map[i][j])
                {
                    map[i][j] = dist;
                    next[i][j] = next[i][k];
                }
            }
        }
    }
    calculated = true;
}

bool Map::isCalculated()
{
    return calculated;
}

std::queue<int>* Map::getRoute(int from, int to)
{
    std::queue<int>* route = new std::queue<int>;
    if(next[from][to] == -1)
        return route;
    route->push(from);
    while(from!=to)
    {
        from = next[from][to];
        route->push(from);
    }
    return route;
}