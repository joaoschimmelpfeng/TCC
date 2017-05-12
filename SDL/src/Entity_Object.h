#ifndef __entity_h_
#define __entity_h_

class Entity_Object
{
	public:
		float pos_x;
		float pos_y;
		float width;
		float height;
		float r;
		float g;
		float b;
		Entity_Object(float pos_x, float pos_y);
		void Render();
};

#endif