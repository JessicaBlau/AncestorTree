#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <ctype.h>
#include <vector>
#include <queue>
#include <string>
#include "FamilyTree.hpp"

using namespace family;
static Tree* node = NULL;
static int count = 0;
bool flagM = false , flagF = false;

bool Tree::findMe(Tree *root, string nameSearch){return false;}
Tree &Tree::addFather(string son, string father){return *this;}
Tree &Tree::addMother(string son, string mother){return *this;}
string Tree::find(string relation){return "";}
string Tree::relation(string name){return "";}
void Tree::remove(string name){}
void Tree::display(){}
int Tree::getLevel(Tree *node, string name){return 0;}
void Tree::getNodesAtDist(Tree *root, int dist){}
vector<string> Tree::getNodesAtDist(int dist){
    vector<string> T;
    return T;
}
void Tree::print2DUtil(Tree *root, int space){}
