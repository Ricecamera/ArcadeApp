#include "Star.h"
#include "Utils.h"
#include <random>

Star::Star(Vec2D centerPoint, float innerDistance, float externalDistance) : mInnerDist(innerDistance), mOuterDist(externalDistance)
{
	mPoints.push_back(centerPoint);

	float angle = TWO_PI / float(NUM_SIDE);

	// find internal points
	Vec2D p0 = Vec2D(centerPoint.GetX(), centerPoint.GetY() - mInnerDist);

	p0.Rotate(-(angle / 2), centerPoint);
	mPoints.push_back(p0);
	for (int i = 1; i < NUM_SIDE; ++i) {
		Vec2D p1 = p0.RotationResult(angle, centerPoint);
		mPoints.push_back(p1);
		p0 = p1;
	}

	// find external points
	p0.SetX(centerPoint.GetX());
	p0.SetY(centerPoint.GetY() - mOuterDist);
	mPoints.push_back(p0);
	for (int i = 1; i < NUM_SIDE; ++i) {
		Vec2D p1 = p0.RotationResult(angle, centerPoint);
		mPoints.push_back(p1);
		p0 = p1;
	}
}


void Star::MoveTo(const Vec2D& position) 
{
	Vec2D offset = position - mPoints[0];
	MoveBy(offset);
}

void Star::RotateBy(float angle) 
{
	Vec2D CenterPoint = mPoints[0];
	for (size_t i = 1; i < mPoints.size(); ++i)
	{
		mPoints[i].Rotate(angle, CenterPoint);
	}
}

Star Star::GenerateRandomStar()
{
	float MAX_STAR_SIZE = 50.f;
	float MIN_STAR_SIZE = 20.0f;
	std::random_device r;

	std::default_random_engine e1(r());
	std::uniform_int_distribution<int> uniform_dist_y(0, SCREEN_HEIGHT);
	std::uniform_int_distribution<int> uniform_dist_x(0, SCREEN_WIDTH);
	std::uniform_real_distribution<float> uniform_dist_size(MIN_STAR_SIZE, MAX_STAR_SIZE);

	float inner_dist = uniform_dist_size(e1) - 10;
	float outer_dist;
	do {
		outer_dist = uniform_dist_size(e1);
	} while (outer_dist < inner_dist);
	

	Vec2D centerPoint = Vec2D(uniform_dist_x(e1), uniform_dist_y(e1));
	return Star(centerPoint, inner_dist, outer_dist);
}