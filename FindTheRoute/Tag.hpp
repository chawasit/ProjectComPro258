//
//  Tag.hpp
//  FindTheRoute
//
//  Created by Chawasit Tengtrairat on 4/23/2559 BE.
//  Copyright © 2559 cpe24. All rights reserved.
//

#ifndef Tag_hpp
#define Tag_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include "verbalexpressions.hpp"

class Tag {
private:
    std::map<int, std::string> name_list;
public:
    Tag();
    std::string getName(int);
    bool add(int, std::string);
    int getID(std::string);
    std::vector<std::pair<int, std::string> > search(std::string);
    std::vector<std::pair<int, std::string> > all();
    
    std::map<int, std::string>::iterator begin(){ return name_list.begin(); };
    std::map<int, std::string>::iterator end(){ return name_list.end(); };
};

#endif /* Tag_hpp */
