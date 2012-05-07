//
//  SmallWorld.cpp
//  JointExample
//
//  Created by Okami Satoshi on 12/04/28.
//  Copyright (c) 2012 Okami Satoshi. All rights reserved.
//

#include "SmallWorld.h"
#include <iostream.h>


void SmallWorld::setup() {
	
	bugs.resize(bugNum);
	genes.resize(bugNum);
	
	initialize();
	initBox2d();
}

void SmallWorld::initBox2d() {
	
	box2d.init();
	box2d.setGravity(gravity.x, gravity.y);
	box2d.setFPS(ofGetFrameRate());
	box2d.registerGrabbing();
	
	for (int i = 0; i < bugNum; i++) {
		
		ofRectangle ground;
		ground = ofRectangle(0, ofGetHeight() / bugNum * i, ofGetWidth(), ofGetHeight() / bugNum);
		box2d.createBounds(ground);
		
		Bug bug;
		bug.box2d = &box2d;
		bug.gene = genes[i];
		
		ofVec2f position(ofGetWidth() / 2, (ofGetHeight() / bugNum) * (i + 1) - 10);
		
		bug.setup(position, nodeNum);
		bugs[i] = bug;
	}
}

void SmallWorld::update() {
	
	if (!finished) {
		
		if (bugs[0].isFinished()) {
			
			evaluate();
			
			bug1 = bugs[0];
			bug2 = bugs[1];
			
			// chech if termination is satisfied
			if (termination()) {
				
				cout << "end bugs life simulation up." << endl;
				finished = true;
				
			} else {
				// do crossover or mutation
				breed();
				
				// reproduction
				initBox2d();
			}
			
		} else {
			
			box2d.update();
			
			// add force every 0.5s
			if (steps > 0 && steps % 15 == 0) {
				
				for (int i = 0; i < bugs.size(); i++) {
					bugs[i].update();
				}
			}
			
			steps++;
		}
	}
}

void SmallWorld::draw() {
	
	for (int i = 0; i < bugs.size(); i++) {
		bugs[i].draw();
	}
	
	ofSetColor(ofColor(0));
	ofDrawBitmapString("generation: " + ofToString(generations), 10, 20);
	
	if (generations > 1) {
		ofDrawBitmapString("1st: " + ofToString(bug1.travelDistance()), 10, 40);
		ofDrawBitmapString("2nd: " + ofToString(bug2.travelDistance()), 10, 60);
	}
}

void SmallWorld::evaluate() {
	
	// sort by travel distance
	for (int i = 0; i < bugs.size(); i++) {
		for (int j = 0; j < bugs.size() - 1; j++) {
			if (bugs[j].travelDistance() < bugs[j + 1].travelDistance()) {
				Bug tmp = bugs[j];
				bugs[j] = bugs[j + 1];
				bugs[j + 1] = tmp;
			}
		}
	}
}

void SmallWorld::initialize() {
	
	for (int i = 0; i < bugNum; i++) {
		Gene gene;
		gene.initialize(minSpeed, maxSpeed, nodeNum * turn);
		genes[i] = gene;
	}
	
	generations++;
}

void SmallWorld::breed() {
	
	if (bugs.size() > 2) {
		
		vector<Gene> tmp;
		tmp.resize(bugs.size());
		
		tmp[0] = bugs[0].getGene();
		tmp[1] = bugs[1].getGene();
		
		for (int i = 2; i < bugs.size() - 1; i++) {
			Gene gene;
			gene.crossover(tmp[0].dna, tmp[1].dna, nodeNum * turn);
			
			for (int j = 0; j < int(nodeNum / 4); j++) {
				gene.mutation(minSpeed, maxSpeed, probability);
			}
			
			tmp[i] = gene;
		}
		
		for (int i = bugs.size() - 2; i < bugs.size() - 1; i++) {
			Gene gene;
			gene.crossover(tmp[0].dna, tmp[1].dna, nodeNum * turn);
			
			for (int j = 0; j < int(nodeNum / 4); j++) {
				gene.mutation(minSpeed, maxSpeed, probability * 10);
			}
			
			tmp[i] = gene;
		}
		
		for (int i = bugs.size() - 1; i < bugs.size(); i++) {
			Gene gene;
			gene.initialize(minSpeed, maxSpeed, nodeNum * turn);
			tmp[i] = gene;
		}
		
		genes.swap(tmp);
	}
	
	generations++;
}

bool SmallWorld::termination() {
	
	return bool(generations > maxGeneration);
}
