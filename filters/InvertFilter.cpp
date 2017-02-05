/*
    This file is part of EqualizerAPO, a system-wide equalizer.
    Copyright (C) 2016  Etienne Dechamps

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#include "stdafx.h"
#define _USE_MATH_DEFINES
#include <cmath>

#include "InvertFilter.h"

using namespace std;

vector<wstring> InvertFilter::initialize(float sampleRate, unsigned maxFrameCount, vector<wstring> channelNames)
{
	this->channelCount = channelNames.size();

	return channelNames;
}

#pragma AVRT_CODE_BEGIN
void InvertFilter::process(float** output, float** input, unsigned frameCount)
{
	for (size_t i = 0; i < channelCount; i++)
	{
		float* sampleChannel = input[i];

		for (unsigned j = 0; j < frameCount; j++)
			sampleChannel[j] *= -1;
	}
}
#pragma AVRT_CODE_END
