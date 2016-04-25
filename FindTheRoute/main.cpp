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
#include <chrono>
#include <thread>

int main(int argc, const char * argv[]) {
    printf("[+] Initialing..\n");
    DataReader reader;
    Map* map = new Map();
    Tag* tag = new Tag();
    Node* node = new Node();
    Group* group = new Group();
    PrettyPrint printer(tag, node, group, map);
    
    printf("[+] Loading Data..\n");
    reader.parseData(tag, node, group, map);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    
    printf("[+] Calculating Route..\n");
    map->setNode(node->size());
    map->createMap();
    map->init();
    map->floyd_warshall();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    printf("[+] Complete!\n");
//    std::this_thread::sleep_for(std::chrono::seconds(3));
    
//    printer.showTag(tag);
//    printer.showDebug();
    printer.debugMap();
    printer.clear();
    printer.showMenu();
    
    map->destroyMap();
    delete map, node, tag, group, printer;
    std::cout << "END\n";
    return 0;
}
