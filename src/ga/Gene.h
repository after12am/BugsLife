//
//  Gene.h
//  emptyExample
//
//  Created by Okami Satoshi on 12/05/07.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef _Gene_h
#define _Gene_h

#include "ofMain.h"
#include "ofVec2f.h"
#include <vector.h>
#include <cmath>

struct Gene {
	
	vector<ofVec2f> dna;
	
	void initialize(const float min, const float max, const int size) {
		
		dna.resize(size);
		
		for (int i = 0; i < size; i++) {
			
			dna[i] = ofVec2f(ofRandom(min, max), ofRandom(min, max));
			//dna[i] = ofVec2f(0, ofRandom(min, max));
		}
	};
	
	void crossover(const vector<ofVec2f>& dna1, const vector<ofVec2f>& dna2, const int size) {
		
		int k = floor(ofRandom(1, size - 1));
		
		dna.resize(size);
		
		for (int i = 0; i < size; i++) {
			
			dna[i] = (i < k) ? dna1[i] : dna2[i];
		}
	};
	
	void mutation(const float min, const float max, const float mutationProbability) {
		
		if (ofRandom(100) < mutationProbability) {
			
			cout << "occured mutation." << endl;
			
			int k = floor(ofRandom(0, dna.size() - 1));
			
			dna[k] = ofVec2f(0, ofRandom(min, max));
		}
	};
};

#endif
