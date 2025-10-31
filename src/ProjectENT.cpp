// ProjectENT.cpp : Defines the entry point for the application.
//

#include "ProjectENT.h"

void use_driver() {
	activeDriver::Driver dryver;
	dryver.begin();

}

void use_engine() {
	activeEngine::VulkanVariables* variables = new  activeEngine::VulkanVariables;
	activeEngine::Engine engyne(variables);
	engyne.start();
	engyne.run();
	engyne.stop();
}
int get_count() {
	return 16;
}


int main()
{

	/*
	tf::Executor executor;
	tf::Taskflow taskflow;

	// Define tasks
	auto A = taskflow.emplace([]() { std::cout << "Task A\n"; });
	auto B = taskflow.emplace([]() { std::cout << "Task B\n"; });
	auto C = taskflow.emplace([]() { std::cout << "Task C\n"; });
	auto D = taskflow.emplace([]() { std::cout << "Task D\n"; });

	// Set dependencies
	A.precede(B, C);  // A runs before B and C
	B.precede(D);     // B runs before D
	D.precede(C);     // D runs before C

	// Execute the taskflow
	executor.run(taskflow).wait();
	*/
	/*
	int count = get_count();
	tf::Executor executor(count);  // Specify 16 threads
	tf::Taskflow taskflow;

	// Create tasks that demonstrate parallel execution
	for (int i = 0; i < count; ++i) {
		taskflow.emplace([i]() {
			std::cout << "Task " << i << " is running on thread "
				<< std::this_thread::get_id() << std::endl;
			});
	}

	// Execute the taskflow
	executor.run(taskflow).wait();
	 */
	use_driver();
	use_engine();

	return 0;
}
