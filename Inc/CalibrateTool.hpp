/*
 * CalibrateTool.hpp
 *
 *  Created on: Dec 28, 2020
 *      Author: handiko
 */

#ifndef INC_CALIBRATETOOL_HPP_
#define INC_CALIBRATETOOL_HPP_

#include "main.h"
#include "dac.h"
#include "tim.h"

class CalibrateTool {
private:
	DAC_HandleTypeDef* hdac;
	TIM_HandleTypeDef* htim;

	void startDac(void);

public:
	CalibrateTool();

	void appointDac(DAC_HandleTypeDef* hdac);
	void appointTimer(TIM_HandleTypeDef* htim);

	void tick(void);

	virtual ~CalibrateTool();
};

#endif /* INC_CALIBRATETOOL_HPP_ */
