/**Copyright (C) Austin Hicks, 2014-2016
This file is part of Libaudioverse, a library for realtime audio applications.
This code is dual-licensed.  It is released under the terms of the Mozilla Public License version 2.0 or the Gnu General Public License version 3 or later.
You may use this code under the terms of either license at your option.
A copy of both licenses may be found in license.gpl and license.mpl at the root of this repository.
If these files are unavailable to you, see either http://www.gnu.org/licenses/ (GPL V3 or later) or https://www.mozilla.org/en-US/MPL/2.0/ (MPL 2.0).*/
#pragma once
#include "../private/node.hpp"
#include "../private/multichannel_filter_bank.hpp"
#include "../implementations/biquad.hpp"
#include <memory>

namespace libaudioverse_implementation {

/**Note.  We can't use floats. There's some instability with the accumulator model that was here before that shows up as audible artifacts.*/
class ThreeBandEqNode: public Node {
	public:
	ThreeBandEqNode(std::shared_ptr<Simulation> simulation, int channels);
	void recompute();
	virtual void process() override;
	virtual void reset() override;
	float lowband_gain;
	MultichannelFilterBank<BiquadFilter> midband_peaks, highband_shelves;
};

std::shared_ptr<Node> createThreeBandEqNode(std::shared_ptr<Simulation> simulation, int channels);
}