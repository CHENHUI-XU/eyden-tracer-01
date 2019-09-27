// Triangle Geaometrical Primitive class
// Written by Sergey Kosov in 2005 for Rendering Competition
#pragma once

#include "Prim.h"

/**
 * @brief Triangle Geaometrical Primitive class
 */
class CPrimTriangle : public CPrim
{
public:
	/**
	 * @brief Constructor
	 * @param a Position of the first vertex
	 * @param b Position of the second vertex
	 * @param c Position of the third vertex
	 */
	CPrimTriangle(Vec3f a, Vec3f b, Vec3f c)
		: CPrim()
		, m_a(a)
		, m_b(b)
		, m_c(c)
  	{}
	virtual ~CPrimTriangle(void) = default;
	
	virtual bool Intersect(Ray& ray) override
	{
		// --- PUT YOUR CODE HERE ---
		const Vec3f s1 = m_b - m_a;
		const Vec3f s2 = m_c - m_a;
		
		const Vec3f f = ray.dir.cross(s2);
		
		const float det = s1.dot(f);
		if (fabs(det) < Epsilon)
			return false;
		
		return true;
	}


	
private:
	Vec3f m_a;	///< Position of the first vertex
	Vec3f m_b;	///< Position of the second vertex
	Vec3f m_c;	///< Position of the third vertex
};
