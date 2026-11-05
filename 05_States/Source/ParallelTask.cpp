#include <Book/ParallelTask.hpp>


ParallelTask::ParallelTask()
: mThread()
, mFinished(false)
{
}

ParallelTask::~ParallelTask()
{
	if (mThread.joinable())
		mThread.join();
}

void ParallelTask::execute()
{
	if (mThread.joinable())
		mThread.join();

	mFinished = false;
	mElapsedTime.restart();
	mThread = std::thread(&ParallelTask::runTask, this);
}

bool ParallelTask::isFinished()
{
	std::lock_guard<std::mutex> lock(mMutex);
	return mFinished;
}

float ParallelTask::getCompletion()
{
	std::lock_guard<std::mutex> lock(mMutex);

	// 100% at 10 seconds of elapsed time
	return mElapsedTime.getElapsedTime().asSeconds() / 10.f;
}

void ParallelTask::runTask()
{
	// Dummy task - stall 10 seconds
	bool ended = false;
	while (!ended)
	{
		std::lock_guard<std::mutex> lock(mMutex); // Protect the clock 
		if (mElapsedTime.getElapsedTime().asSeconds() >= 10.f)
			ended = true;
	}

	{ // mFinished may be accessed from multiple threads, protect it
		std::lock_guard<std::mutex> lock(mMutex);
		mFinished = true;
	}	
}
