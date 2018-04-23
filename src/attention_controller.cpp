#include "attention_controller.hpp"

AttentionController::AttentionController(HavingAttention &controlled, Vision &vision)
	: attentionControlled(controlled),
	  vision(vision)
{

}
void AttentionController::tick(){
	list<vt::Node> objects;
	vt::Node facePrototype("Face");
	size_t faces = this->vision.howManyFaces();
	for(int i = 0; i <  faces; i++)
		objects.push_back(facePrototype);

	this->attentionControlled.payAttention(objects);
}
