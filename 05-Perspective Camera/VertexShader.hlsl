cbuffer WorldBuffer : register(b0)
{
	matrix cWorld;
	matrix cView;
	matrix cProjection;
}

struct VertexOutput
{
	float4 position : SV_POSITION;
	float4 colour : COLOUR;
};

// Entry point for the vertex shader - will be executed for each vertex
VertexOutput main(float3 position : POSITION, float4 colour : COLOUR)
{
	VertexOutput output;

	// Transform to homogeneous clip space.
	output.position = mul(float4(position, 1.0f), cWorld);
	output.position = mul(output.position, cView);
	output.position = mul(output.position, cProjection);

	// Set the vertex colour
	output.colour = colour;

	return output;
}