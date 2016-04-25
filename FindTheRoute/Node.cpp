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
    NodeData data(tag, group);
//    node[id] = data;
    node.insert(std::make_pair(id, data));
    return true;
}

int Node::getTagID(int id)
{
    auto it = node.find(id);
    if(it!=node.end())
    {
        return it->second.tag;
    }else{
        return -1;
    }
}

int Node::getGroupID(int id)
{
    auto it = node.find(id);
    if(it!=node.end())
    {
        return it->second.group;
    }else{
        return -1;
    }
}

int Node::getNodeByTag(int tag)
{
    for(auto it = node.begin(); it!=node.end();it++)
    {
        if(it->second.tag==tag)
            return it->first;
    }
    return -1;
}

int Node::getNodeByGroup(int group)
{
    for(auto it = node.begin(); it!=node.end();it++)
    {
        if(it->second.group==group)
            return it->first;
    }
    return -1;
}