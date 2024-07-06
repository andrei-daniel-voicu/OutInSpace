#include "Collider.h"



Collider::Collider ()
{
	
}
void Collider::Update (float _top, float _left)
{
	rect.left = _left;
	rect.top = _top;
}