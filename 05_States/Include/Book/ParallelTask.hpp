#ifndef BOOK_PARALLELTASK_HPP
#define BOOK_PARALLELTASK_HPP

#include <SFML/System/Clock.hpp>

#include <mutex>
#include <thread>


class ParallelTask
{
	public:
							ParallelTask();
							~ParallelTask();

		void				execute();
		bool				isFinished();
		float				getCompletion();

	private:
		void				runTask();

	private:
		std::thread			mThread;
		bool				mFinished;
		sf::Clock			mElapsedTime;
		std::mutex			mMutex;
};

#endif // BOOK_PARALLELTASK_HPP
