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
        printf("N[%d, tag %d, group %d]\n", it->first, it->second.tag, it->second.group);
    }
    
    for(auto it=group->begin(); it!=group->end(); it++)
    {
        printf("G[%d, %s]\n", it->first, it->second.c_str());
    }
    
}

void PrettyPrint::showMenu(){
    int command;
    do{
        printf("Please select the command.\n (1)FindRoute (2)Search (3)ShowAllPath");
        scanf("%d",&command);
        switch (command) {
            case 1:
                menuFindRoute();
                break;
            case 2:
                menuSearch();
                break;
            case 3:
                menuShow();
                break;
            default:
                printf("Invalid command.\n");
                break;
        }
        
    }while(command != 0);
}

void PrettyPrint::menuShow(){
}

void PrettyPrint::menuFindRoute(){
    int Start,Destination;
    scanf("%d",&Start);
    scanf("%d",&Destination);
    
}

void PrettyPrint::menuSearch(){
    char ToFind[200];
    scanf("%s",&ToFind);
    
}