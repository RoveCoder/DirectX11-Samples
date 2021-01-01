// Vertex output - input of each pixel
struct VertexOutput
{
	float4 position : SV_POSITION;
	float4 colour : COLOUR;
};

// Entry point for the vertex shader - will be executed for each pixel
float4 main(VertexOutput vertex_output) : SV_TARGET
{
	return vertex_output.colour;
}