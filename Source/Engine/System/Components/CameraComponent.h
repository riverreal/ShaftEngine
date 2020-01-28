#pragma once

#include <Shaft/Core.h>
#include "IComponent.h"

namespace Shaft
{
	struct CameraComponent : IComponent
	{
    public:
        CameraComponent()
            :viewMatrix (0.0f),
            projMatrix (0.0f),
            lookAt(0.0f),
            dirty(true),
            near(0.1f),
            far(1000.0f),
            fov(60.0f),
            aspectRatio(0.0f)
        {}

        void SetLookAt(Vec3f l)
        {
            lookAt = l;
            dirty = true;
        }

        void SetFOV(float f)
        {
            fov = f;
            dirty = true;
        }

        void SetNearFar(float n, float f)
        {
            near = n;
            far = f;
            dirty = true;
        }

        void SetAspectRatio(float aspect)
        {
            aspectRatio = aspect;
        }

        float GetAspectRatio() const { return aspectRatio; }
        Vec3f GetLookAt() const { return lookAt; }
        float GetNear() const { return near; }
        float GetFar() const { return far; }
        float GetFOV() const { return fov; }

    public:
        bool dirty;
        Matrix viewMatrix;
        Matrix projMatrix;

    private:
        Vec3f lookAt;
        float fov;
        float near;
        float far;
        float aspectRatio;
	};
}