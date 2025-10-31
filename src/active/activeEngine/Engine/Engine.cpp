#include"engine.h"


// private function
namespace activeEngine {
	void Engine::update_time() {
		// Get the current time
		double currentFrameTime = glfwGetTime();
		// Calculate deltaTime
		this->deltaTime = static_cast<float>(currentFrameTime - lastFrameTime);
		// Update last frame time
		lastFrameTime = currentFrameTime;
	}
	void Engine::draw()
	{

	}
	void Engine::updateMapChunks()
	{
	}
	void Engine::updateVulkanObjects()
	{
	}
	void Engine::updateGameFiles()
	{
	}
	void Engine::set_loadingScreen()
	{
	}
	void Engine::drawFrame()
	{
		/*
		while (gameIsRunning) {

			// 1. Input Processing
			ProcessPlayerInput();

			// 2. Game Thread: World Update (Actors, Physics, AI, etc.)
			// Update all actors in the world including the player's position
			for (Actor actor : World.Actors) {
				actor.Tick();  // Calls the Tick function to update the actor's state
			}

			// 3. Game Thread: Physics Simulation (if enabled)
			PhysicsEngine.StepSimulation();

			// 4. Game Thread: Player Position Update
			Player.UpdatePositionBasedOnInput();

			// 5. Game Thread: Gameplay Logic
			GameMode.HandleGameLogic();
			AIController.UpdateBehavior();

			// 6. Render Thread: Prepare for Rendering
			RenderThread.PrepareFrame();

			// 7. Audio Thread: Update and Process Sounds
			for (SoundComponent sound : AudioSystem.Sounds) {
				sound.Update();  // Update audio parameters based on actor position
			}

			// 8. Render Thread: Submit the Frame to the GPU
			RenderThread.SubmitFrame();

			// 9. Audio Thread: Mix Audio and Play Sounds
			AudioSystem.ProcessAudio();

			// 10. Synchronization: Wait for the next frame
			SynchronizeFrame();
		}

		*/
		renderManager.getCamera()->update(deltaTime);
	}
	void Engine::reset()
	{
	}
}
// public function
namespace activeEngine {
	Engine::Engine(VulkanVariables* variables) :setupManager(variables), renderManager(variables) {}


	void Engine::start() {
		setupManager.setup();
		renderManager.setup();
		set_loadingScreen();
		lastFrameTime = glfwGetTime();
	}

	void Engine::run() {
		while (renderManager.mainLoop()) {
			renderManager.begin();
			update_time();
			drawFrame();

			// handle resize
			setupManager.handle_window_resize();
		}
		renderManager.wait();
	}
	void Engine::stop() {
		setupManager.destroy();
	}
}