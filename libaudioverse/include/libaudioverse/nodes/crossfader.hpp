/**Copyright (C) Austin Hicks, 2014-2016
This file is part of Libaudioverse, a library for realtime audio applications.
This code is dual-licensed.  It is released under the terms of the Mozilla Public License version 2.0 or the Gnu General Public License version 3 or later.
You may use this code under the terms of either license at your option.
A copy of both licenses may be found in license.gpl and license.mpl at the root of this repository.
If these files are unavailable to you, see either http://www.gnu.org/licenses/ (GPL V3 or later) or https://www.mozilla.org/en-US/MPL/2.0/ (MPL 2.0).*/
#pragma once
#include "../private/node.hpp"
#include "../private/callback.hpp"
#include <memory>
namespace libaudioverse_implementation {

class Simulation;
class Node;

class CrossfaderNode: public Node {
	public:
	CrossfaderNode(std::shared_ptr<Simulation> sim, int channels, int inputs);
	void crossfade(float duration, int input);
	//Immediately finish the current crossfade.
	void finishCrossfade();
	void process();
	std::shared_ptr<Callback<void()>> finished_callback;
	private:
	int channels = 0;
	int current = 0, target = 0;
	float current_weight = 1.0, target_weight = 0.0, delta = 0.0;
	bool crossfading = false;
};

std::shared_ptr<Node> createCrossfaderNode(std::shared_ptr<Simulation> simulation, int channels, int inputs);

}