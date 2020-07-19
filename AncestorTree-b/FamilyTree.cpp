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

bool Tree::findMe(Tree *root, string nameSearch){
    if(root->name == nameSearch){// if i am the root youngest of generations 
        node = root;// the static tree is me 
        return true;// i am in tree now
    }
    if(root->Mother == NULL && root->Father == NULL){// if i am not root and there is no mother or father to root im not in this tree
        return false;
    }
    if(root->Father != NULL || root->Mother != NULL){// if root has a father tree search it for me 
        flagF = findMe(root->Father, nameSearch);// if im in roots father side return true
        flagM = findMe(root->Mother, nameSearch);
    }
    // if(root->Mother != NULL){// if root has a mother 
    //     flagM = findMe(root->Mother, nameSearch);
    // }
    return (flagM || flagF);
}
Tree &Tree::addFather(string son, string father){// adds father to son
    if(findMe(this,son)){
        cout << node;
        node->Father = new Tree(father, node);
    }
    else{
        __throw_out_of_range("son is not in tree");
    }
    return *this;
}

Tree &Tree::addMother(string son, string mother){
    if(findMe(this,son)){
        node->Mother = new Tree(mother, node);
    }
    else{
        __throw_range_error("son is not in tree");
    }
    return *this;
}

string Tree::find(string relation){};
string Tree::relation(string name){};
void Tree::remove(string name){};
void Tree::display(){};
int Tree::getLevel(Tree *node, string name){};
void Tree::getNodesAtDist(Tree *root, int dist){};
vector<string> Tree::getNodesAtDist(int dist){};
void Tree::print2DUtil(Tree *root, int space){};
