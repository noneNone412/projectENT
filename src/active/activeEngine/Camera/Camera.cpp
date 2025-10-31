#include "Camera.h"

// priavate
namespace activeEngine {
    
    void Camera::setCamera(Camera::CameraType typeOfCamera) {
        lastX = 400.0f;
        lastY = 300.0f;

        // Initialize camera settings like position, perspective, etc.
        setPosition(glm::vec3(0.0f, 0.0f, 5.0f));  // Set initial position
        setPerspective(45.0f, 16.0f / 9.0f, 0.1f, 100.0f);  // Set perspective
        setRotation(glm::vec3(0.0f, 0.0f, 0.0f));  // Set initial rotation
        setMovementSpeed(5.0f);  // Set movement speed
        setRotationSpeed(1.0f);  // Set rotation speed

        // Set the camera type to firstperson or lookat depending on your needs
        type = typeOfCamera;
    }

    void Camera::updateMatricesIfNeeded() {
        if (matricesNeedUpdate) {
            updateViewMatrix();
            matricesNeedUpdate = false;
        }
    }

    void Camera::updateViewMatrix()
    {
        std::cout << "updateViewMatrix\n";
        if (type == CameraType::lookat)
        {
            // Look-at mode: camera looks at a target position
            matrices.view = glm::lookAt(position, target, glm::vec3(0.0f, 1.0f, 0.0f));
        }
        else
        {
            // First-person mode: rotate and translate camera
            glm::mat4 rotM = glm::mat4(1.0f);
            glm::mat4 transM;

            rotM = glm::rotate(rotM, glm::radians(rotation.x * (flipY ? -1.0f : 1.0f)), glm::vec3(1.0f, 0.0f, 0.0f));
            rotM = glm::rotate(rotM, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
            rotM = glm::rotate(rotM, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));

            glm::vec3 translation = position;
            if (flipY) {
                translation.y *= -1.0f;
            }
            transM = glm::translate(glm::mat4(1.0f), translation);

            if (type == CameraType::firstperson)
            {
                matrices.view = rotM * transM;
            }
            else
            {
                matrices.view = transM * rotM;
            }
        }

        viewPos = glm::vec4(position, 0.0f) * glm::vec4(-1.0f, 1.0f, -1.0f, 1.0f);
        updated = true;
    }
}
// public
namespace activeEngine {
    bool Camera::moving()
    {
        return keys.left || keys.right || keys.up || keys.down;
    }

    float Camera::getNearClip() {
        return znear;
    }

    float Camera::getFarClip() {
        return zfar;
    }

    void Camera::setPerspective(float fov, float aspect, float znear, float zfar)
    {
        this->fov = fov;
        this->znear = znear;
        this->zfar = zfar;
        matrices.perspective = glm::perspective(glm::radians(fov), aspect, znear, zfar);
        if (flipY) {
            matrices.perspective[1][1] *= -1.0f;
        }
        matricesNeedUpdate = true;
    }

    void Camera::updateAspectRatio(float aspect)
    {
        matrices.perspective = glm::perspective(glm::radians(fov), aspect, znear, zfar);
        if (flipY) {
            matrices.perspective[1][1] *= -1.0f;
        }
        matricesNeedUpdate = true;
    }

    void Camera::setPosition(glm::vec3 position)
    {
        this->position = position;
        matricesNeedUpdate = true;
    }

    void Camera:: setRotation(glm::vec3 rotation)
    {
        this->rotation = rotation;
        matricesNeedUpdate = true;
    }

    void Camera::rotate(glm::vec3 delta)
    {
        this->rotation += delta;
        matricesNeedUpdate = true;
    }

    void  Camera:: setTranslation(glm::vec3 translation)
    {
        this->position = translation;
        matricesNeedUpdate = true;
    }

    void Camera::translate(glm::vec3 delta)
    {
        this->position += delta;
        matricesNeedUpdate = true;
    }

    void Camera::setRotationSpeed(float rotationSpeed)
    {
        this->rotationSpeed = rotationSpeed;
    }

    void Camera:: setMovementSpeed(float movementSpeed)
    {
        this->movementSpeed = movementSpeed;
    }

    // Set target for look-at camera
    void Camera::setTarget(glm::vec3 target)
    {
        this->target = target;
        matricesNeedUpdate = true;
    }

    // Dynamic FOV adjustment for zooming
    void Camera:: zoom(float deltaFov)
    {
        fov += deltaFov;
        matrices.perspective = glm::perspective(glm::radians(fov), 16.0f / 9.0f, znear, zfar); // assuming aspect ratio
        matricesNeedUpdate = true;
    }

    void Camera::update(float deltaTime)
    {
        if (type == CameraType::firstperson && moving())
        {
            glm::vec3 camFront;
            camFront.x = -cos(glm::radians(rotation.x)) * sin(glm::radians(rotation.y));
            camFront.y = sin(glm::radians(rotation.x));
            camFront.z = cos(glm::radians(rotation.x)) * cos(glm::radians(rotation.y));
            camFront = glm::normalize(camFront);

            float moveSpeed = deltaTime * movementSpeed;

            if (keys.up)
                position += camFront * moveSpeed;
            if (keys.down)
                position -= camFront * moveSpeed;
            if (keys.left)
                position -= glm::normalize(glm::cross(camFront, glm::vec3(0.0f, 1.0f, 0.0f))) * moveSpeed;
            if (keys.right)
                position += glm::normalize(glm::cross(camFront, glm::vec3(0.0f, 1.0f, 0.0f))) * moveSpeed;
        }

        updateMatricesIfNeeded();
    }

    bool Camera::updatePad(glm::vec2 axisLeft, glm::vec2 axisRight, float deltaTime)
    {
        bool retVal = false;

        if (type == CameraType::firstperson)
        {
            const float deadZone = 0.0015f;
            const float range = 1.0f - deadZone;

            glm::vec3 camFront;
            camFront.x = -cos(glm::radians(rotation.x)) * sin(glm::radians(rotation.y));
            camFront.y = sin(glm::radians(rotation.x));
            camFront.z = cos(glm::radians(rotation.x)) * cos(glm::radians(rotation.y));
            camFront = glm::normalize(camFront);

            float moveSpeed = deltaTime * movementSpeed * 2.0f;
            float rotSpeed = deltaTime * rotationSpeed * 50.0f;

            // Move
            if (fabsf(axisLeft.y) > deadZone)
            {
                float pos = (fabsf(axisLeft.y) - deadZone) / range;
                position -= camFront * pos * ((axisLeft.y < 0.0f) ? -1.0f : 1.0f) * moveSpeed;
                retVal = true;
            }
            if (fabsf(axisLeft.x) > deadZone)
            {
                float pos = (fabsf(axisLeft.x) - deadZone) / range;
                position += glm::normalize(glm::cross(camFront, glm::vec3(0.0f, 1.0f, 0.0f))) * pos * ((axisLeft.x < 0.0f) ? -1.0f : 1.0f) * moveSpeed;
                retVal = true;
            }

            // Rotate
            if (fabsf(axisRight.x) > deadZone)
            {
                float pos = (fabsf(axisRight.x) - deadZone) / range;
                rotation.y += pos * ((axisRight.x < 0.0f) ? -1.0f : 1.0f) * rotSpeed;
                retVal = true;
            }
            if (fabsf(axisRight.y) > deadZone)
            {
                float pos = (fabsf(axisRight.y) - deadZone) / range;
                rotation.x -= pos * ((axisRight.y < 0.0f) ? -1.0f : 1.0f) * rotSpeed;
                retVal = true;
            }
        }
        updateMatricesIfNeeded();
        return retVal;
    }
}
