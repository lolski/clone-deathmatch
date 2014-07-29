#include "PrintSceneNodeImmediateChildren.h"

void printSceneNodeImmediateChildren(ISceneNode *which) {
    core::list<ISceneNode *> l = which->getChildren();
    for (core::list<ISceneNode *>::Iterator it = l.begin(); it != l.end(); ++it) {
        ISceneNode *n = *it;
        std::cout<<n->getName()<<std::endl;
    }    
}