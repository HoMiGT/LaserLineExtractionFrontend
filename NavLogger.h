#pragma once
#include <memory>
#include <vector>
#include <string>
#include <filesystem>
#include <iostream>
#include <mutex>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/daily_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace NavLogger {
	static std::shared_ptr<spdlog::logger> initializeNavLogger() {
		try {
			std::filesystem::path log_dir("logs");
			std::filesystem::create_directories(log_dir);
			if (!std::filesystem::exists(log_dir)) {
				throw std::runtime_error("无法创建日志目录: " + log_dir.string());
			}

			auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_st>();
			console_sink->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%^%l%$] %v");

			auto file_sink = std::make_shared<spdlog::sinks::daily_file_format_sink_st>(
				"logs/desktop-%Y-%m-%d.log", 0, 0);
			file_sink->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%l] %v");

			auto logger = std::make_shared<spdlog::logger>(
				"advanced_logger",
				spdlog::sinks_init_list{ console_sink, file_sink }
			);
#ifdef _DEBUG
			logger->set_level(spdlog::level::debug);
#else
			logger->set_level(spdlog::level::info);
#endif
			logger->flush_on(spdlog::level::info);
			//spdlog::register_logger(logger);
			logger->info(">>>>>> 日志系统初始化完成 <<<<<<");
			return logger;
		}
		catch (const std::exception& ex) {
			std::cerr << "致命错误: " << ex.what() << std::endl;
			std::terminate();
		}
	}
} // namespace

static std::shared_ptr<spdlog::logger> NavLog() {
	static std::shared_ptr<spdlog::logger> logger = NavLogger::initializeNavLogger();
	return logger;
}

#define LOG_INFO(...)NavLog()->info(__VA_ARGS__)
#define LOG_WARN(...)NavLog()->warn(__VA_ARGS__)
#define LOG_ERROR(...)NavLog()->error(__VA_ARGS__)


