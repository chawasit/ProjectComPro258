//
//  Group.hpp
//  FindTheRoute
//
//  Created by Chawasit Tengtrairat on 4/24/2559 BE.
//  Copyright © 2559 cpe24. All rights reserved.
//

#ifndef Group_hpp
#define Group_hpp

#include <stdio.h>
#include <string>
#include <map>

class Group {
private:
    std::map<int, std::string> group;
public:
    void add(int , std::string);
    std::string get(int);
    
    std::map<int, std::string>::iterator begin(){ return group.begin(); };
    std::map<int, std::string>::iterator end(){ return group.end(); };
};
#endif /* Group_hpp */
