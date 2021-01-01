#include "DxModel.h"
#include <DirectXMath.h>
#include <vector>

DX::Model::Model(DX::Renderer* renderer) : m_DxRenderer(renderer)
{
}

void DX::Model::Create()
{
	CreateVertexBuffer();
	CreateIndexBuffer();
	CreateColourBuffer();
}

void DX::Model::CreateVertexBuffer()
{
	auto d3dDevice = m_DxRenderer->GetDevice();

	// Set vertex data
	std::vector<Vertex> vertices =
	{
		{ -0.5f, +0.5f, 0.0f }, // Top left vertex
		{ +0.5f, +0.5f, 0.0f }, // Top right vertex
		{ -0.5f, -0.5f, 0.0f }, // Bottom left vertex
		{ +0.5f, -0.5f, 0.0f }, // Bottom right vertex
	};

	// Create index buffer
	D3D11_BUFFER_DESC vertex_buffer_desc = {};
	vertex_buffer_desc.Usage = D3D11_USAGE_DEFAULT;
	vertex_buffer_desc.ByteWidth = static_cast<UINT>(sizeof(Vertex) * vertices.size());
	vertex_buffer_desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;

	D3D11_SUBRESOURCE_DATA vertex_subdata = {};
	vertex_subdata.pSysMem = vertices.data();

	DX::Check(d3dDevice->CreateBuffer(&vertex_buffer_desc, &vertex_subdata, m_d3dVertexBuffer.ReleaseAndGetAddressOf()));
}

void DX::Model::CreateIndexBuffer()
{
	auto d3dDevice = m_DxRenderer->GetDevice();

	// Set Indices
	std::vector<UINT> indices =
	{
		0, 1, 2, // Triangle 1
		2, 1, 3, // Triangle 2
	};

	m_IndexCount = static_cast<UINT>(indices.size());

	// Create index buffer
	D3D11_BUFFER_DESC index_buffer_desc = {};
	index_buffer_desc.Usage = D3D11_USAGE_DEFAULT;
	index_buffer_desc.ByteWidth = static_cast<UINT>(sizeof(UINT) * indices.size());
	index_buffer_desc.BindFlags = D3D11_BIND_INDEX_BUFFER;

	D3D11_SUBRESOURCE_DATA index_subdata = {};
	index_subdata.pSysMem = indices.data();

	DX::Check(d3dDevice->CreateBuffer(&index_buffer_desc, &index_subdata, m_d3dIndexBuffer.ReleaseAndGetAddressOf()));
}

void DX::Model::CreateColourBuffer()
{
	auto d3dDevice = m_DxRenderer->GetDevice();

	// Set Indices
	m_Colours =
	{
		DirectX::Colors::Red,
		DirectX::Colors::Blue,
		DirectX::Colors::Green,
		DirectX::Colors::Yellow,
	};

	// Create index buffer
	D3D11_BUFFER_DESC colour_buffer_desc = {};
	colour_buffer_desc.Usage = D3D11_USAGE_DEFAULT;
	colour_buffer_desc.ByteWidth = static_cast<UINT>(sizeof(DirectX::XMVECTORF32) * m_Colours.size());
	colour_buffer_desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;

	D3D11_SUBRESOURCE_DATA colour_subdata = {};
	colour_subdata.pSysMem = m_Colours.data();

	DX::Check(d3dDevice->CreateBuffer(&colour_buffer_desc, &colour_subdata, m_d3dColourBuffer.ReleaseAndGetAddressOf()));
}

void DX::Model::Render()
{
	auto d3dDeviceContext = m_DxRenderer->GetDeviceContext();

	// We need the stride and offset for the vertex
	UINT vertex_stride = sizeof(Vertex);
	auto vertex_offset = 0u;

	// Bind the vertex buffer to the pipeline's Input Assembler stage
	d3dDeviceContext->IASetVertexBuffers(0, 1, m_d3dVertexBuffer.GetAddressOf(), &vertex_stride, &vertex_offset);

	// We need the stride and offset for the colour
	UINT colour_stride = sizeof(DirectX::XMVECTORF32);
	auto colour_offset = 0u;

	// Bind the colour buffer to the pipeline's Input Assembler stage
	d3dDeviceContext->IASetVertexBuffers(1, 1, m_d3dColourBuffer.GetAddressOf(), &colour_stride, &colour_offset);

	// Bind the index buffer to the pipeline's Input Assembler stage
	d3dDeviceContext->IASetIndexBuffer(m_d3dIndexBuffer.Get(), DXGI_FORMAT_R32_UINT, 0);

	// Bind the geometry topology to the pipeline's Input Assembler stage
	d3dDeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	// Render geometry
	d3dDeviceContext->DrawIndexed(m_IndexCount, 0, 0);
}
 