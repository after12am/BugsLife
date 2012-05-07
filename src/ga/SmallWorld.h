//
//  SmallWorld.h
//  JointExample
//
//  Created by Okami Satoshi on 12/04/28.
//  Copyright (c) 2012 Okami Satoshi. All rights reserved.
//

#ifndef _SmallWorld_h
#define _SmallWorld_h

#include "ofxBox2d.h"
#include "ofMain.h"
#include "ofVec2f.h"
#include <math.h>
#include <vector.h>
#include "Bug.h"
#include "Gene.h"


class SmallWorld {
	
protected:
	
	ofxBox2d box2d;
	
	vector<Bug> bugs;
	vector<Gene> genes;
	
	Bug bug1, bug2;
	
	int steps;
	bool finished;
	
public:
	
	int bugNum;
	int nodeNum;
	int turn;
	
	int generations;
	int maxGeneration;
	
	float probability;
	float minSpeed;
	float maxSpeed;
	ofVec2f gravity;
	
	
	SmallWorld() {
		
		bugNum = 10;
		nodeNum = 4;
		turn = 10;
		
		steps = 0;
		generations = 0;
		maxGeneration = 1000;
		
		// mutation probability
		probability = .05f;
		
		gravity = ofVec2f(0, 10);
		minSpeed = -8;
		maxSpeed = 8;
		
		finished = false;
	}
	
	void setup();
	void update();
	void draw();
	void initBox2d();
	
	// ga
	void evaluate();
	void initialize();
	void breed();
	bool termination();
};

#endif
