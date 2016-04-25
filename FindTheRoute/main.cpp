//
//  main.cpp
//  FindTheRoute
//
//  Created by Chawasit Tengtrairat on 4/22/2559 BE.
//  Copyright © 2559 cpe24. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <iomanip>
#include "Map.hpp"
#include "DataReader.hpp"
#include "PrettyPrint.hpp"
#include "Tag.hpp"
#include "Node.hpp"
#include "Group.hpp"

int main(int argc, const char * argv[]) {
    DataReader reader;
    Map* map = new Map();
    Tag* tag = new Tag();
    Node* node = new Node();
    Group* group = new Group();
    PrettyPrint printer(tag, node, group, map);
    
    reader.parseData(tag, node, group, map);
    
//    printer.showTag(tag);
    printer.showDebug();
    printer.showMenu();
    std::cout << "END\n";
    return 0;
}
