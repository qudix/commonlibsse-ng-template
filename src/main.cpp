#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/msvc_sink.h>

void InitLogging()
{
	auto path = logs::log_directory();
	if (!path)
		return;

	const auto plugin = SKSE::PluginDeclaration::GetSingleton();
	*path /= fmt::format("{}.log", plugin->GetName());

	std::vector<spdlog::sink_ptr> sinks{ 
		std::make_shared<spdlog::sinks::basic_file_sink_mt>(path->string(), true), 
		std::make_shared<spdlog::sinks::msvc_sink_mt>() 
	};

	auto logger = std::make_shared<spdlog::logger>("global", sinks.begin(), sinks.end());
	logger->set_level(spdlog::level::info);
	logger->flush_on(spdlog::level::info);

	spdlog::set_default_logger(std::move(logger));
	spdlog::set_pattern("[%^%L%$] %v");
}

void InitMessaging()
{
	logs::trace("Initializing messaging listener...");
	const auto intfc = SKSE::GetMessagingInterface();
	if (!intfc->RegisterListener([](SKSE::MessagingInterface::Message* a_msg) {
		switch(a_msg->type) {
			// [Skyrim Lifecycle Events]
			case SKSE::MessagingInterface::kPostLoad:     // Called after all plugins have finished running SKSEPlugin_Load.
				// It is now safe to do multithreaded operations, or operations against other plugins.
				break;
			case SKSE::MessagingInterface::kPostPostLoad: // Called after all kPostLoad message handlers have run.
				break;
			case SKSE::MessagingInterface::kInputLoaded:  // Called when all game data has been found.
				break;
			case SKSE::MessagingInterface::kDataLoaded:   // All ESM/ESL/ESP plugins have loaded, main menu is now active.
				// It is now safe to access form data.
				RE::ConsoleLog::GetSingleton()->Print("Hello World!");
				break;
			// [Skyrim Game Events]
			case SKSE::MessagingInterface::kNewGame:      // Player starts a new game from main menu.
				break;
			case SKSE::MessagingInterface::kPreLoadGame:  // Player selected a game to load, but it hasn't loaded yet.
				// a_msg->data will be the name of the loaded save.
				break;
			case SKSE::MessagingInterface::kPostLoadGame: // Player's selected save game has finished loading.
				// a_msg->data will be a boolean indicating whether the load was successful.
				break;
			case SKSE::MessagingInterface::kSaveGame:     // Player has saved a game.
				// a_msg->data will be the save name.
				break;
			case SKSE::MessagingInterface::kDeleteGame:   // Player deleted a saved game from within the load menu.
				break;
		}
	})) {
		stl::report_and_fail("Failed to initialize message listener.");
	}

}

void InitPapyrus()
{
	logs::trace("Initializing papyrus bindings...");
	const auto intfc = SKSE::GetPapyrusInterface();
	if (!intfc->Register([](RE::BSScript::IVirtualMachine* /*a_vm*/) -> bool {
		// Register papyrus functions here, or change this lambda to a function
		return true;
	})) {
		stl::report_and_fail("Failed to initialize papyrus bindings.");
	}
}

void InitSerialization()
{
	logs::trace("Initializing cosave serialization...");
	// Setup serialization if needed
	// const auto intfc = SKSE::GetSerializationInterface();
	// intfc->SetUniqueID('0000');    // Unique ID
	// intfc->SetSaveCallback(...);   // Function called when saving the game
	// intfc->SetRevertCallback(...); // Function called when reverting state
	// intfc->SetLoadCallback(...);   // Function called when loading a save
}

SKSEPluginLoad(const SKSE::LoadInterface* a_skse)
{
	InitLogging();

	const auto plugin = SKSE::PluginDeclaration::GetSingleton();
	logs::info("{} v{} is loading...", plugin->GetName(), plugin->GetVersion());

	SKSE::Init(a_skse);
	InitMessaging();
	InitPapyrus();
	InitSerialization();

	logs::info("{} loaded.", plugin->GetName());

	return true;
}
