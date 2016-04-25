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
        printf("--------------------------------------------------------------\n\n");
        printf(" Please select the command.\n (1)FindRoute (2)Search Location (3)Show All Location (0)Exit\nSelect: ");
        scanf("%d", &command);
        printf("--------------------------------------------------------------\n\n");
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
                printf("[!] Invalid command.\n");
                break;
        }
        sleep(3);
    }while(command != 0);
    printf("[!] By bye :D");
}

void PrettyPrint::menuFindRoute(){
    int Start=0,Destination=0;
    printf("[?] Please Input where to start: ");
    scanf("%d",&Start);
    printf("[?] Please Input destination: ");
    scanf("%d",&Destination);
    if(Start == Destination)
    {
        printf("[!] Start and Destination must not be the same\n");
        return ;
    }
    
    std::vector<int> from=node->getNodeByTag(Start),
                     to=node->getNodeByTag(Destination);
    int** distance = map->getMap();
    int current_from, current_to, route_distance;
    int current_group;
    
    for(int i=0;i<from.size();i++)
        printf("FROM %d %s\n", from[i], tag->getName(node->getTagID(from[i])).c_str());
    for(int j=0;j<to.size();j++)
        printf("TO %d %s\n", to[j], tag->getName(node->getTagID(to[j])).c_str());
    
    int min_distance=99999999;
    std::queue<int> min_route;
    std::queue<int> route;
    if(from.size()>0 and to.size()>0)
    {
        for(int i=0;i<from.size();i++)
        {
            for(int j=0;j<to.size();j++)
            {
                route_distance = distance[from[i]][to[j]];
                route = map->getRoute(from[i], to[j]);
                if(route_distance<min_distance)
                {
                    min_distance = route_distance;
                    min_route = route;
                }
            }
        }
        printf("\n[+] Bus Route from %s \n  to %s\n\n",
               tag->getName(Start).c_str(),
               tag->getName(Destination).c_str());
        
        if(!min_route.empty())
        {
            current_from = min_route.front();
            min_route.pop();
            current_group = node->getGroupID(current_from);
            printf("[+] %s [%s] ",
                   tag->getName(node->getTagID(current_from)).c_str(),
                   group->get(current_group).c_str());
        }
        while(!min_route.empty())
        {
            current_to = min_route.front(); min_route.pop();
            //                    printf("%d->", current_from);
            if(current_group!=node->getGroupID(current_to))
            {
                current_group = node->getGroupID(current_to);
                printf("%s [%s] ",
                       tag->getName(node->getTagID(current_from)).c_str(),
                       group->get(current_group).c_str() );
            }
            current_from = current_to;
        }
        printf("%s\n  Distance: %d m, Time: %d minutes\n\n",
               tag->getName(node->getTagID(current_from)).c_str(),
               min_distance,
               (min_distance/11/60) );
    }else{
        printf("[-] Locaction not found\n");
    }
}

void PrettyPrint::menuSearch(){
    char ToFind[200];
    printf("[?] Please Input tag name:");
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

void PrettyPrint::sleep(int second)
{
    std::this_thread::sleep_for(std::chrono::seconds(second));
}