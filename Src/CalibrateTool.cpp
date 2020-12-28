/*
 * CalibrateTool.cpp
 *
 *  Created on: Dec 28, 2020
 *      Author: handiko
 */

#include <CalibrateTool.hpp>

CalibrateTool::CalibrateTool() {
	// TODO Auto-generated constructor stub

}

/*
 * Private method
 */
void CalibrateTool::startDac(void)
{
	HAL_DAC_Start(hdac, DAC_CHANNEL_1);
	//HAL_DAC_Start(hdac, DAC_CHANNEL_2);
}

/*
 * Public method
 */
void CalibrateTool::appointDac(DAC_HandleTypeDef* hdac)
{
	this->hdac = hdac;

	startDac();
}

void CalibrateTool::tick(void)
{
	if(dacTune == 1.0)
	{
		HAL_DAC_SetValue(hdac, DAC_CHANNEL_1, DAC_ALIGN_12B_R, dacVal++);
	}
	else
	{
		HAL_DAC_SetValue(hdac, DAC_CHANNEL_1, DAC_ALIGN_12B_R, (uint32_t)(dacTune * dacVal++));
	}

	if(dacVal == 4096)
	{
		dacVal = 0;
	}
}

float CalibrateTool::getCalibration(void)
{
	return dacTune;
}

CalibrateTool::~CalibrateTool() {
	// TODO Auto-generated destructor stub
}

