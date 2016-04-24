//
//  Tag.cpp
//  FindTheRoute
//
//  Created by Chawasit Tengtrairat on 4/23/2559 BE.
//  Copyright © 2559 cpe24. All rights reserved.
//

#include "Tag.hpp"

Tag::Tag()
{
    
}

int Tag::getID(std::string name)
{
    int ret = -1;
    for (auto it = name_list.begin(); it!=name_list.end(); it++) {
        if(it->second == name)
        {
            ret = it->first;
            break;
        }
    }
    return ret;
}

bool Tag::add(int id, std::string name)
{
    if(getID(name)==-1)
    {
        name_list[id] = name;
        return true;
    }else{
        return false;
    }
}


std::string Tag::getName(int id)
{
    std::string ret;
    auto it = name_list.find(id);
    if(it!=name_list.end())
    {
        ret = it->second;
    }
    return ret;
}
