//
//  Bug.h
//  JointExample
//
//  Created by Okami Satoshi on 12/04/28.
//  Copyright (c) 2012 Okami Satoshi. All rights reserved.
//

#ifndef _Bug_h
#define _Bug_h

#include "ofxBox2d.h"
#include "ofMain.h"
#include "ofVec2f.h"
#include <vector.h>
#include <math.h>
#include "Gene.h"


class Bug {
	
protected:
	
	
	vector<ofxBox2dRect> nodes;
	vector<ofxBox2dJoint> joints;
	
	
	int dnaOffset;
	bool finished;
	
public:
	
	ofxBox2d* box2d;
	ofVec2f position;
	Gene gene;
	
	Bug() {
		dnaOffset = 0;
		finished = false;
	}
	
	Gene getGene() { return gene; }
	bool isFinished() { return finished; }
	
	void setup(ofVec2f position, int nodeNum);
	void update();
	void draw();
	float travelDistance();
};

#endif
