/*
 * Utils.h
 *
 *  Created on: Jan. 8, 2019
 *      Author: serge
 */

#ifndef UTILS_UTILS_H_
#define UTILS_UTILS_H_

static const float EPSILON = 0.0001f;

const float PI = 3.14159f;
const float TWO_PI = 2.0f * PI;

const int SCREEN_WIDTH = 1280/*224*/;
const int SCREEN_HEIGHT = 720/*288*/;

bool IsEqual(float x, float y);

bool IsGreaterThanOrEqual(float x, float y);

bool IsLessThanOrEqual(float x, float y);


#endif /* UTILS_UTILS_H_ */
