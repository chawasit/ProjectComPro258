//
//  Node.hpp
//  FindTheRoute
//
//  Created by Chawasit Tengtrairat on 4/24/2559 BE.
//  Copyright © 2559 cpe24. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>
#include <string>
#include <map>

class Node {
private:
    std::map<int, std::pair<int, int> > node;
public:
    Node();
    bool add(int, int, int);
    int getTagID(int);
    int getGroupID(int);
    int getNodeByTag(int);
    int getNodeByGroup(int);
    
    std::map<int, std::pair<int, int>>::iterator begin(){ return node.begin(); };
    std::map<int, std::pair<int, int>>::iterator end(){ return node.end(); };
};
#endif /* Node_hpp */
