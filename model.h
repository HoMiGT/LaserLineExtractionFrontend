#pragma once

#include <atomic>
#include <QString>
#include <QTime>

enum StartActionColor {
	GRAY,  // 灰色
	GREEN, // 绿色
	RED  // 红色
};

enum TaskState {
	WAIT,  // 等待
	RUNING,  // 运行中
	SUCCESS,  // 成功
	FAIL,  // 失败
	DEFAULT,  // 未知
};

inline TaskState getTaskStateByChinese(QString& state) {
	if (state == "等待") {
		return TaskState::WAIT;
	}
	else if (state == "运行中") {
		return TaskState::RUNING;
	}
	else if (state == "成功") {
		return TaskState::SUCCESS;
	}
	else if (state == "失败") {
		return TaskState::FAIL;
	}
	else {
		return TaskState::DEFAULT;
	}
}

inline QString getChinesByTaskState(TaskState& state) {
	switch (state) {
	case TaskState::WAIT:
		return "等待";
	case TaskState::RUNING:
		return "进行中";
	case TaskState::SUCCESS:
		return "成功";
	case TaskState::FAIL:
		return "失败";
	default:
		return "未知";
	}
}

// 任务配置结构体
struct TaskInfo {
	QString configName; // 配置模板名称
	QString taskName;  // 任务名称
	QString extractImagePath; // 提取图片路径
	QString savedSeedPath;  // 保存种子路径
	QString failedImagePath;  // 失败图片路径
	TaskState status;  // 任务状态
	std::atomic<int> extractSuccessCount; // 提取成功数
	std::atomic<int> extractFailedCount; // 提取失败数
	double successRatio;  // 成功率
	bool isDingNotic;  // 是否钉钉通知
	QString dingDingUrl;  // 钉钉通知Url
	bool isUploadServer;  // 是否上传入服务
	QString pythonExePath;  // python 执行路径
	QString pythonScriptPath; // python 脚本路径
	QTime startTime; // 任务开始时间
	QTime endTime; // 任务结束时间
	double extractHeight; // 提取高
	double extractWidth; // 提取宽
	double extractX; // 二维码x坐标
	double extractY; // 二维码y坐标
	int qrSideLength; // 二维码边长
	double labelWidth;  // 二维码宽
	double labelHeight;  // 二维码高
    int blockNum;  // 粉块数量
};

// 任务运行结构体
struct TaskRunInfo {
	QString pythonExePath; // python解释器路径
	QString pythonScriptPath;  // python脚本执行路径
	QString extractPath;  // 提取路径
	QString saveSeedPath;  // 保存种子路径
	QString saveImagePath; // 保存失败图片路径
	QStringList extractImageName;  // 提取图片名称
	int qrSideLength; // 二维码边长
	double extractHeight; // 提取高
	double extractWidth; // 提取宽
};
