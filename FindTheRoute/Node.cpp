//
//  Node.cpp
//  FindTheRoute
//
//  Created by Chawasit Tengtrairat on 4/24/2559 BE.
//  Copyright © 2559 cpe24. All rights reserved.
//

#include "Node.hpp"

Node::Node()
{
    
}

bool Node::add(int id, int tag, int group)
{
    node[id] = std::pair<int, int>(tag, group);
    return true;
}

int Node::getTagID(int id)
{
    auto it = node.find(id);
    if(it!=node.end())
    {
        return it->second.first;
    }else{
        return -1;
    }
}

int Node::getGroupID(int id)
{
    auto it = node.find(id);
    if(it!=node.end())
    {
        return it->second.second;
    }else{
        return -1;
    }
}