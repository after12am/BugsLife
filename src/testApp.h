#pragma once

#include "ofMain.h"
#include "SmallWorld.h"
#include <vector.h>


class testApp : public ofBaseApp {
	
public:
	
	static const int SIMULATION_NUM = 1;
	
	void setup();
	void update();
	void draw();
	
	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void resized(int w, int h);
	
	SmallWorld world;
};