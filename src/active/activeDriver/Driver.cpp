#include "driver.h"

namespace activeDriver {
	void Driver::begin()
	{
		publisher.publish_vkExtensions();
		publisher.buildShaders();
	}
}