#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;
namespace family{
    class Tree{
    private:
        string name;
        Tree *Mother;
        Tree *Father;
        Tree *Son;
    public:
        Tree(string name){
            this->name = name;
            this->Father = this->Mother = this->Son = NULL;
        }
        Tree(string name, Tree *Son){
            this->name = name;
            this->Son = Son;
        }
        Tree& addFather(string Son, string Father);// function that add father to someone in tree
        Tree& addMother(string son, string Mother);// function that adds mother to someone in tree
        string relation(string name);// finds this person and his relation to you
        string find(string relation);// finds the name of the person who is in this rilation to you
        void display();
        void remove(string name);
    private:
        int getLevel(Tree *node, string name);// returns the level of the tree where name is 
        int getLevelUtil(Tree *node, string name, int level);
        void getNodesAtDist(Tree *root,int dist);// gets the person thats at this distance from the root 
        vector<string> getNodesAtDist(int dist);// returns all nodes to get to this distance 
        void print2DUtil(Tree *root, int space);
        bool findMe(Tree *root, string nameSearch);// returns true if this name is in the tree
    };
}