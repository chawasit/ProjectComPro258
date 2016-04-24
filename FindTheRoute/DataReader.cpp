//
//  DataReader.cpp
//  FindTheRoute
//
//  Created by Chawasit Tengtrairat on 4/24/2559 BE.
//  Copyright © 2559 cpe24. All rights reserved.
//

#include "DataReader.hpp"

DataReader::DataReader(std::string path)
{
    open(path);
}


DataReader::DataReader()
{
    open("data.txt");
}


void DataReader::open(std::string path)
{
    if(io.is_open())
    {
        close();
    }
    io.open(path);
}

void DataReader::close()
{
    io.close();
}

void DataReader::parseData(Tag *tag, Node *node, Group *group, Map *map)
{
    io.seekg(std::ios::beg);
    std::string line;
    while(getline(io, line))
    {
        if(line == "[NODE]")
        {
            getline(io, line);
            while(line!="[END]")
            {
                std::istringstream stream(line);
                parseNode(stream, node);
                getline(io, line);
            }
        }
        else if(line == "[TAG]")
        {
            getline(io, line);
            while(line!="[END]")
            {
                std::istringstream stream(line);
                parseTag(stream, tag);
                getline(io, line);
            }
        }
        else if(line == "[GROUP]")
        {
            getline(io, line);
            while(line!="[END]")
            {
                std::istringstream stream(line);
                parseGroup(stream, group);
                getline(io, line);
            }
        }
        else if(line == "[PATH]")
        {
            getline(io, line);
            while(line!="[END]")
            {
                std::istringstream stream(line);
                parsePath(stream, map);
                getline(io, line);
            }
        }
        
    }
}

void DataReader::getln(std::istream &in, std::string &str)
{
    std::string temp;
    getline(in, temp);
    if(temp.c_str()[0]!='#')
    {
        str = temp;
    }
}

void DataReader::parsePath(std::istringstream &in, Map *map)
{
    int f,t,w;
    in >> f >> t >> w;
    map->addPath(f, t, w);
}

void DataReader::parseGroup(std::istringstream &in, Group *group)
{
    int id;
    std::string name;
    in >> id;
    getline(in, name);
    group->add(id, name);
}

void DataReader::parseTag(std::istringstream &in, Tag *tag)
{
    int id;
    std::string name;
    in >> id;
    getline(in, name);
    tag->add(id, name);
}

void DataReader::parseNode(std::istringstream &in, Node *node)
{
    int id,t,g;
    in >> id >> t >> g;
    node->add(id, t, g);
}