#include <Book/PostEffect.hpp>

#include <SFML/Graphics/Shader.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/VertexArray.hpp>


PostEffect::~PostEffect()
{
}

void PostEffect::applyShader(const sf::Shader& shader, sf::RenderTarget& output)
{
	sf::Vector2f outputSize = static_cast<sf::Vector2f>(output.getSize());

	sf::VertexArray vertices(sf::PrimitiveType::TriangleStrip, 4);
	vertices[0] = sf::Vertex{{0.f, 0.f},             sf::Color::White, {0.f, 1.f}};
	vertices[1] = sf::Vertex{{outputSize.x, 0.f},    sf::Color::White, {1.f, 1.f}};
	vertices[2] = sf::Vertex{{0.f, outputSize.y},    sf::Color::White, {0.f, 0.f}};
	vertices[3] = sf::Vertex{{outputSize.x, outputSize.y}, sf::Color::White, {1.f, 0.f}};

	sf::RenderStates states;
	states.shader 	 = &shader;
	states.blendMode = sf::BlendNone;

	output.draw(vertices, states);
}

bool PostEffect::isSupported()
{
	return sf::Shader::isAvailable();
}
