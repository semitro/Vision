#ifndef SEMANTICWEB_H
#define SEMANTICWEB_H

#include <unordered_set>
#include "node.hpp"

using std::unordered_set;
using std::string;

/*
 * Семантическая сеть:
 * из неё мы можем быстро получить доступ к желаемому объекту мира,
 * а далее узнать, в каких отношениях он состоит с другими объектами
 *
 */

// TO-DO - нужна ли Node Object?
namespace vt {


class myNodeHash {
public:
   size_t operator() (const Node* val) const {
	  return std::hash<std::string>()(val->getName());
   }
};

class myNodeEqual {
public:
   bool operator()(const Node *val1, const Node *val2) const{
	  return val1->getName() == val2->getName();
   }
};


class SemanticWeb
{
public:
	SemanticWeb();
	Node* getNode(Node  node); // Получаем указатель из любого значения!
	Node* getNode(string name);
	void  addNode(Node* node);
private:
	unordered_set<Node*, myNodeHash, myNodeEqual> nodes;
};

}
#endif // SEMANTICWEB_H
