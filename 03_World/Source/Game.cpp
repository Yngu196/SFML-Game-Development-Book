#include <Book/Game.hpp>
#include <Book/StringHelpers.hpp>

#include <SFML/Window/Event.hpp>
#include <iostream>


const sf::Time Game::TimePerFrame = sf::seconds(1.f/60.f);

Game::Game()
: mWindow(sf::VideoMode({640, 480}), "World", sf::Style::Close)
, mWorld(mWindow)
, mFont()
, mStatisticsText(mFont, "", 30)
, mStatisticsUpdateTime()
, mStatisticsNumFrames(0)
{
	if (!mFont.openFromFile("Media/Sansation.ttf")){
		// 字体加载失败的处理逻辑
		std::cerr << "Failed to load font: Media/Sansation.ttf" << std::endl;
		// 可选：直接关闭窗口退出程序
		// mWindow.close(); 
	}
	mStatisticsText.setFont(mFont);
	mStatisticsText.setPosition(sf::Vector2f(5.f, 5.f));
	mStatisticsText.setCharacterSize(10);
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (mWindow.isOpen())
	{
		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;

			processEvents();
			update(TimePerFrame);

		}

		updateStatistics(elapsedTime);
		render();
	}
}

void Game::processEvents()
{
	while (const auto event = mWindow.pollEvent())
	{
		// 判断窗口关闭（无额外数据，用 is 更简洁）
		if (event->is<sf::Event::Closed>()) {
			mWindow.close();
		}
		// 判断按键按下（有数据，用 getIf 提取）
		else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
			handlePlayerInput(keyPressed->code, true);
		}
		// 判断按键释放
		else if (const auto* keyReleased = event->getIf<sf::Event::KeyReleased>()) {
			handlePlayerInput(keyReleased->code, false);
		}
	}
}

void Game::update(sf::Time elapsedTime)
{
	mWorld.update(elapsedTime);
}

void Game::render()
{
	mWindow.clear();	
	mWorld.draw();

	mWindow.setView(mWindow.getDefaultView());
	mWindow.draw(mStatisticsText);
	mWindow.display();
}

void Game::updateStatistics(sf::Time elapsedTime)
{
	mStatisticsUpdateTime += elapsedTime;
	mStatisticsNumFrames += 1;

	if (mStatisticsUpdateTime >= sf::seconds(1.0f))
	{
		mStatisticsText.setString(
			"Frames / Second = " + toString(mStatisticsNumFrames) + "\n" +
			"Time / Update = " + toString(mStatisticsUpdateTime.asMicroseconds() / mStatisticsNumFrames) + "us");
							 
		mStatisticsUpdateTime -= sf::seconds(1.0f);
		mStatisticsNumFrames = 0;
	}
}

void Game::handlePlayerInput(sf::Keyboard::Key, bool)
{
}
