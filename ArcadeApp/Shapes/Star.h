
#ifndef SHAPES_STAR_H_
#define SHAPES_STAR_H_

#include "Vec2D.h"
#include <vector>
#include "Shape.h"

class Star : public Shape
{
public:
	Star() : Star(Vec2D::Zero, 0, 0) {}
	Star(Vec2D centerPoint, float innerDistance, float externalDistance);
	
	inline Vec2D GetCenterPoint() const override { return mPoints[0]; }
	inline float GetInnerDist() const { return mInnerDist; }
	inline float GetOuterDist() const { return mOuterDist; }

	void MoveTo(const Vec2D& position) override;
	void RotateBy(float angle);

	static Star GenerateRandomStar();
private:
	float mInnerDist;
	float mOuterDist;
	static unsigned int const NUM_SIDE = 5;

};

#endif