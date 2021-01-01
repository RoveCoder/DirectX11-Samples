#include "DxCamera.h"

DX::Camera::Camera(int width, int height)
{
	Resize(width, height);

	// Calculate camera's view
	auto eye = DirectX::XMVectorSet(0.0f, 0.0f, -4.0f, 0.0f);
	auto at = DirectX::XMVectorSet(0.0f, 0.0f, 0.0f, 0.0f);
	auto up = DirectX::XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);
	m_View = DirectX::XMMatrixLookAtLH(eye, at, up);
}

void DX::Camera::Resize(int width, int height)
{
	auto fov = 50.0f;

	// Convert degrees to radians
	auto field_of_view_radians = DirectX::XMConvertToRadians(fov);

	// Calculate window aspect ratio
	auto window_aspect_ratio = static_cast<float>(width) / height;

	// Calculate camera's perspective
	m_Projection = DirectX::XMMatrixPerspectiveFovLH(field_of_view_radians, window_aspect_ratio, 0.01f, 100.0f);
}
