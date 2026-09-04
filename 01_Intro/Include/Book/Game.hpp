#ifndef BOOK_GAME_HPP
#define BOOK_GAME_HPP

#include <SFML/Graphics.hpp>


class Game 
{
	public:
								Game();
		void					run();
		

	private:
		void					processEvents();
		void					update(sf::Time elapsedTime);
		void					render();

		void					updateStatistics(sf::Time elapsedTime);	
		void					handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
		

	private:
		static const float		PlayerSpeed;
		static const sf::Time	TimePerFrame;

		// 1. 先声明基础资源
		sf::Texture mTexture;
		sf::Font mFont;

		// 2. 再声明依赖资源的对象
		sf::Sprite mPlayer;         // 依赖 mTexture
		sf::Text mStatisticsText;   // 依赖 mFont

		// 其他成员
		sf::RenderWindow mWindow;
		sf::Time mStatisticsUpdateTime;

		std::size_t				mStatisticsNumFrames;
		bool					mIsMovingUp;
		bool					mIsMovingDown;
		bool					mIsMovingRight;
		bool					mIsMovingLeft;
};

#endif // BOOK_GAME_HPP
