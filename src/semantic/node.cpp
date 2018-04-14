#include "semantic/node.hpp"

Node::Node(NodeType type, std::string name)
	:type(type), name(name)
{
}


void Node::addRelation(Node *subject, Relation relation){
	std::pair<Node*,Relation> p(subject, relation);
	subjects.insert(p);

}

Relation::Relation(RelationType type)
	:type(type){

}
