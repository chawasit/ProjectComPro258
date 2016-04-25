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

std::vector<std::pair<int, std::string> > Tag::search(std::string text)
{
    verex::verex expr = verex::verex()
                        .search_one_line()
                        .start_of_line()
                        .anything()
                        .then(text)
                        .anything()
                        .with_any_case();
    std::vector<std::pair<int, std::string> > ret;
    for(auto it=name_list.begin();it!=name_list.end();it++)
    {
        if(expr.test(it->second))
        {
            ret.push_back(std::make_pair(it->first, it->second));
        }
    }
    return ret;
}
