#ifndef EulerCamera_h__
#define EulerCamera_h__

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtx/rotate_vector.hpp>
#include <gtc/quaternion.hpp>
#include <gtx/quaternion.hpp>

//Note: this camera assumes left hand rule.
class EulerCamera
{
   // glm::vec3 m_position;
    glm::vec3 m_up;
    glm::vec3 m_right;
    glm::mat4 m_view_matrix;
    glm::mat4 m_projection_matrix;

    double m_angle_X, m_angle_Y, m_angle_Z;

public:
    glm::vec3 m_position;
    glm::vec3 m_direction;
	EulerCamera(void);
	~EulerCamera(void);

    void update_view_matrix();
    glm::mat4 get_view_matrix();
    void set_perspective_projection(float FOV, float aspectRatio, float near, float far);
    glm::mat4 get_projection_matrix();
	glm::vec3 get_eye_position();
    glm::vec3 get_look_direction();

    void reset(float eyeX, float eyeY, float eyeZ, float centerX, float centerY, float centerZ, float upX, float upY, float upZ);
    void reset(const glm::vec3 &eye, const glm::vec3 &center, glm::vec3  &up);


//#pragma region Rotations
	/// <summary>
	/// Rotates the axes (N, R) about the U-axis with the specified angle. This is equivalent to
	/// a left-turn.
	/// </summary>//y--->z--->x
    void yaw(float angleDegrees);

	/// <summary>
	/// Rotates the axes (U, N) about the R-axis with the specified angle. This is equivalent
	/// to a look-up (up turn).
	/// </summary>//x--->y--->z
    void pitch(float angleDegrees);

	/// <summary>
	/// Rotates the axes (R, U) about the N-axis with the specified angle.
	/// </summary>//z--->x--->y
    void roll(float angleDegrees);
//#pragma endregion

//#pragma region Translations

	/// <summary>
	/// Moves the eye point a distance dist forward == -dist * N
	/// Walk
	/// </summary>
    void walk(float dist);

	/// <summary>
	/// Moves the eye point a distance dist to the right == +dist * R
	/// Strafe
	/// </summary>
    void strafe(float dist);

	/// <summary>
	/// Moves the eye point a distance dist upward == +dist * U
	/// Fly
	/// </summary>
    void fly(float dist);

//#pragma endregion

	/// <summary>
	/// Moves the eye position a distance stepR along the vector R,
	/// a distance stepU along the vector U, and a distance stepD
	/// along the vector N.
	/// </summary>
    void slide(float stepR, float stepU, float stepD);
};
#endif // EulerCamera_h__

