#include "EulerCamera.h"

EulerCamera::EulerCamera(void)
{
    m_angle_X = 0;
    m_angle_Y = 0;
    this->reset(0, 0, 0,
		0, 0, -1, 
		0, 1, 0);

    set_perspective_projection(45.0f,4.0f/3.0f,0.1f,100000.0f);
}

EulerCamera::~EulerCamera(void)
{
}

glm::vec3 EulerCamera::get_look_direction()
{
    return -m_direction;
}

void EulerCamera::reset(float eyeX, float eyeY, float eyeZ, float centerX, float centerY, float centerZ, float upX, float upY, float upZ)
{
	glm::vec3 eyePt(eyeX, eyeY, eyeZ);
	glm::vec3 centerPt(centerX, centerY, centerZ);
	glm::vec3 upVec(upX, upY, upZ);
    reset(eyePt, centerPt, upVec);
}

void EulerCamera::reset(const glm::vec3 &eye, const glm::vec3 &center, glm::vec3 &up)
{
    m_position = eye;
	
	//still needs normalization
    m_direction = center - m_position;
	//i = j x k
    m_right = glm::cross(m_direction, up);
	//j = k x i
    m_up = up;
	//normalize all
    m_up = glm::normalize(m_up);
    m_right = glm::normalize(m_right);
    m_direction = glm::normalize(m_direction);

    m_view_matrix = glm::lookAt(m_position, center, m_up);
	//UpdateViewMatrix();
}

glm::mat4 EulerCamera::get_view_matrix()
{
    return m_view_matrix;
}

void EulerCamera::update_view_matrix()
{
	const float PI = 3.14f;
    m_direction = glm::vec3(
        -cos(m_angle_Y)*sin(m_angle_X),
         sin(m_angle_Y),
        -cos(m_angle_Y)*cos(m_angle_X));
	

    m_direction = glm::normalize(m_direction);


    m_right = glm::cross(m_direction,glm::vec3(0,1,0));

    m_up = glm::cross(m_right,m_direction);

    glm::vec3 center = m_position + m_direction;
    m_view_matrix = glm::lookAt(m_position, center, m_up);
}

glm::mat4 EulerCamera::get_projection_matrix()
{
    return m_projection_matrix;
}

void EulerCamera::set_perspective_projection(float FOV, float aspectRatio, float near, float far)
{
    m_projection_matrix = glm::perspective(FOV, aspectRatio, near, far);
}

void EulerCamera::slide(float stepR, float stepU, float stepD)
{
    m_position += stepR *m_right;
    m_position += stepU * m_up;
	//next transition needs to be tested!!.
    m_position += stepD * m_direction;
}

void EulerCamera::yaw(float angle_degrees)
{
    m_angle_X +=angle_degrees;
}

void EulerCamera::pitch(float angle_degrees)
{
	double PI = 3.14;
    if (m_angle_Y + angle_degrees < PI/2.0 && m_angle_Y + angle_degrees > - PI/2.0)
        m_angle_Y +=angle_degrees;
}

void EulerCamera::roll(float angle_degrees)
{
    m_angle_Z += angle_degrees;
}

void EulerCamera::walk(float distance)
{
    m_position += distance * m_direction;
}

void EulerCamera::strafe(float distance)
{
    m_position += distance *m_right;
}

void EulerCamera::fly(float distance)
{
    m_position += distance * m_up;
}
glm::vec3  EulerCamera::GetEyePosition()
{
	return m_position;
}