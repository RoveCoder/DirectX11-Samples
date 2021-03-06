#pragma once

#include "DxRenderer.h"
#include <vector>
#include <DirectXColors.h>

namespace DX
{
	struct Vertex
	{
		float x = 0;
		float y = 0;
		float z = 0;
	};

	class Model
	{
	public:
		Model(DX::Renderer* renderer);
		virtual ~Model() = default;

		// Create device
		void Create();

		// Render the model
		void Render();

		// World 
		DirectX::XMMATRIX World = DirectX::XMMatrixIdentity();

	private:
		DX::Renderer* m_DxRenderer = nullptr;

		// Number of indices to draw
		UINT m_IndexCount = 0;

		// Vertex buffer
		ComPtr<ID3D11Buffer> m_d3dVertexBuffer = nullptr;
		void CreateVertexBuffer();

		// Index buffer
		ComPtr<ID3D11Buffer> m_d3dIndexBuffer = nullptr;
		void CreateIndexBuffer();

		// Vertex colours list
		std::vector<DirectX::XMVECTORF32> m_Colours;

		// Colour buffer
		ComPtr<ID3D11Buffer> m_d3dColourBuffer = nullptr;
		void CreateColourBuffer();
	};
}