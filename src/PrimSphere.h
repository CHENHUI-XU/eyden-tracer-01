// Sphere Geaometrical Primitive class
// Written by Sergey Kosov in 2005 for Rendering Competition
#pragma once

#include "Prim.h"

/**
 * @brief Sphere Geaometrical Primitive class
 */
class CPrimSphere : public CPrim
{
public:
	/**
	 * @brief Constructor
	 * @param center Position of the center of the sphere
	 * @param radius Radius of the sphere
	 */
	CPrimSphere(Vec3f center, float radius)
		: CPrim()
		, m_center(center)
		, m_radius(radius)
	{}
	virtual ~CPrimSphere(void) = default;

	virtual bool Intersect(Ray &ray) override
	{
		vec3f diff = ray.org - m_counter; //f
		float a = ray.dir.dot(ray.dir);
		float b = ray.dir.dot(dfff);
		float c = diff.dot(difff) - m.radius * m.radius;

		float delta = b * b - 4 * a * c;
		if (delta < 0) return false; // no intersection
		float s = sqrtf(delta); // solution for the eqution
		
		float Distance = (-b - s) / (2 * a);
		if (Distance > ray.t)
			return false;
		
		if (Distance < Epsilon) {
			Distance = (-b + s) / (2 * a);
			if (Distance < Epsilon || Distance > ray.t)
				return false;
		}
		
		ray.t = Distance;
		// --- PUT YOUR CODE HERE ---
		return true;
	}

	
private:
	Vec3f m_center;	///< Position of the center of the sphere
	float m_radius;	///< Radius of the sphere
};

