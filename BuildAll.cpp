#include <iostream>
#include <MTTools/WorkerThread.h>
#include <MTTools/Timer.h>
using namespace ULMTTools;

int main()
{
	WorkerThread_SPtr worker = std::make_shared<WorkerThread>();
	TaskScheduler_SPtr scheduler = std::make_shared<TaskScheduler>();

	ConditionVariable cond;
	size_t tasksPerSec = 1000;
	

	ThrottledWorkerThread throttler();

	ReusableThrottledWorkerThread reusableThrottler(worker,
											scheduler,
											std::chrono::seconds(1),
											tasksPerSec
											);
	Timer timer(scheduler);

	for (int i = 0; i < 100; i++)
	{
		timer.install([i]() {std::cout << "Executing task " << i+1 << std::endl; }, std::chrono::seconds(1));
	}

	std::getchar();

	//size_t totaltasks = tasksPerSec * 10;
	//std::vector<double> latencies;
	//latencies.reserve(totaltasks);

	//time_point start = utils::now();

	//for (size_t i = 1; i <= totaltasks; i++)
	//{
	//	time_point start = utils::now();
	//	throttler.push([i, &cond, start, totaltasks, &latencies]()
	//	{
	//		/*std::cout << "Executing task " << i << ", latency: "<<
	//				  std::chrono::duration_cast<std::chrono::microseconds>(utils::now() - start).count() <<"usec"<<
	//				  std::endl; */

	//		latencies.push_back((float)std::chrono::duration_cast<std::chrono::nanoseconds>(utils::now() - start).count() / (float)1000000000);

	//		if (totaltasks == i)
	//			cond.notify_one();
	//	});
	//}


	//cond.wait();

	//for (size_t i = 0; i < totaltasks; i++)
	//	std::cout << "Latency for task " << i + 1 << ": " << latencies[i] << " sec" << std::endl;

	//std::cout << "Total latency: " << (float)std::chrono::duration_cast<std::chrono::nanoseconds>(utils::now() - start).count() / (float)1000000000 << " sec";

	return 0;
}
