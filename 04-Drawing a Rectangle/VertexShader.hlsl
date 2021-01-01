struct VertexOutput
{
	float4 position : SV_POSITION;
	float4 colour : COLOUR;
};

// Entry point for the vertex shader - will be executed for each vertex
VertexOutput main(float3 position : POSITION, float4 colour : COLOUR)
{
	VertexOutput output;

	// Pass our vertex through without any modifications
	output.position = float4(position, 1.0f);

	// Set the vertex colour
	output.colour = colour;

	return output;
}