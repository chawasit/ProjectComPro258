//
//  Group.cpp
//  FindTheRoute
//
//  Created by Chawasit Tengtrairat on 4/24/2559 BE.
//  Copyright © 2559 cpe24. All rights reserved.
//

#include "Group.hpp"

void Group::add(int id, std::string name)
{
    group[id] = name;
}

std::string Group::get(int id)
{
    std::string ret;
    auto it = group.find(id);
    if(it!=group.end())
    {
        ret = it->second;
    }
    return ret;
}
