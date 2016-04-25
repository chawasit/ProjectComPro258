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
        printf("Please select the command.\n (1)FindRoute (2)Search Location (3)Show All Location (0)Exit\nSelect: ");
        scanf("%d",&command);
        switch (command) {
            case 1:
                menuFindRoute();
                break;
            case 2:
                menuSearch();
                break;
            case 3:
                menuShowAll();
                break;
            case 0:
                break;
            default:
                printf("Invalid command.\n");
                break;
        }
        
    }while(command != 0);
    printf("By bye :D");
}

void PrettyPrint::menuFindRoute(){
    int Start,Destination;
    printf("Please Input where to start: ");
    scanf("%d",&Start);
    printf("Please Input destination: ");
    scanf("%d",&Destination);
    std::vector<int> from=node->getNodeByTag(Start),
                     to=node->getNodeByTag(Destination);
//    std::vector< std::pair<int, std::queue<int>>> result;
    int** distance = map->getMap();
    int current_from, current_to, route_distance;
    int current_group;
    
    for(int i=0;i<from.size();i++)
        printf("FROM %d %s\n", from[i], tag->getName(node->getTagID(from[i])).c_str());
    for(int j=0;j<to.size();j++)
        printf("TO %d %s\n", to[j], tag->getName(node->getTagID(to[j])).c_str());
    
    
    if(from.size()>0 and to.size()>0)
    {
        for(int i=0;i<from.size();i++)
        {
            for(int j=0;j<to.size();j++)
            {
                route_distance = distance[from[i]][to[j]];
                if(route_distance==99999999)
                    continue;
                std::queue<int> *route = map->getRoute(from[i], to[j]);
                if(!route->empty())
                {
                    current_from = route->front();
                    route->pop();
                    current_group = node->getGroupID(current_from);
                    printf("[+] %s [%5s> ",
                           tag->getName(node->getTagID(current_from)).c_str(),
                           group->get(current_group).c_str());
                }
                while(!route->empty())
                {
                    current_to = route->front(); route->pop();
//                    printf("%d->", current_from);
                    if(current_group!=node->getGroupID(current_to))
                    {
                        current_group = node->getGroupID(current_to);
                        printf("%s [%5s> ",
                               tag->getName(node->getTagID(current_from)).c_str(),
                               group->get(current_group).c_str() );
                    }
                    current_from = current_to;
                }
                
//                while(!route->empty())
//                {
//                    current_to = route->front(); route->pop();
//                    printf("%d->", current_to);
//                }
                delete route;
                printf("%s\n[+] Distance %dm\n",
                        tag->getName(node->getTagID(current_from)).c_str(),
                        route_distance );
            }
        }
    }else{
        printf("[-] Invalid Tag\n");
    }
}

void PrettyPrint::menuSearch(){
    char ToFind[200];
    printf("Please Input tag name:");
    scanf("%s",ToFind);
    std::string find(ToFind);
    std::vector<std::pair<int, std::string> > found = tag->search(find);
    for(int i=0;i<found.size();i++)
    {
        if(i%2==0 and i>0){ printf("\n"); }
        printf("[%3d] %-25s ", found[i].first, found[i].second.c_str());
    }
    printf("\n");
}

void PrettyPrint::menuShowAll()
{
    std::vector<std::pair<int, std::string> > found = tag->all();
    for(int i=0;i<found.size();i++)
    {
        if(i%2==0 and i>0){ printf("\n"); }
        printf("[%3d] %-25s", found[i].first, found[i].second.c_str());
    }
    printf("\n");
}


void PrettyPrint::clear()
{
#ifdef OS_WINDOWS
    system("cls");
#else
    system("clear");
#endif
}


void PrettyPrint::debugMap()
{
    int** m = map->getMap();
    int** n = map->getNext();
    int nodes = map->getNode();

    for(int i=1;i<=nodes;i++)
    {
        for (int j=1; j<=nodes; j++) {
            if(m[i][j]==99999999)
                printf("- ");
            else
                printf("%d ", m[i][j]);
        }
        printf("\n");
    }

}