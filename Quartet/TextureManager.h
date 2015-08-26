#pragma once
#include <vector>
#include <SFML\Graphics.hpp>

class TextureManager final
{
public:
	TextureManager();
	~TextureManager();

	void AddTexture(sf::Texture& texture);
	sf::Texture& GetTexture(int index);
private:
	std::vector<sf::Texture> textureList;
};

