//
//  PrettyPrint.cpp
//  FindTheRoute
//
//  Created by Chawasit Tengtrairat on 4/23/2559 BE.
//  Copyright © 2559 cpe24. All rights reserved.
//

#include "PrettyPrint.hpp"

PrettyPrint::PrettyPrint(Tag* t, Node* n, Group* g, Map* m)
{
    tag = t;
    node = n;
    group = g;
    map = m;
}

void PrettyPrint::showRoute(std::queue<int> *route)
{
    
}

void PrettyPrint::showTag()
{
    for(auto it=tag->begin(); it!=tag->end(); it++)
    {
        printf("[%d, %s]\n", it->first, it->second.c_str());
    }
}

void PrettyPrint::showDebug()
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
        printf("Please select the command.\n (1)FindRoute (2)Search (3)ShowAllPath\nSelect: ");
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
    printf("Please Input where to start:");
    scanf("%d",&Start);
    printf("Please Input destination:");
    scanf("%d",&Destination);
}

void PrettyPrint::menuSearch(){
    char ToFind[200];
    printf("Please Input tag name:");
    scanf("%s",ToFind);
    std::string find(ToFind);
    std::vector<std::pair<int, std::string> > found = tag->search(find);
    for(int i=0;i<found.size();i++)
    {
        printf("[%d %s] ", found[i].first, found[i].second.c_str());
    }
}