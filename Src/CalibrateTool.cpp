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
#ifdef DAC_CHANNEL_2
	HAL_DAC_Start(hdac, DAC_CHANNEL_2);
#endif
}

/*
 * Public method
 */
void CalibrateTool::appointDac(DAC_HandleTypeDef* hdac)
{
	this->hdac = hdac;

	startDac();
}

void CalibrateTool::appointTimer(TIM_HandleTypeDef* htim)
{
	this->htim = htim;
}

void CalibrateTool::tick(void)
{

}

CalibrateTool::~CalibrateTool() {
	// TODO Auto-generated destructor stub
}

