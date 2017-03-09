#include<GL/glew.h>
#include"element2d.h"

class Rect : public Element2D
{
    public:
    Rect();
    ~Rect();
	void render();
    void move()
    {
        this->transform.Scale(1.5);
    }
    private:
	

};