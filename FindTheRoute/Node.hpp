//
//  Node.hpp
//  FindTheRoute
//
//  Created by Chawasit Tengtrairat on 4/24/2559 BE.
//  Copyright © 2559 cpe24. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>
#include <string>
#include <map>

struct NodeData {
    int tag,group;
    NodeData(int t, int g):tag(t),group(g){};
};

class Node {
private:
    std::map<int, NodeData > node;
public:
    Node();
    bool add(int, int, int);
    int getTagID(int);
    int getGroupID(int);
    int getNodeByTag(int);
    int getNodeByGroup(int);
    
    std::map<int, NodeData >::iterator begin(){ return node.begin(); };
    std::map<int, NodeData >::iterator end(){ return node.end(); };
};
#endif /* Node_hpp */
