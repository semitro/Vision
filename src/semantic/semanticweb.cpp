#include "semantic/semanticweb.hpp"

SemanticWeb::SemanticWeb()
{

}

void SemanticWeb::addNode(Node *node){
	this->nodes.insert(node);
}

Node* SemanticWeb::getNode(Node node){
	auto i = nodes.find(&node);
	if( i == nodes.end())
		return NULL;
	else
		return *i;
}
