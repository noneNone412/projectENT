#pragma once
#include "../../activeConstants/constants.h"


namespace activeEngine {
	class Camera {
	private:
		float fov;
		float znear, zfar;
		glm::vec3 target = glm::vec3(0.0f); // Default target for lookat mode
		bool matricesNeedUpdate = true; // Track if matrices need updating
		
		void updateViewMatrix();


	public:
		void updateMatricesIfNeeded();

		enum CameraType { lookat, firstperson };
		CameraType type = CameraType::lookat;

		glm::vec3 rotation = glm::vec3();
		glm::vec3 position = glm::vec3();
		glm::vec4 viewPos = glm::vec4();

		float rotationSpeed = 1.0f;
		float movementSpeed = 1.0f;

		bool updated = true;
		bool flipY = false;
		double lastX;
		double lastY;
		struct
		{
			glm::mat4 perspective;
			glm::mat4 view;
		} matrices;

		struct
		{
			bool left = false;
			bool right = false;
			bool up = false;
			bool down = false;
		} keys;
		bool moving();

		float getNearClip();

		float getFarClip();

		void setPerspective(float fov, float aspect, float znear, float zfar);

		void updateAspectRatio(float aspect);

		void setPosition(glm::vec3 position);

		void setRotation(glm::vec3 rotation);

		void rotate(glm::vec3 delta);

		void setTranslation(glm::vec3 translation);

		void translate(glm::vec3 delta);

		void setRotationSpeed(float rotationSpeed);

		void setMovementSpeed(float movementSpeed);

		// Set target for look-at camera
		void setTarget(glm::vec3 target);

		// Dynamic FOV adjustment for zooming
		void zoom(float deltaFov);

		void update(float deltaTime);

		bool updatePad(glm::vec2 axisLeft, glm::vec2 axisRight, float deltaTime);

		void setCamera(CameraType typeOfCamera);


	};
}