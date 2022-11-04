#pragma once

class Scene
{

public:

	Scene() {};
	~Scene() {};

	virtual void s_init() = 0;
	virtual void s_clean() = 0;
	virtual void s_integrate(float t) = 0;
	virtual void s_keyPress(unsigned char key) = 0;
};

