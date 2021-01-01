#pragma once

#include <DirectXMath.h>

namespace DX
{
	// Perspective Camera
	class Camera
	{
	public:
		Camera(int width, int height);
		virtual ~Camera() = default;

		void Resize(int width, int height);

		// Get projection matrix
		constexpr DirectX::XMMATRIX GetProjection() { return m_Projection; }

		// Get view matrix
		constexpr DirectX::XMMATRIX GetView() { return m_View; }

	private:
		// Projection matrix
		DirectX::XMMATRIX m_Projection;

		// View matrix
		DirectX::XMMATRIX m_View;
	};
}