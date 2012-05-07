//
//  Bug.cpp
//  JointExample
//
//  Created by Okami Satoshi on 12/04/28.
//  Copyright (c) 2012 Okami Satoshi. All rights reserved.
//

#include "Bug.h"
#include <iostream.h>


void Bug::setup(ofVec2f position, int nodeNum) {
	
	this->position = position;
	
	// add node
	for (int i = 0; i < nodeNum; i++) {
		ofxBox2dRect node;
		node.setPhysics(1003.0, 0.13, 1000.9);
		node.setup(box2d->getWorld(), position.x + (i * 10), position.y, 5, 5);
		nodes.push_back(node);
	}
	
	// connect each node with a joint
	for (int i = 1; i < nodes.size(); i++) {
		ofxBox2dJoint joint;
        joint.setup(box2d->getWorld(), nodes[i-1].body, nodes[i].body);
        joint.setLength(15);
        joints.push_back(joint);
	}
}


void Bug::update() {
	
	if (!finished) {
			
		for (int i = 0; i < nodes.size(); i++) {
			
			ofVec2f v = gene.dna[dnaOffset];
			nodes[i].setVelocity(v.x, v.y);
			dnaOffset++;
		}
		
		finished = bool(dnaOffset > gene.dna.size());
	}
}

void Bug::draw() {
	
	ofSetHexColor(0xf2ab01);
	
	for(int i = 0; i < nodes.size(); i++) {
		ofFill();
		ofSetHexColor(0xBF2545);
		nodes[i].draw();
	}
	
	for(int i = 0; i < joints.size(); i++) {
		ofSetHexColor(0x444342);
		joints[i].draw();
	}
}

// use for evaluation of ga : genetic algorism
float Bug::travelDistance() {
	
	return (nodes[0].getPosition() - position).length();
}
