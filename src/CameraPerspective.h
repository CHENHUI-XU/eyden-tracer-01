// Perspective Camera class
// Written by Sergey Kosov in 2005 for Rendering Competition
#pragma once

#include "ICamera.h"

/**
 * @brief Perspective Camera class
 */
class CCameraPerspective : public ICamera
{
public:
	/**
	 * @brief Constructor
	 * @param pos Camera origin (center of projection)
	 * @param dir Camera viewing direction
	 * @param up Up-vector
	 * @param angle (Vertical) full opening angle of the viewing frustum (in degrees)
	 * @param resolution The image resolution
	 */
	CCameraPerspective(Vec3f pos, Vec3f dir, Vec3f up, float angle, Size resolution)
		: ICamera(resolution)
		, m_pos(pos)
		, m_dir(dir)
		, m_up(up)
	{
		m_zAxis = dir - pos;
		m_xAxis = m_zAxis.cross(m_up);
		m_yAxis = m_xAxis.cross(m_zAxis);

		m_xAxis = normalize(m_xAxis);
		m_yAxis = normalize(m_yAxis);
		m_zAxis = normalize(m_zAxis);

		m_aspect = resolution.width / resolution.height;

		float a = angle * pif / 180.0f;
		m_focus = 1.0f / tanf(a / 2.0f);

		// --- PUT YOUR CODE HERE ---
	}
	virtual ~CCameraPerspective(void) = default;

	virtual bool InitRay(float x, float y, Ray& ray) override
	{

		float dx = 0.5f;
		float dy = 0.5f;
		

		float sx = 2 * (x + dx) / getResolution().width - 1;
		float sy = 2 * (y + dy) / getResolution().height - 1;
		
		ray.org = m_pos;
		ray.dir = normalize(m_aspect * sx * m_xAxis + sy * m_yAxis + m_focus * m_zAxis);
		ray.t = std::numeric_limits<float>::infinity();
		
		ray.dir = normalize(ray.dir);
	// --- PUT YOUR CODE HERE ---
		return true;
	}


private:
	// input values
	Vec3f m_pos;
	Vec3f m_dir;
	Vec3f m_up;

	// preprocessed values
	float m_focus;
	Vec3f m_xAxis;
	Vec3f m_yAxis;
	Vec3f m_zAxis;
	float m_aspect;
};

