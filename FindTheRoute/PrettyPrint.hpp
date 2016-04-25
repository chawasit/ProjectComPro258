//
//  PrettyPrint.hpp
//  FindTheRoute
//
//  Created by Chawasit Tengtrairat on 4/23/2559 BE.
//  Copyright © 2559 cpe24. All rights reserved.
//

#ifndef PrettyPrint_hpp
#define PrettyPrint_hpp

#include <stdio.h>
#include <queue>
#include <string>
#include "Tag.hpp"
#include "Map.hpp"
#include "Node.hpp"
#include "Group.hpp"

class PrettyPrint {
private:
    Tag* tag;
    Node* node;
    Group* group;
    Map *map;
public:
    PrettyPrint(Tag*, Node*, Group*, Map*);
    void showTag();
    void showRoute(std::queue<int>*);
    void showDebug();
    void showMenu();
    void clear();
    
    
    void debugMap();
    
    void menuFindRoute(); // Find the route
    void menuSearch(); // Search by location
    void menuShowAll(); // show all location
};

#endif /* PrettyPrint_hpp */
