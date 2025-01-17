#pragma once
#include "pch.h"
#include "ViewMatrixHook.h"
#include "NvParameter.h"
#include "DebugOverlay.h"
#include "CFSR_logging.h"

class FeatureContext;

//Global Context
class CyberFsrContext
{
	CyberFsrContext();
public:
	std::shared_ptr<Config> MyConfig;

	VkDevice VulkanDevice;
	VkInstance VulkanInstance;
	VkPhysicalDevice VulkanPhysicalDevice;

	//std::vector<std::shared_ptr<Hyper_NGX::Parameter>> NvParameterInstances;
	Hyper_NGX_Parameter::ParameterFactory paramFactory;

	ankerl::unordered_dense::map <unsigned int, std::unique_ptr<FeatureContext>> Contexts;
	FeatureContext* CreateContext();
	void DeleteContext(NVSDK_NGX_Handle* handle);

	static std::shared_ptr<CyberFsrContext> instance()
	{
		static std::shared_ptr<CyberFsrContext> INSTANCE{std::make_shared<CyberFsrContext>(CyberFsrContext())};
		return INSTANCE;
	}
};

class FeatureContext
{
public:
	std::unique_ptr<ViewMatrixHook> ViewMatrix;
	NVSDK_NGX_Handle Handle{0};
	ID3D12Device* DxDevice;
	FfxFsr2Context FsrContext;
	FfxFsr2ContextDescription FsrContextDescription;
	std::vector<unsigned char> ScratchBuffer;

#ifdef CyberFSR_DO_OVERLAY1
	std::unique_ptr<DebugOverlay> DebugLayer;
#endif

	unsigned int Width{}, Height{}, RenderWidth{}, RenderHeight{};
	NVSDK_NGX_PerfQuality_Value PerfQualityValue = NVSDK_NGX_PerfQuality_Value_Balanced;
	float Sharpness = 1.0f;
	float MVScaleX{}, MVScaleY{};
	float JitterOffsetX{}, JitterOffsetY{};
};
