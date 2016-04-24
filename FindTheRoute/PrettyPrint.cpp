//
//  PrettyPrint.cpp
//  FindTheRoute
//
//  Created by Chawasit Tengtrairat on 4/23/2559 BE.
//  Copyright © 2559 cpe24. All rights reserved.
//

#include "PrettyPrint.hpp"


void PrettyPrint::showRoute(std::queue<int> *route)
{
    
}

void PrettyPrint::showTag(Tag *tag)
{
    for(auto it=tag->begin(); it!=tag->end(); it++)
    {
        printf("[%d, %s]", it->first, it->second.c_str());
    }
}

void PrettyPrint::showDebug(Tag * tag, Node *node, Group *group, Map *map)
{
    for(auto it=tag->begin(); it!=tag->end(); it++)
    {
        printf("T[%d, %s]\n", it->first, it->second.c_str());
    }
    
    for(auto it=node->begin(); it!=node->end(); it++)
    {
        printf("N[%d, tag %d, group %d]\n", it->first, it->second.first, it->second.second);
    }
    
    for(auto it=group->begin(); it!=group->end(); it++)
    {
        printf("G[%d, %s]\n", it->first, it->second.c_str());
    }
    
}