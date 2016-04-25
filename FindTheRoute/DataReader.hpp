//
//  DataReader.hpp
//  FindTheRoute
//
//  Created by Chawasit Tengtrairat on 4/24/2559 BE.
//  Copyright © 2559 cpe24. All rights reserved.
//

#ifndef DataReader_hpp
#define DataReader_hpp

#include <stdio.h>
#include <fstream>
#include <string>
#include <sstream>
#include "Tag.hpp"
#include "Node.hpp"
#include "Map.hpp"
#include "Group.hpp"

class DataReader {
private:
    std::ifstream io;
public:
    DataReader();
    DataReader(std::string);
    void open(std::string);
    void close();
    
    void parseData(Tag *tag, Node *node, Group *group, Map *map);
    void parseTag(std::istringstream&, Tag *);
    void parseNode(std::istringstream&, Node *);
    void parseGroup(std::istringstream&, Group *);
    void parsePath(std::istringstream&, Map *);
    bool getln(std::istream&, std::string&);
};
#endif /* DataReader_hpp */
